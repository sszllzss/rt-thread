/*
 * @Descripttion: 
 * @version: v1.0
 * @Author: SSZL
 * @e-meil: sszllzss@foxmail.com
 * @Date: 2021-08-18 18:05:11
 * @LastEditors: SSZL
 * @LastEditTime: 2021-08-20 11:41:58
 */
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-04-29     tyustli      first version
 */

#include <rtdevice.h>
#include "drv_gpio.h"
#include "fsl_clock.h"
/* defined the LED pin: GPIO1_IO */
#define LED0_PIN               GET_PIN(1, 5)

int main(void)
{
    /* set LED0 pin mode to output */
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    
    rt_kprintf("CPU Freq:%d Semc:%d\n",CLOCK_GetFreq(kCLOCK_CpuClk),CLOCK_GetFreq(kCLOCK_SemcClk));
    rt_kprintf("SysPllClk:%d SysPllPfd0Clk:%d\n",CLOCK_GetFreq(kCLOCK_SysPllClk),CLOCK_GetFreq(kCLOCK_SysPllPfd0Clk));
    rt_kprintf("SysPllPfd1Clk:%d SysPllPfd2Clk:%d\n",CLOCK_GetFreq(kCLOCK_SysPllPfd1Clk),CLOCK_GetFreq(kCLOCK_SysPllPfd2Clk));
    rt_kprintf("SysPllPfd3Clk:%d Usb1PllClk:%d\n",CLOCK_GetFreq(kCLOCK_SysPllPfd3Clk),CLOCK_GetFreq(kCLOCK_Usb1PllClk));
    rt_kprintf("Usb1PllPfd0Clk:%d Usb1PllPfd1Clk:%d\n",CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk),CLOCK_GetFreq(kCLOCK_Usb1PllPfd1Clk));
    rt_kprintf("Usb1PllPfd2Clk:%d Usb1PllPfd3Clk:%d\n",CLOCK_GetFreq(kCLOCK_Usb1PllPfd2Clk),CLOCK_GetFreq(kCLOCK_Usb1PllPfd3Clk));
    rt_kprintf("kCLOCK_SemcAltMux:%d\n",CLOCK_GetMux(kCLOCK_SemcAltMux));
    rt_kprintf("kCLOCK_SemcMux:%d\n",CLOCK_GetMux(kCLOCK_SemcMux));
    rt_kprintf("kCLOCK_FlexspiMux:%d\n",CLOCK_GetMux(kCLOCK_FlexspiMux));

    rt_kprintf("kCLOCK_SemcDiv:%d\n",CLOCK_GetDiv(kCLOCK_SemcDiv));
    rt_kprintf("kCLOCK_FlexspiDiv: %d\n",CLOCK_GetDiv(kCLOCK_FlexspiDiv));
    while (1)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED0_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }
}

