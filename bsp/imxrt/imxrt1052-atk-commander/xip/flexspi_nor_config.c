/*
 * Copyright 2017-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "flexspi_nor_config.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xip_board"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(XIP_BOOT_HEADER_ENABLE) && (XIP_BOOT_HEADER_ENABLE == 1)
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) || defined(__GNUC__)
__attribute__((section(".boot_hdr.conf"), used))
#elif defined(__ICCARM__)
#pragma location = ".boot_hdr.conf"
#endif
//注意 0 1 2 3 4 5 8 9 11 15 为BootROM 预设尽量不要修改
#define CMD_LUT_SEQ_IDX_READ            0
#define CMD_LUT_SEQ_IDX_READSTATUS      1
#define CMD_LUT_SEQ_IDX_WRITEENABLE     3
#define CMD_LUT_SEQ_IDX_SECTORERASE     5
#define CMD_LUT_SEQ_IDX_RESETENABLE     6
#define CMD_LUT_SEQ_IDX_RESET           7
#define CMD_LUT_SEQ_IDX_BLOCKERASE      8
#define CMD_LUT_SEQ_IDX_WRITE           9
#define CMD_LUT_SEQ_IDX_WRITESTATUS1_2  10
#define CMD_LUT_SEQ_IDX_CHIPERASE       11
#define CMD_LUT_SEQ_IDX_EXITNOCOM       15



const flexspi_nor_config_t spiflash_w25q64_config  = {
	.memConfig =
	{
		.tag = FLEXSPI_CFG_BLK_TAG,/*标志：FCFB*/
		.version = FLEXSPI_CFG_BLK_VERSION,/*版本：V1.4.0*/
		.readSampleClkSrc = kFlexSPIReadSampleClk_LoopbackInternally,/*内部环回*/
		.csHoldTime = 3u, /*保持时间*/
		.csSetupTime = 3u,/*建立时间*/
		.columnAddressWidth = 0u,/*列地址宽度*/
//		.deviceModeCfgEnable = 1u,/*设备模式配置使能*/
//		.deviceModeType = kDeviceConfigCmdType_QuadEnable,/*Quad 使能命令*/
//		.deviceModeSeq.seqNum = 1u,/*LUT序列号*/
//		.deviceModeSeq.seqId = CMD_LUT_SEQ_IDX_WRITESTATUS1_2, /*LUT序列索引*/
//		.deviceModeArg = 0x000200,/*设置 QE=1（S9）*/
		.configCmdEnable = 1u,/* 打开命令配置 */
		.configModeType[0] = kDeviceConfigCmdType_Generic,
        .configCmdSeqs[0] = /*指示Flash寄存器配置时序在LUT中index */
			{
				.seqNum = 1u,/*LUT序列号*/
				.seqId = CMD_LUT_SEQ_IDX_RESETENABLE,/*LUT序列索引*/
				.reserved = 0
			},
		.configModeType[1] = kDeviceConfigCmdType_Reset,
	    .configCmdSeqs[1] = /*指示Flash寄存器配置时序在LUT中index */
				{
					.seqNum = 1u,/*LUT序列号*/
					.seqId = CMD_LUT_SEQ_IDX_RESET,/*LUT序列索引*/
					.reserved = 0
				},
		.configModeType[2] = kDeviceConfigCmdType_QuadEnable,
		.configCmdSeqs[2] = /*指示Flash寄存器配置时序在LUT中index */
			{
				.seqNum = 1u,/*LUT序列号*/
				.seqId = CMD_LUT_SEQ_IDX_WRITESTATUS1_2,/*LUT序列索引*/
				.reserved = 0
			},
		.configCmdArgs[2] =  0x000200,/*设置 QE=1（S9）*/
		//.controllerMiscOption = kFlexSpiMiscOffset_SafeConfigFreqEnable,
		.deviceType = kFlexSpiDeviceType_SerialNOR,/*设备类型为nor flash*/
		.sflashPadType = kSerialFlash_4Pads,/*设备数据总线为4*/
		.serialClkFreq = kFlexSpiSerialClk_133MHz,/*flash 时钟*/
		.sflashA1Size = 8u * 1024u * 1024u,      /*flash 大小8MBytes*/
		//.dataValidTime = {16u, 16u},
		.lookupTable =
		{
			/*快速读命令（四线）连续读*/
			[4*CMD_LUT_SEQ_IDX_READ+0]     = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xEB, RADDR_SDR, FLEXSPI_4PAD, 0x18),
			[4*CMD_LUT_SEQ_IDX_READ+1]     = FLEXSPI_LUT_SEQ(MODE8_SDR, FLEXSPI_4PAD, 0x20, DUMMY_SDR, FLEXSPI_4PAD, 0x04),// MODE8_SDR里参数值填入0x20
			[4*CMD_LUT_SEQ_IDX_READ+2]     = FLEXSPI_LUT_SEQ(READ_SDR, FLEXSPI_4PAD, 0x04, JMP_ON_CS, FLEXSPI_1PAD, 0x01),
			[4*CMD_LUT_SEQ_IDX_READ+3]     = FLEXSPI_LUT_SEQ(STOP, FLEXSPI_1PAD, 0x00, 0, 0, 0),
			/* 快速读命令（四线） */
