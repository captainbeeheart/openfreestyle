#ifndef __PATCHTABLE_H__
#define __PATCHTABLE_H__

#include "rf430frl152h.h"

// Size of the RAM patch table to cover the full table.
// FreeStyle Libre total size is 61 descriptors = 244 bytes
// Only 3 used on curretn version, so reducong table to 
// 10 slots (44 bytes) to gain 204 bytes of possible code
// while keeping existing ROM patches.
#define MAX_PATCH 10

typedef struct patchfunc_T
{
    uint16_t index;
    uint16_t *pfunc;
}patchfunc_t;

struct patchtable_T
{
    patchfunc_t patchfuncTable[MAX_PATCH];
    uint16_t    numberOfPatches;
    uint16_t    endMark;
    uint16_t    padding[2];
};

void patch_cal(void);

#endif