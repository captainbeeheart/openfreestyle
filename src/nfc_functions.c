#include "nfctable.h"
#include "freestylelibre_api.h"
#include "nfc_functions.h"


// Hello world from FreeStyle Libe NFC function

fram_data_t __attribute__ ((section (".framdata"))) fram_data;

#ifdef TEST_FUNC_A5
uint8_t __attribute__ ((section (".frampatch.data"))) helloWorld[] = "Hello from FreeStyle Libre";

// Demo function
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
#endif

// Update all CRC sections
void __attribute__ ((section (".frampatch"))) updateCRCs(void) 
{
    api_calc_crc16_t api_calc_crc16 = *(api_calc_crc16_t)(RAM_CALC_CRC16_ADDR);

    // Update data CRCs
    fram_data.header.crc16 = api_calc_crc16((short int *)&fram_data.header.unk0, (sizeof(fram_header_t)-2)/2);
    fram_data.data.crc16 = api_calc_crc16((short int *)&fram_data.data.short_term_idx, (sizeof(fram_tables_t)-2)/2);
    fram_data.footer.crc16 = api_calc_crc16((short int *)&fram_data.footer.unk1, (sizeof(fram_footer_t)-2)/2);
    fram_data.code.crc16 = api_calc_crc16((short int *)&fram_data.code.code_section, (sizeof(fram_code_t)-2)/2);
}

// The goal of this nfcRebirthFuncA6 function is to give a second life
// to a dead sensor so it can provides again temperature measurements
// for about 10 days, regarding to the remaining bettery life.
uint16_t __attribute__ ((section (".frampatch"))) nfcRebirthFuncA6(void) 
{
    api_memclr_t api_memclr = (api_memclr_t)ROM_MEM_CLR_ADDR;
    volatile uint8_t *pRF13MINT_H = RF13MINT_H;
    volatile uint8_t *pRF13MTXF_L = RF13MTXF_L;
    uint8_t *pclean;

    uint8_t interrupt_sav; 

    // Save and disable interrupt mask:
    interrupt_sav = *pRF13MINT_H;
    *pRF13MINT_H = 0;

    // Reset header section:
    api_memclr(&fram_data.header.warmupFlag, HEADER_TO_RESET_SZ);

    // Reset data section:
    api_memclr(&fram_data.data.short_term_idx, DATA_TO_RESET_SZ);

    // Reset footer section:
    // Disable the CRC verification
    fram_data.footer.bypassChecks = 0x6D;
    fram_data.header.state = NOT_STARTED;

    // Update all CRCs
    updateCRCs();

    // Restore interrupt mask:
    *pRF13MINT_H = interrupt_sav;

    // Return OK to RF
    *pRF13MTXF_L = 0; // No error
    *pRF13MTXF_L = 1; // data: OK flag 

    return 1;

}

// This function updates the sensor timelife in case the battery has been changed
// new battery seems to last for 24-25 days, so let's put 30 days.
uint16_t __attribute__ ((section (".frampatch"))) nfcIncreaseTimeFuncA7(void) 
{
    volatile uint8_t *pRF13MINT_H = RF13MINT_H;
    volatile uint8_t *pRF13MTXF_L = RF13MTXF_L;

    // Disable the CRC verification
    fram_data.footer.bypassChecks = 0x6D;

    // Set sensor maxtime to 30 days
    fram_data.footer.maxTime = (uint16_t)MIN2HRS*HRS2DAYS*30;

    // Update all CRCs
    updateCRCs();

    // Return OK to RF
    *pRF13MTXF_L = 0; // No error
    *pRF13MTXF_L = 1; // data: OK flag 

    return 1;
}