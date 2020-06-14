#include "patchtable.h"

__attribute__ ((section (".frampatchtable")))
struct patchtable_T patchTable =
{
   {{0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0, 0},                         // Free patch slot
    {0xFFFF, (uint16_t*)0xFD84},    // Table bottom Points to a ret_func code
    {0x0025, (uint16_t*)0xFC9A},    // Patch ram table function 0x25 by FRAM code
    {0x0014, (uint16_t*)0xFC50}},   // Patch ram table function 0x14 by FRAM code
    3,                              // Number of effective patches + 1 
    0xF55,                          // Start of table marker
    {0, 0}                          // Padding
};