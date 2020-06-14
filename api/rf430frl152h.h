/* ============================================================================ */
/* Copyright (c) 2020, Texas Instruments Incorporated                           */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR PROFITS */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/* This file supports RF430FRL152H devices. */
/* Version: 1.209 */

typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int int16_t;
typedef unsigned short int uint16_t;


/************************************************************
* STANDARD BITS
************************************************************/
/************************************************************
* STATUS REGISTER BITS
************************************************************/
/************************************************************
* PERIPHERAL FILE MAP
************************************************************/
/************************************************************
* COMPACT CLOCK SYSTEM
************************************************************/
#define CCSCTL0           (short int*)0x0160
#define CCSCTL0_L         (char*)0x0160
#define CCSCTL0_H         (char*)0x0161
#define CCSCTL1           (short int*)0x0162
#define CCSCTL1_L         (char*)0x0162
#define CCSCTL1_H         (char*)0x0163
#define CCSCTL2           (short int*)0x0164
#define CCSCTL2_L         (char*)0x0164
#define CCSCTL2_H         (char*)0x0165
#define CCSCTL4           (short int*)0x0168
#define CCSCTL4_L         (char*)0x0168
#define CCSCTL4_H         (char*)0x0169
#define CCSCTL5           (short int*)0x016A
#define CCSCTL5_L         (char*)0x016A
#define CCSCTL5_H         (char*)0x016B
#define CCSCTL6           (short int*)0x016C
#define CCSCTL6_L         (char*)0x016C
#define CCSCTL6_H         (char*)0x016D
#define CCSCTL7           (short int*)0x016E
#define CCSCTL7_L         (char*)0x016E
#define CCSCTL7_H         (char*)0x016F
#define CCSCTL8           (short int*)0x0170
#define CCSCTL8_L         (char*)0x0170
#define CCSCTL8_H         (char*)0x0171
/*************************************************************
* CRC Module
*************************************************************/
#define CRCDI             (short int*)0x0150
#define CRCDI_L           (char*)0x0150
#define CRCDI_H           (char*)0x0151
#define CRCDIRB           (short int*)0x0152
#define CRCDIRB_L         (char*)0x0152
#define CRCDIRB_H         (char*)0x0153
#define CRCINIRES         (short int*)0x0154
#define CRCINIRES_L       (char*)0x0154
#define CRCINIRES_H       (char*)0x0155
#define CRCRESR           (short int*)0x0156
#define CRCRESR_L         (char*)0x0156
#define CRCRESR_H         (char*)0x0157
/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
#define PAIN              (short int*)0x0200
#define PAIN_L            (char*)0x0200
#define PAIN_H            (char*)0x0201
#define PAOUT             (short int*)0x0202
#define PAOUT_L           (char*)0x0202
#define PAOUT_H           (char*)0x0203
#define PADIR             (short int*)0x0204
#define PADIR_L           (char*)0x0204
#define PADIR_H           (char*)0x0205
#define PAREN             (short int*)0x0206
#define PAREN_L           (char*)0x0206
#define PAREN_H           (char*)0x0207
#define PADS              (short int*)0x0208
#define PADS_L            (char*)0x0208
#define PADS_H            (char*)0x0209
#define PASEL0            (short int*)0x020A
#define PASEL0_L          (char*)0x020A
#define PASEL0_H          (char*)0x020B
#define PASEL1            (short int*)0x020C
#define PASEL1_L          (char*)0x020C
#define PASEL1_H          (char*)0x020D
#define PAIES             (short int*)0x0218
#define PAIES_L           (char*)0x0218
#define PAIES_H           (char*)0x0219
#define PAIE              (short int*)0x021A
#define PAIE_L            (char*)0x021A
#define PAIE_H            (char*)0x021B
#define PAIFG             (short int*)0x021C
#define PAIFG_L           (char*)0x021C
#define PAIFG_H           (char*)0x021D
#define P1IV              (short int*)0x020E
#define P2IV              (short int*)0x021E
/************************************************************
* RF13M (13MHz NFC communication module
************************************************************/
#define RF13MCTL          (short int*)0x0800
#define RF13MCTL_L        (char*)0x0800
#define RF13MCTL_H        (char*)0x0801
#define RF13MINT          (short int*)0x0802
#define RF13MINT_L        (char*)0x0802
#define RF13MINT_H        (char*)0x0803
#define RF13MIV           (short int*)0x0804
#define RF13MIV_L         (char*)0x0804
#define RF13MIV_H         (char*)0x0805
#define RF13MRXF          (short int*)0x0806
#define RF13MRXF_L        (char*)0x0806
#define RF13MRXF_H        (char*)0x0807
#define RF13MTXF          (short int*)0x0808
#define RF13MTXF_L        (char*)0x0808
#define RF13MTXF_H        (char*)0x0809
#define RF13MCRC          (short int*)0x080A
#define RF13MCRC_L        (char*)0x080A
#define RF13MCRC_H        (char*)0x080B
#define RF13MFIFOFL       (short int*)0x080C
#define RF13MFIFOFL_L     (char*)0x080C
#define RF13MFIFOFL_H     (char*)0x080D
#define RF13MWMCFG        (short int*)0x080E
#define RF13MWMCFG_L      (char*)0x080E
#define RF13MWMCFG_H      (char*)0x080F
#define RF13MRXBUF        (short int*)0x0820
#define RF13MRXBUF_L      (char*)0x0820
#define RF13MRXBUF_H      (char*)0x0821
#define RF13MTXBUF        (short int*)0x0840
#define RF13MTXBUF_L      (char*)0x0840
#define RF13MTXBUF_H      (char*)0x0841
/************************************************************
* SD14 (14 Bit sigma delta ADC
************************************************************/
#define SD14CTL0          (short int*)0x0700
#define SD14CTL0_L        (char*)0x0700
#define SD14CTL0_H        (char*)0x0701
#define SD14CTL1          (short int*)0x0702
#define SD14CTL1_L        (char*)0x0702
#define SD14CTL1_H        (char*)0x0703
#define SD14MEM0          (short int*)0x0704
#define SD14MEM0_L        (char*)0x0704
#define SD14MEM0_H        (char*)0x0705
#define SD14MEM1          (short int*)0x0706
#define SD14MEM1_L        (char*)0x0706
#define SD14MEM1_H        (char*)0x0707
#define SD14MEM2          (short int*)0x0708
#define SD14MEM2_L        (char*)0x0708
#define SD14MEM2_H        (char*)0x0709
#define SD14MEM3          (short int*)0x070A
#define SD14MEM3_L        (char*)0x070A
#define SD14MEM3_H        (char*)0x070B
#define SD14IV            (short int*)0x070C
#define SD14IV_L          (char*)0x070C
#define SD14IV_H          (char*)0x070D
/************************************************************
* USCI B0
************************************************************/
#define UCB0CTLW0         (short int*)0x0640
#define UCB0CTLW0_L       (char*)0x0640
#define UCB0CTLW0_H       (char*)0x0641
#define UCB0CTLW1         (short int*)0x0642
#define UCB0CTLW1_L       (char*)0x0642
#define UCB0CTLW1_H       (char*)0x0643
#define UCB0BRW           (short int*)0x0646
#define UCB0BRW_L         (char*)0x0646
#define UCB0BRW_H         (char*)0x0647
#define UCB0STATW         (short int*)0x0648
#define UCB0STATW_L       (char*)0x0648
#define UCB0STATW_H       (char*)0x0649
#define UCB0TBCNT         (short int*)0x064A
#define UCB0TBCNT_L       (char*)0x064A
#define UCB0TBCNT_H       (char*)0x064B
#define UCB0RXBUF         (short int*)0x064C
#define UCB0RXBUF_L       (char*)0x064C
#define UCB0RXBUF_H       (char*)0x064D
#define UCB0TXBUF         (short int*)0x064E
#define UCB0TXBUF_L       (char*)0x064E
#define UCB0TXBUF_H       (char*)0x064F
#define UCB0I2COA0        (short int*)0x0654
#define UCB0I2COA0_L      (char*)0x0654
#define UCB0I2COA0_H      (char*)0x0655
#define UCB0I2COA1        (short int*)0x0656
#define UCB0I2COA1_L      (char*)0x0656
#define UCB0I2COA1_H      (char*)0x0657
#define UCB0I2COA2        (short int*)0x0658
#define UCB0I2COA2_L      (char*)0x0658
#define UCB0I2COA2_H      (char*)0x0659
#define UCB0I2COA3        (short int*)0x065A
#define UCB0I2COA3_L      (char*)0x065A
#define UCB0I2COA3_H      (char*)0x065B
#define UCB0ADDRX         (short int*)0x065C
#define UCB0ADDRX_L       (char*)0x065C
#define UCB0ADDRX_H       (char*)0x065D
#define UCB0ADDMASK       (short int*)0x065E
#define UCB0ADDMASK_L     (char*)0x065E
#define UCB0ADDMASK_H     (char*)0x065F
#define UCB0I2CSA         (short int*)0x0660
#define UCB0I2CSA_L       (char*)0x0660
#define UCB0I2CSA_H       (char*)0x0661
#define UCB0IE            (short int*)0x066A
#define UCB0IE_L          (char*)0x066A
#define UCB0IE_H          (char*)0x066B
#define UCB0IFG           (short int*)0x066C
#define UCB0IFG_L         (char*)0x066C
#define UCB0IFG_H         (char*)0x066D
#define UCB0IV            (short int*)0x066E
/************************************************************
* SFR - Special Function Register Module
************************************************************/
#define SFRIE1            (short int*)0x0100
#define SFRIE1_L          (char*)0x0100
#define SFRIE1_H          (char*)0x0101
#define SFRIFG1           (short int*)0x0102
#define SFRIFG1_L         (char*)0x0102
#define SFRIFG1_H         (char*)0x0103
#define SFRRPCR           (short int*)0x0104
#define SFRRPCR_L         (char*)0x0104
#define SFRRPCR_H         (char*)0x0105
/************************************************************
* COMPACT SYS - System Module
************************************************************/
#define SYSCTL            (short int*)0x0180
#define SYSCTL_L          (char*)0x0180
#define SYSCTL_H          (char*)0x0181
#define SYSJMBC           (short int*)0x0186
#define SYSJMBC_L         (char*)0x0186
#define SYSJMBC_H         (char*)0x0187
#define SYSJMBI0          (short int*)0x0188
#define SYSJMBI0_L        (char*)0x0188
#define SYSJMBI0_H        (char*)0x0189
#define SYSJMBI1          (short int*)0x018A
#define SYSJMBI1_L        (char*)0x018A
#define SYSJMBI1_H        (char*)0x018B
#define SYSJMBO0          (short int*)0x018C
#define SYSJMBO0_L        (char*)0x018C
#define SYSJMBO0_H        (char*)0x018D
#define SYSJMBO1          (short int*)0x018E
#define SYSJMBO1_L        (char*)0x018E
#define SYSJMBO1_H        (char*)0x018F
#define SYSCNF            (short int*)0x0190
#define SYSCNF_L          (char*)0x0190
#define SYSCNF_H          (char*)0x0191
#define SYSBERRIV         (short int*)0x0198
#define SYSBERRIV_L       (char*)0x0198
#define SYSBERRIV_H       (char*)0x0199
#define SYSUNIV           (short int*)0x019A
#define SYSUNIV_L         (char*)0x019A
#define SYSUNIV_H         (char*)0x019B
#define SYSSNIV           (short int*)0x019C
#define SYSSNIV_L         (char*)0x019C
#define SYSSNIV_H         (char*)0x019D
#define SYSRSTIV          (short int*)0x019E
#define SYSRSTIV_L        (char*)0x019E
#define SYSRSTIV_H        (char*)0x019F
/************************************************************
* PMM_RF - Power Management System of RF
************************************************************/
#define RFPMMCTL0         (short int*)0x0120
#define RFPMMCTL0_L       (char*)0x0120
#define RFPMMCTL0_H       (char*)0x0121
#define RFPMMCTL1         (short int*)0x0122
#define RFPMMCTL1_L       (char*)0x0122
#define RFPMMCTL1_H       (char*)0x0123
#define RFMMIE            (short int*)0x0124
#define RFMMIE_L          (char*)0x0124
#define RFMMIE_H          (char*)0x0125
#define RFPMMIFG          (short int*)0x0126
#define RFPMMIFG_L        (char*)0x0126
#define RFPMMIFG_H        (char*)0x0127
#define RFPMMIV           (short int*)0x0128
#define RFPMMIV_L         (char*)0x0128
#define RFPMMIV_H         (char*)0x0129
/************************************************************
* Timer0_A3
************************************************************/
#define TA0CTL            (short int*)0x0340
#define TA0CCTL0          (short int*)0x0342
#define TA0CCTL1          (short int*)0x0344
#define TA0CCTL2          (short int*)0x0346
#define TA0R              (short int*)0x0350
#define TA0CCR0           (short int*)0x0352
#define TA0CCR1           (short int*)0x0354
#define TA0CCR2           (short int*)0x0356
#define TA0IV             (short int*)0x036E
#define TA0EX0            (short int*)0x0360
/************************************************************
* WATCHDOG TIMER A
************************************************************/
#define WDTCTL            (short int*)0x015C
#define WDTCTL_L          (char*)0x015C
#define WDTCTL_H          (char*)0x015D
/************************************************************
* Interrupt Vectors (offset from 0xFFFF - 0x20
************************************************************/
/************************************************************
* End of Modules
************************************************************/
