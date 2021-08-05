/*
 * @Descripttion: 
 * @version: v1.0
 * @Author: SSZL
 * @e-meil: sszllzss@foxmail.com
 * @Date: 2021-07-30 13:15:17
 * @LastEditors: SSZL
 * @LastEditTime: 2021-08-05 10:33:39
 */
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-05     zylx         The first version for STM32F4xx
 * 2019-4-25      misonyo      port to IMXRT
 */

#ifndef SDRAM_PORT_H__
#define SDRAM_PORT_H__


/* parameters for sdram peripheral */
#define SDRAM_BANK_ADDR                 ((uint32_t)0x80000000U) //基地址
/* region#0/1/2/3: kSEMC_SDRAM_CS0/1/2/3 */
#define SDRAM_REGION                    kSEMC_SDRAM_CS0   //区域选择
/* CS pin: kSEMC_MUXCSX0/1/2/3 */
#define SDRAM_CS_PIN                    kSEMC_MUXCSX0 //CS 引脚选择
/* size(kbyte):32MB = 32*1024*1KBytes */
#define SDRAM_SIZE                      ((uint32_t)0x8000) //存储器大小，单位为 kbytes
/* data width: kSEMC_PortSize8Bit,kSEMC_PortSize16Bit */
#define SDRAM_DATA_WIDTH                kSEMC_PortSize16Bit //Port 的大小 数据宽
/* column bit numbers: kSEMC_SdramColunm_9/10/11/12bit */
#define SDRAM_COLUMN_BITS               kSEMC_SdramColunm_9bit //列地址位宽
/* cas latency clock number: kSEMC_LatencyOne/Two/Three */
#define SDRAM_CAS_LATENCY               kSEMC_LatencyThree //CAS 延迟

/* Timing configuration for W9825G6KH-6 */
/* TRP:precharge to active command time (ns) */
#define SDRAM_TRP                       20 //预充电（Precharge）至有效（active）的等待时间，单位为纳秒
/* TRCD:active to read/write command delay time (ns) */
#define SDRAM_TRCD                      20 //Act 至读/写操作的等待时间，单位为纳秒
/* The time between two refresh commands,Use the maximum of the (Trfc , Txsr).(ns) */
#define SDRAM_REFRESH_RECOVERY          67  //刷新恢复（Refresh recovery）时间，单位为纳秒
/* TWR:write recovery time (ns). */
#define SDRAM_TWR                       20//写恢复（write recovery）时间，单位为纳秒
/* TRAS:active to precharge command time (ns). */
#define SDRAM_TRAS       50 //有效（Active）至预充电（precharge）时间 ，单位为纳秒
/* TRC time (ns). */
#define SDRAM_TRC                       100 //刷新至刷新的等待时间（Refresh to refresh），单位为纳秒
/* active to active time (ns). */
#define SDRAM_ACT2ACT                   70 //有效至有效的等待时间（Active to active） ，单位为纳秒
/* refresh time (ns). 64ms */
#define SDRAM_REFRESH_ROW               64 * 1000000 / 8192 //刷新定时器周期，即每隔多久刷新一行      和紧急刷新阈值

#endif /* SDRAM_PORT_H__ */
