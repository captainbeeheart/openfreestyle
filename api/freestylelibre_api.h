/* This file defines known ROM or RAM function pointer API functions and their prototype */

#ifndef __FREESTYLELIBRE_API__
#define __FREESTYLELIBRE_API__

#include "rf430frl152h.h"

/* RAM functions pointers to ROM table              */
/* Should be used prior to ROM functions            */
/* this table can be patched by FRAM functions to   */
/* fix ROM issues                                   */
#define RAM_CHECK_RFHEADER_OK_ADDR              *((short int*)0x1C20)
#define RAM_UNK_FUNC_1C22_ADDR                  *((short int*)0x1C22)
#define RAM_UNK_FUNC_1C24_ADDR                  *((short int*)0x1C24)
#define RAM_UNK_FUNC_1C26_ADDR                  *((short int*)0x1C26)
#define RAM_CFG_CLOCK_ADDR                      *((short int*)0x1C28)
#define RAM_CHECK_SECTION_CRC16_ADDR            *((short int*)0x1C2A)
#define RAM_CHK_FRAM_WR_ACCESS_LOCK_ADDR        *((short int*)0x1C2C)
#define RAM_UNK_FUNC_1C2E_ADDR                  *((short int*)0x1C2E)
#define RAM_CALC_CRC16_ADDR                     *((short int*)0x1C30)
#define pROM_CHK_CRC16_ADDR                     *((short int*)0x1C32)
#define RAM_UNK_FUNC_4582_ADDR                  *((short int*)0x1C34)
#define RAM_NFC_CUSTOM_A0_ADDR                  *((short int*)0x1C36)
#define RAM_NFC_CUSTOM_A2_LOCK_FRAM_WR_ADDR     *((short int*)0x1C38)
#define RAM_UNK_FUNC_1C3A_ADDR                  *((short int*)0x1C3A)
#define RAM_UNK_FUNC_1C3C_ADDR                  *((short int*)0x1C3C)
#define RAM_UNK_FUNC_1C3E_ADDR                  *((short int*)0x1C3E)
#define RAM_UNK_FUNC_1C40_ADDR                  *((short int*)0x1C40)
#define RAM_SENSOR_STATE_AND_ADC_UPDATE_ADDR    *((short int*)0x1C42)
#define RAM_UNK_FUNC_1C44_ADDR                  *((short int*)0x1C44)
#define RAM_UNK_FUNC_1C46_ADDR                  *((short int*)0x1C46)
#define RAM_UNK_FUNC_1C48_ADDR                  *((short int*)0x1C48)
#define RAM_UNK_FUNC_1C4A_ADDR                  *((short int*)0x1C4A)
#define RAM_SOME_ARITHMETIC_ADDR                *((short int*)0x1C4C)
#define RAM_UNK_FUNC_1C4E_ADDR                  *((short int*)0x1C4E)
#define RAM_UNK_FUNC_1C50_ADDR                  *((short int*)0x1C50)
#define RAM_UNK_FUNC_1C52_PATCHED_ADDR          *((short int*)0x1C52)
#define RAM_UNK_FUNC_1C54_ADDR                  *((short int*)0x1C54)
#define RAM_UNK_FUNC_1C56_ADDR                  *((short int*)0x1C56)
#define RAM_UNK_FUNC_1C58_ADDR                  *((short int*)0x1C58)
#define RAM_WARMUP_INIT_ADDR                    *((short int*)0x1C5A)
#define RAM_UPDATE_TIMER_CNTR_ADDR              *((short int*)0x1C5C)
#define RAM_UNK_FUNC_1C5E_ADDR                  *((short int*)0x1C5E)
#define RAM_RECORD_SENSOR_LIFE_STATE_ADDR       *((short int*)0x1C60)
#define RAM_UNK_FUNC_1C62_ADDR                  *((short int*)0x1C62)
#define RAM_MAIN_THREAD_OPERATION_ADDR          *((short int*)0x1C64)
#define RAM_UNK_FUNC_1C66_ADDR                  *((short int*)0x1C66)
#define RAM_UNK_FUNC_1C68_ADDR                  *((short int*)0x1C68)
#define RAM_UNK_FUNC_1C6A_PATCHED_ADDR          *((short int*)0x1C6A)
#define RAM_CHK_FRAM_CODE_AND_FOOTER_CRC        *((short int*)0x1C6C)
#define RAM_UNK_FUNC_1C6E_ADDR                  *((short int*)0x1C6E)
#define RAM_UPDATE_MEASURE_ADDR                 *((short int*)0x1C70)
#define RAM_INIT_FRAM_SECTIONS_ADDR             *((short int*)0x1C72)
#define RAM_POWERMANAGEMENT_INT_CTRL_ADDR       *((short int*)0x1C74)
#define RAM_UNK_FUNC_1C76_ADDR                  *((short int*)0x1C76)
#define RAM_SET_SIGMADELTA_ADC_ADDR             *((short int*)0x1C78)
#define RAM_UNK_FUNC_1C7A_ADDR                  *((short int*)0x1C7A)
#define RAM_UNK_FUNC_1C7C_ADDR                  *((short int*)0x1C7C)
#define RAM_UNK_FUNC_1C7E_ADDR                  *((short int*)0x1C7E)
#define RAM_SIGMADELTA_ADC_STUFF_ADDR           *((short int*)0x1C80)
#define RAM_SET_SIGMADELTA_ADC_CTRL_ADDR        *((short int*)0x1C82)
#define RAM_DIVIDE_TBC_ADDR                     *((short int*)0x1C84)
#define RAM_CALC_BLOCK_CRC16_ADDR               *((short int*)0x1C86)
#define RAM_UPDATE_SENSOR_STATE_ADDR            *((short int*)0x1C88)
#define RAM_UNK_FUNC_1C8A                       *((short int*)0x1C8A)
#define RAM_SWITCH_SENSOR_IN_ERROR_ADDR         *((short int*)0x1C8C)
#define RAM_SET_TA0_REGISTERS_ADDR              *((short int*)0x1C8E)
#define RAM_CHK_TIMER_TBC_ADDR                  *((short int*)0x1C90)
#define RAM_SET_MEASURE_TIME_ADDR               *((short int*)0x1C92)
#define RAM_DISABLE_BATT_SWITCH_ADDR            *((short int*)0x1C94)
#define RAM_ENABLE_BATT_SWITCH_ADDR             *((short int*)0x1C96)
#define RAM_START_SENSOT_OPERATION_ADDR         *((short int*)0x1C98)
#define RAM_SET_POWER_ON_RESET_BIT_ADDR         *((short int*)0x1C9A)
#define RAM_INC_TIME_COUNTER_ADDR               *((short int*)0x1C9C)
#define RAM_RESET_WATCHDOG_ADDR                 *((short int*)0x1C9E)
#define RAM_COMPUTE_RAW_TABLE_VALUE_ADDR        *((short int*)0x1CA0)

