# This file extracts usefull bytes from the elf file and 
# merge it to existing FRAM dump file to download the code
# properly using nfc block write functions
#  1- Send a command to the sensor to make FRAM writable (A4 command)
#  2- Merge and Compute resulting checksum for code section
#  3- Download code to sensor
#
# Use pypn5180 for NFC control.


from pypn5180.iso_iec_15693 import iso_iec_15693
import binascii
import os
import argparse
import progressbar
import sys


crc16table = [0, 4489, 8978, 12955, 17956, 22445, 25910, 29887, 35912, 40385,
  44890, 48851, 51820, 56293, 59774, 63735, 4225, 264, 13203, 8730,
  22181, 18220, 30135, 25662, 40137, 36160, 49115, 44626, 56045, 52068,
  63999, 59510, 8450, 12427, 528, 5017, 26406, 30383, 17460, 21949,
  44362, 48323, 36440, 40913, 60270, 64231, 51324, 55797, 12675, 8202,
  4753, 792, 30631, 26158, 21685, 17724, 48587, 44098, 40665, 36688,
  64495, 60006, 55549, 51572, 16900, 21389, 24854, 28831, 1056, 5545,
  10034, 14011, 52812, 57285, 60766, 64727, 34920, 39393, 43898, 47859,
  21125, 17164, 29079, 24606, 5281, 1320, 14259, 9786, 57037, 53060,
  64991, 60502, 39145, 35168, 48123, 43634, 25350, 29327, 16404, 20893,
  9506, 13483, 1584, 6073, 61262, 65223, 52316, 56789, 43370, 47331,
  35448, 39921, 29575, 25102, 20629, 16668, 13731, 9258, 5809, 1848,
  65487, 60998, 56541, 52564, 47595, 43106, 39673, 35696, 33800, 38273,
  42778, 46739, 49708, 54181, 57662, 61623, 2112, 6601, 11090, 15067,
  20068, 24557, 28022, 31999, 38025, 34048, 47003, 42514, 53933, 49956,
  61887, 57398, 6337, 2376, 15315, 10842, 24293, 20332, 32247, 27774,
  42250, 46211, 34328, 38801, 58158, 62119, 49212, 53685, 10562, 14539,
  2640, 7129, 28518, 32495, 19572, 24061, 46475, 41986, 38553, 34576,
  62383, 57894, 53437, 49460, 14787, 10314, 6865, 2904, 32743, 28270,
  23797, 19836, 50700, 55173, 58654, 62615, 32808, 37281, 41786, 45747,
  19012, 23501, 26966, 30943, 3168, 7657, 12146, 16123, 54925, 50948,
  62879, 58390, 37033, 33056, 46011, 41522, 23237, 19276, 31191, 26718,
  7393, 3432, 16371, 11898, 59150, 63111, 50204, 54677, 41258, 45219,
  33336, 37809, 27462, 31439, 18516, 23005, 11618, 15595, 3696, 8185,
  63375, 58886, 54429, 50452, 45483, 40994, 37561, 33584, 31687, 27214,
  22741, 18780, 15843, 11370, 7921, 3960]



def computeCRC16(data, datalen):
  
    crc = 0xffff
    for i in range(datalen):
        crc = ((crc >> 8) ^ crc16table[(crc ^ data[i]) & 0xff])&0xffff
  
    reverseCrc = 0
    for i in range(16):
        reverseCrc = ((reverseCrc << 1) | ((crc & 1)&0xFFFF))&0xFFFF
        crc = crc >> 1

    return reverseCrc