//			[4*CMD_LUT_SEQ_IDX_READ+0]     = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xEB, RADDR_SDR, FLEXSPI_4PAD, 0x18),
//			[4*CMD_LUT_SEQ_IDX_READ+1]     = FLEXSPI_LUT_SEQ(MODE8_SDR, FLEXSPI_4PAD, 0x00, DUMMY_SDR, FLEXSPI_4PAD, 0x04),
//			[4*CMD_LUT_SEQ_IDX_READ+2]     = FLEXSPI_LUT_SEQ(READ_SDR, FLEXSPI_4PAD, 0x04, STOP, FLEXSPI_1PAD, 0x00),
			/*读状态命令*/
			[4*CMD_LUT_SEQ_IDX_READSTATUS+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x05, READ_SDR, FLEXSPI_1PAD, 0x04),
			[4*CMD_LUT_SEQ_IDX_READSTATUS+1]   = FLEXSPI_LUT_SEQ(STOP, FLEXSPI_1PAD, 0x00, STOP, FLEXSPI_1PAD, 0x00),
			/*写使能命令*/
			[4*CMD_LUT_SEQ_IDX_WRITEENABLE+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x06, STOP, FLEXSPI_1PAD, 0x00),
			/*擦除扇区命令*/
			[4*CMD_LUT_SEQ_IDX_SECTORERASE+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x20, RADDR_SDR, FLEXSPI_1PAD, 0x18),
			[4*CMD_LUT_SEQ_IDX_SECTORERASE+1]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x20, RADDR_SDR, FLEXSPI_1PAD, 0x18),
			/* 启用复位 */
			[4*CMD_LUT_SEQ_IDX_RESETENABLE+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x66, STOP, FLEXSPI_1PAD, 0x00),
			/* 复位外部Flash */
			[4*CMD_LUT_SEQ_IDX_RESET+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x99, STOP, FLEXSPI_1PAD, 0x00),
			/* 写状态寄存器1-2 */
			[4*CMD_LUT_SEQ_IDX_WRITESTATUS1_2+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x01, WRITE_SDR, FLEXSPI_1PAD, 0x2),
			/*擦除块命令*/
			[4*CMD_LUT_SEQ_IDX_BLOCKERASE+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xD8, RADDR_SDR, FLEXSPI_1PAD, 0x18),
			/*页编程命令（四线）*/
			[4*CMD_LUT_SEQ_IDX_WRITE+0]   = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x32, RADDR_SDR, FLEXSPI_1PAD, 0x18),
			[4*CMD_LUT_SEQ_IDX_WRITE+1] = FLEXSPI_LUT_SEQ(WRITE_SDR,FLEXSPI_4PAD , 0x04, STOP, FLEXSPI_1PAD, 0x00),
			/*整片擦除*/
			[4*CMD_LUT_SEQ_IDX_CHIPERASE+0]  = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xc7, STOP, FLEXSPI_1PAD, 0x00),
			/*退出Exit No Command Mode*/
			[4*CMD_LUT_SEQ_IDX_EXITNOCOM+0]     = FLEXSPI_LUT_SEQ(RADDR_SDR, FLEXSPI_4PAD, 0x18, MODE8_SDR, FLEXSPI_4PAD, 0xFF),// MODE8_SDR里参数值填入0xFF
			[4*CMD_LUT_SEQ_IDX_EXITNOCOM+1]     = FLEXSPI_LUT_SEQ(DUMMY_SDR, FLEXSPI_4PAD, 0x04, READ_SDR, FLEXSPI_4PAD, 0x01),
		},
	},
	.pageSize = 256u,/*页大小为256字节*/
	.sectorSize = 4u * 1024u,/*扇区大小为4k字节*/
	.serialNorType = 0,/*   Extended SPI */
	.blockSize = 64u* 1024u,/*储存块大小64k字节*/
	.isUniformBlockSize = false,
};
#endif /* XIP_BOOT_HEADER_ENABLE */
