#include "nfctable.h"
#include "freestylelibre_api.h"
#include "nfc_functions.h"


// Hello world from FreeStyle Libe NFC function

uint8_t __attribute__ ((section (".frampatch.data"))) helloWorld[] = "Hello from FreeStyle Libre";


uint16_t __attribute__ ((section (".frampatch"))) nfcTestFuncA5(void) 
{
    volatile uint8_t *pRF13MTXF_L = RF13MTXF_L;
    volatile uint16_t *pRF13MTXF = RF13MTXF;
    api_check_rf_header_t api_check_rf_header = (api_check_rf_header_t)RAM_CHECK_RFHEADER_OK_ADDR;
    api_check_section_crc16_t api_check_section_crc16 = (api_check_section_crc16_t)RAM_CHECK_SECTION_CRC16_ADDR;
    api_calc_crc16_t api_calc_crc16 = *(api_calc_crc16_t)(RAM_CALC_CRC16_ADDR);
    uint16_t code_crc;
    uint8_t sec0_crc, sec1_crc;


    // Check rf header is correct:
    if(api_check_rf_header())
    {
        // Compute Code section CRC and return the value
        code_crc = api_calc_crc16((short int *)0xF9BA, 779);

        // Check CRC of header section and data section are ok and return True/False flag
        sec0_crc = (uint8_t)api_check_section_crc16(0);
        sec1_crc = (uint8_t)api_check_section_crc16(1);

        // Copy string to RFTx frame
        *pRF13MTXF_L = 0; 
        for(uint16_t k=0; k < 26; k++)
        {            
            *pRF13MTXF_L = helloWorld[k];
        }

        // Return CRCs
        *pRF13MTXF = code_crc;
        *pRF13MTXF_L = sec0_crc;
        *pRF13MTXF_L = sec1_crc;

        // Return OK
        return 1;
    }

    // Decoding magic error
    return 0;
}