class nfc():

    MAGIC = "C2AD7521"

    def __init__(self, ftdi_port):
        self.isoIec15693 = iso_iec_15693(ftdi_port)
        self.pb = None

    def ctrl_fram(self, code):
        data, errStr  = self.isoIec15693.customCommand(code, 0x07, list(binascii.unhexlify(self.MAGIC)))
        if "No Answer from tag" not in errStr: 
            print("CMD %x: [%s] Data: [%r] - [%s]" %(code, errStr, data, binascii.hexlify(data)))
        else:
            print("%s" %errStr)

    def unlock_fram(self):
        self.ctrl_fram(0xA4)

    def lock_fram(self):
        self.ctrl_fram(0xA2)

    def updatepb(self, current_block, max_block):
        k = int(100*current_block/max_block)
        self.pb.update(k)


    def dump_fram(self, file):
        with open(file, 'wb') as fd:
            print("Dumping FRAM, Do not remove sensor...")
            self.pb = progressbar.ProgressBar().start()
            for k in range(244):
                data, errStr = self.isoIec15693.readSingleBlockCmd(int(k))
                self.updatepb(k, 243)
                if 'OK' in errStr:
                    hexdata = bytes(data)
                    fd.write(hexdata)
                else:
                    print("ERROR in FRAM read")
                    return 1
            self.pb.finish()
            self.pb = None
            return 0


    def upload_blob(self, blob):
        nb_blocks = int(len(blob)/8)
        print("Uploading new FRAM code, Do not remove sensor...")
        self.pb = progressbar.ProgressBar().start()
        for k in range(nb_blocks):
            self.write_block(k, blob[k*8:(k*8)+8])
            self.updatepb(k, nb_blocks)
        self.pb.finish()
        self.pb = None
        print("Upload done")


    def write_block(self, block_offset, data):
        data, errStr = self.isoIec15693.writeSingleBlockCmd(block_offset, data)
        if errStr != "Transaction OK":
            print("Write Block N°%d: %s" %(block_offset, errStr))


