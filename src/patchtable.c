#include "patchtable.h"
#include "freestylelibre_api.h"

#define NUMBER_OF_PATCHES 3
#define TABLE_CHECKSUM  (uint16_t)(NUMBER_OF_PATCHES + 0x0019+ 0xFC20+ 0x0014 + 0xFC50 + 0x0025 + 0xFC9A /*+ 0x001D + (uint16_t)patch_cal*/)

__attribute__ ((section (".frampatchtable")))
struct patchtable_T patchTable =
{
   {{0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0xFFFF, (uint16_t*)0xFD84},    // Table bottom Points to a ret_func code
    // {0x001D, (uint16_t*)patch_cal}, // Patch to bypass calibration function
    {0x0025, (uint16_t*)0xFC9A},    // Patch ram table function 0x25 by FRAM code
    {0x0014, (uint16_t*)0xFC50},    // Patch ram table function 0x14 by FRAM code
    {0x0019, (uint16_t*)0xFC20}},   // Patch ram table function 0x19 by FRAM code
    NUMBER_OF_PATCHES,              // Number of effective patches
    TABLE_CHECKSUM,                 // Table checksum
    {0, 0}                          // Padding
};



/* Patch calibration function to switch directly in READY mode*/
void __attribute__ ((section (".frampatch"))) patch_cal(void)
{
    api_update_sensor_state_t api_update_sensor_state = *(api_update_sensor_state_t)(RAM_UPDATE_SENSOR_STATE_ADDR);

    api_update_sensor_state(READY_WORKING);

}