/* ROM functions*/
#define ROM_MEM_CPY_ADDR                        ((short int*)0x5F78)
#define ROM_MEM_CLR_ADDR                        ((short int*)0x5F54)
#define ROM_MPY_2N_ADDR                         ((short int*)0x5FD0)
#define ROM_DIV_2N_ADDR                         ((short int*)0x5F8C)
#define ROM_GET_FRAM_ADDR_FROM_BLOCK_NBR        ((short int*)0x4EDA)

#define ROM_NFC_CUSTOM_A0_ADDR                  ((short int*)0x5724)
#define ROM_NFC_CUSTOM_A2_LOCK_FRAM_WR_ADDR     ((short int*)0x5A56)
#define ROM_NFC_CUSTOM_A4_UNLOCK_FRAME_WR_ADDR  ((short int*)0x5A2C)

/* FRAM functions*/
#define FRAM_NFC_CUSTOM_A3_MEMORYDUMP_ADDR      ((short int*)0xFBCA)
#define FRAM_NFC_CUSTOM_A1_GETTIMERVAL_ADDR     ((short int*)0xF9BA)
#define FRAM_NFC_CUSTOM_E0_ADDR                 ((short int*)0xFBAE)
#define FRAM_NFC_CUSTOM_E1_ADDR                 ((short int*)0xFA3C)
#define FRAM_NFC_CUSTOM_E2_ADDR                 ((short int*)0xFB4A)


/* Functions prototypes */
/*=======================*/

/* check_section_crc16                        */
/* input: sectionId 0 for header, 1 for data  */
/* return 0=Ok / 0x0D or 0x0C Error           */
typedef  uint16_t (*api_check_section_crc16_t)(uint16_t sectionId);


/* Compute CRC16                */
/* input: pdata                 */
/* input: length in words       */
/* return crc16                 */
typedef  uint16_t (*api_calc_crc16_t)(uint16_t *pdata, uint16_t length);


/* Divide by 2^n                */
/* input: data                  */
/* input: division factor (n)   */
/* return data >> n             */
typedef uint16_t (*api_div_2n_t)(uint16_t data, uint16_t factor);


/* Multiply by 2^n              */
/* input: data                  */
/* input: mpy factor (n)        */
/* return data << n             */
typedef uint16_t (*api_mpy_2n_t)(uint16_t data, uint16_t factor);


/* Check RF header              */
/* Check RF header manufacturer */
/* ID and magic are ok          */
/* Waited bytes:                */
/* <0x07,0xC2>,0xAD,0x75,0x21   */
/* Return 1 if ok, or 0         */
typedef  uint16_t (*api_check_rf_header_t)(void);


/* Return FRAM address from     */
/* block number                 */
/* input: block number          */
/* return 16 bits address       */
typedef uint16_t (*api_get_fram_addr_from_block_nbr_t)(uint16_t block_offset);




#endif




