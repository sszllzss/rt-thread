/*
 * @Descripttion: 
 * @version: v1.0
 * @Author: SSZL
 * @e-meil: sszllzss@foxmail.com
 * @Date: 2021-08-05 15:12:09
 * @LastEditors: SSZL
 * @LastEditTime: 2021-08-05 15:17:55
 */
#ifndef _SDRAM_H
#define _SDRAM_H
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK I.MX RT1052������
//SDRAM��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2018/1/3
//�汾��V1.0
//��Ȩ���У�����ؾ���?
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
#include "rtthread.h"
#define SDRAM_START_ADDR    ((uint32_t)(0X80000000)) //SDRAM��ʼ��ַ
#define SDRAM_SIZE_KBYTES   ((uint32_t)(32*1024))    //SDRAM��С����λkBytes

void SDRAM_Init(void);
#endif
