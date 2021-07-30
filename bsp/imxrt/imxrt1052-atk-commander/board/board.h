/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-09-22     Bernard      add board.h to this bsp
 */

// <<< Use Configuration Wizard in Context Menu >>>
#ifndef __BOARD_H__
#define __BOARD_H__

#include "fsl_common.h"
#include "clock_config.h"

#ifdef __CC_ARM
extern int Image$$RTT_HEAP$$ZI$$Base;
extern int Image$$RTT_HEAP$$ZI$$Limit;
#define HEAP_BEGIN          (&Image$$RTT_HEAP$$ZI$$Base)
#define HEAP_END            (&Image$$RTT_HEAP$$ZI$$Limit)

#elif __ICCARM__
#pragma section="HEAP"
#define HEAP_BEGIN          (__segment_end("HEAP"))
extern void __RTT_HEAP_END;
#define HEAP_END            (&__RTT_HEAP_END)

#else
extern int heap_start;
extern int heap_end;
#define HEAP_BEGIN          (&heap_start)
#define HEAP_END            (&heap_end)
#endif

#define HEAP_SIZE           ((uint32_t)HEAP_END - (uint32_t)HEAP_BEGIN)

void rt_hw_board_init(void);



#if defined(__CC_ARM) || defined(__CLANG_ARM)           /* ARM Compiler */
    #define RT_SECTION(x)               __attribute__((section(x)))
#elif defined (__IAR_SYSTEMS_ICC__)     /* for IAR Compiler */
    #define RT_SECTION(x)               @ x
#elif defined (__GNUC__)                /* GNU GCC Compiler */
    #define RT_SECTION(x)               __attribute__((section(x)))
#elif defined (__ADSPBLACKFIN__)        /* for VisualDSP++ Compiler */
    #define RT_SECTION(x)               __attribute__((section(x)))
#elif defined (_MSC_VER)
    #define RT_SECTION(x)
#elif defined (__TI_COMPILER_VERSION__)
    #define RT_SECTION(x)
#elif defined (__TASKING__)
    #define RT_SECTION(x)               __attribute__((section(x)))
#else
    #error not supported tool chain
#endif


#endif

