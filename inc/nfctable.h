#ifndef __NFCTABLE_H__
#define __NFCTABLE_H__

#include "rf430frl152h.h"

#define MAX_NFC_FUNCS 11
#define NFC_MARKER 0xABAB

typedef struct nfcfunc_T
{
    uint16_t *pfunc;
    uint16_t functionCode;
}nfcfunc_t;

struct nfctable_T
{
    uint16_t  topMarker;
    nfcfunc_t patchfuncTable[MAX_NFC_FUNCS];
    uint16_t  bottomMarker;
};



#endif