"""
WARNING! Assumtion is that:
 - FRAMNFCTABLE section ends on a RF block boundary (0xFFD0 corresponds to block #238)
   So no check is done on section end.
 - FRAMLEGACYCODE section starts on a block boundary.
 - Assuming that sections frampatch, frampatchtable and framnfctable addresses are contiguous.
 - frampatchtable and framnfctable senctions are filled.
"""
class binary_blob():
    
    FRAM_BASE = 0xF860

    def __init__(self, elf_file, dump_file, linker_file, out):
        self.elf_file = elf_file
        self.dump_file = dump_file
        self.linker_file = linker_file
        self.out = out
        self.has_legacy_code = False

        self.read_binary(self.elf_file)
        self.read_linkerfile(self.linker_file)
        self.read_full_dump(self.dump_file)
        self.build_full_dump(self.out)

        self.frampatch_start_address = 0
        self.frampatch_length = 0
        self.start_offset = 0
        self.is_block_boundary = True
        self.start_block = 0
        self.framcrc_start_address = 0
        self.framcrc_length = 0
        self.crc_offset = 0
        self.framlegacy_address = 0
        self.framlegacy_length = 0
        self.framlegacy_offset = 0
        self.frampatchtable_address = 0
        self.frampatchtable_length = 0
        self.frampatchtable_offset = 0
        self.framfctable_address = 0
        self.framfctable_length = 0
        self.framfctable_offset = 0


    def extract_section(self, section, file):
        os.system("msp430-elf-objcopy -O binary --only-section .%s ../build/%s /tmp/%s.%s" %(section,file,file,section))
        with open("/tmp/%s.%s" %(file,section),'rb') as fh:
            blob = fh.read()        
        return blob


    def read_binary(self, file):
        self.blob_frampatch = self.extract_section("frampatch", file)
        self.blob_frampatchtable = self.extract_section("frampatchtable", file)
        self.blob_framnfctable = self.extract_section("framnfctable", file)


    def get_binary(self):
        return self.full_dump


    def read_full_dump(self, file):
        with open(file,'rb') as fh:
            self.fram_dump = fh.read()        


    def read_linkerfile(self, file):
        with open(file,'r') as fh:
            linkerfile = fh.readlines()        
        for line in linkerfile:
            if "FRAMPATCHCODE" in line:
                if "ORIGIN" in line:
                    self.frampatch_start_address = int(line.split("= ")[1].split(", ")[0],16)
                    self.frampatch_length = int(line.split("LENGTH = ")[1].split(" ")[0],16)
                    self.start_offset = self.frampatch_start_address - self.FRAM_BASE
                    self.is_block_boundary = (self.frampatch_start_address / 8).is_integer()
                    self.start_block = int((self.start_offset)/8)

            if "FRAMPATCHCODECRC" in line:
                if "ORIGIN" in line:
                    self.framcrc_start_address = int(line.split("= ")[1].split(", ")[0],16)
                    self.framcrc_length = int(line.split("LENGTH = ")[1].split(" ")[0],16)
                    self.crc_offset = self.framcrc_start_address - self.FRAM_BASE

            if "FRAMLEGACYCODE" in line:
                if "ORIGIN" in line:
                    self.has_legacy_code = True
                    self.framlegacy_address = int(line.split("= ")[1].split(", ")[0],16)
                    self.framlegacy_length = int(line.split("LENGTH = ")[1].split(" ")[0],16)
                    self.framlegacy_offset = self.framlegacy_address - self.FRAM_BASE

            if "FRAMPATCHTABLE" in line:
                if "ORIGIN" in line:
                    self.frampatchtable_address = int(line.split("= ")[1].split(", ")[0],16)
                    self.frampatchtable_length = int(line.split("LENGTH = ")[1].split(" ")[0],16)
                    self.frampatchtable_offset = self.frampatchtable_address - self.FRAM_BASE

            if "FRAMNFCTABLE" in line:
                if "ORIGIN" in line:
                    self.framfctable_address = int(line.split("= ")[1].split(", ")[0],16)
                    self.framfctable_length = int(line.split("LENGTH = ")[1].split(" ")[0],16)
                    self.framfctable_offset = self.framfctable_address - self.FRAM_BASE


    def build_full_dump(self, out):
        #  Merge sensor FRAM dump and new code
        self.full_dump = bytearray(self.fram_dump)

        # Add zero patting to patch code section if required
        if len(self.blob_frampatch) != self.frampatch_length:
            self.blob_frampatch = self.blob_frampatch + b'\x00'*(self.frampatch_length-len(self.blob_frampatch))

        blob = self.blob_frampatch + self.blob_frampatchtable + self.blob_framnfctable

        for k in range(self.start_offset, self.start_offset+len(blob)):
            self.full_dump[k] = blob[k-self.start_offset]

        # Update Code section CRC:
        crc_len =  self.frampatch_length + self.frampatchtable_length + self.framfctable_length
        if self.has_legacy_code is True:
            crc_len += self.framlegacy_length
            crc = computeCRC16(self.full_dump[self.framlegacy_offset:], crc_len)
            print("New code section CRC16 (@ 0x%0.4x - %d)= 0x%0.4x" %(self.framlegacy_offset, crc_len, crc))
        else:
            crc = computeCRC16(self.full_dump[self.start_offset:], crc_len)
            print("New code section CRC16 (@ 0x%0.4x - %d)= 0x%0.4x" %(self.start_offset, crc_len, crc))

        self.full_dump[self.crc_offset ] = (crc >> 8)&0xFF
        self.full_dump[self.crc_offset +1] = (crc )&0xFF

        with open(out, "wb") as fd:
            fd.write(self.full_dump)



def parseInputs():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--elf", type=str, default="out.elf", help="input elf file")
    parser.add_argument("-d", "--dump", type=str, default="fram_dump.bin", help="output current sensor FRAM dump file")
    parser.add_argument("-o", "--out", type=str, default="fram_out.bin", help="output new FRAM file")
    parser.add_argument("-l", "--linkerscript", type=str, default="rf430frl152h_freestylelibre.ld", help="Input, Linker script file")
    parser.add_argument("-f", "--ftdi_port", type=str, default="PORT_A", help="FTDI 2232 port 'PORT_A, PORT_B'")
    return parser.parse_args()

if __name__ == "__main__":
    args = parseInputs()

    # Get a full FRAM dump of the sensor
    sensor = nfc(args.ftdi_port)
    if sensor.dump_fram(args.dump):
        sys.exit(0)

    # Compute bew FRAM 
    datablob = binary_blob(args.elf, args.dump, args.linkerscript, args.out)
    outdata = datablob.get_binary()

    # Update FRAM
    sensor.unlock_fram()
    sensor.upload_blob(outdata)
    sensor.lock_fram()

