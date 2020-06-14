#include "nfctable.h"
#include "freestylelibre_api.h"
#include "nfc_functions.h"

__attribute__ ((section (".framnfctable")))
struct nfctable_T nfcTable =
{
    NFC_MARKER,                     // Top marker
   {{0, 0},
    {0, NFC_MARKER},                                // Stop table parsing as no other functions
    {(uint16_t *)nfcTestFuncA5, 0xA5},              // Add custom function accessible through NFC
    {FRAM_NFC_CUSTOM_E2_ADDR, 0xE2},
    {FRAM_NFC_CUSTOM_E1_ADDR, 0xE1},
    {FRAM_NFC_CUSTOM_E0_ADDR, 0xE0},                // Re-enable E0 to E2 functions access
    {ROM_NFC_CUSTOM_A4_UNLOCK_FRAME_WR_ADDR, 0xA4},
    {FRAM_NFC_CUSTOM_A3_MEMORYDUMP_ADDR, 0xA3},
    {ROM_NFC_CUSTOM_A2_LOCK_FRAM_WR_ADDR, 0xA2},
    {FRAM_NFC_CUSTOM_A1_GETTIMERVAL_ADDR, 0xA1},
    {ROM_NFC_CUSTOM_A0_ADDR, 0xA0}},
    NFC_MARKER,                     // Bottom marker 
};