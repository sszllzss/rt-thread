#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_MEMHEAP
#define RT_USING_MEMHEAP_AS_HEAP
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart1"
#define RT_VER_NUM 0x40003

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */


/* Command shell */

#define RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE 80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_USING_MSH_ONLY
#define FINSH_ARG_MAX 10

/* Device virtual file system */

#define RT_USING_DFS
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 2
#define DFS_FILESYSTEM_TYPES_MAX 2
#define DFS_FD_MAX 16
#define RT_USING_DFS_DEVFS

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SERIAL
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_CAN
#define RT_USING_HWTIMER
#define RT_USING_CPUTIME
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_ADC
#define RT_USING_PWM
#define RT_USING_RTC
#define RT_USING_SDIO
#define RT_SDIO_STACK_SIZE 512
#define RT_SDIO_THREAD_PRIORITY 15
#define RT_MMCSD_STACK_SIZE 1024
#define RT_MMCSD_THREAD_PREORITY 22
#define RT_MMCSD_MAX_PARTITION 16
#define RT_USING_SPI
#define RT_USING_SFUD
#define RT_SFUD_USING_SFDP
#define RT_SFUD_SPI_MAX_HZ 50000000
#define RT_USING_WDT

/* Using USB */


/* POSIX layer and C standard library */

#define RT_USING_LIBC
#define RT_USING_POSIX

/* Network */

/* Socket abstraction layer */


/* Network interface device */


/* light weight TCP/IP stack */


/* AT commands */


/* VBUS(Virtual Software BUS) */


/* Utilities */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */


/* multimedia packages */


/* tools packages */


/* system packages */

/* acceleration: Assembly language or algorithmic acceleration packages */


/* Micrium: Micrium software products porting for RT-Thread */


/* peripheral libraries and drivers */


/* AI packages */


/* miscellaneous packages */


/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */


/* Hardware Drivers Config */

#define SOC_IMXRT1052CVL5B

/* On-chip Peripheral Drivers */

#define BSP_USING_DMA
#define BSP_USING_GPIO
#define BSP_USING_LPUART
#define BSP_USING_LPUART1
#define BSP_LPUART1_RX_USING_DMA
#define BSP_LPUART1_RX_DMA_CHANNEL 0
#define BSP_LPUART1_TX_USING_DMA
#define BSP_LPUART1_TX_DMA_CHANNEL 1
#define BSP_USING_LPUART2
#define BSP_LPUART2_RX_USING_DMA
#define BSP_LPUART2_RX_DMA_CHANNEL 6
#define BSP_LPUART2_TX_USING_DMA
#define BSP_LPUART2_TX_DMA_CHANNEL 7
#define BSP_USING_LPUART3
#define BSP_LPUART3_RX_USING_DMA
#define BSP_LPUART3_RX_DMA_CHANNEL 8
#define BSP_LPUART3_TX_USING_DMA
#define BSP_LPUART3_TX_DMA_CHANNEL 9
#define BSP_USING_LPUART4
#define BSP_LPUART4_RX_USING_DMA
#define BSP_LPUART4_RX_DMA_CHANNEL 10
#define BSP_LPUART4_TX_USING_DMA
#define BSP_LPUART4_TX_DMA_CHANNEL 11
#define BSP_USING_HWTIMER
#define BSP_USING_PWM
#define BSP_USING_PWM1
#define BSP_USING_PWM1_CH2
#define BSP_USING_PWM2
#define BSP_USING_PWM2_CH3
#define BSP_USING_I2C
#define BSP_USING_I2C1
#define HW_I2C1_BADURATE_100kHZ
#define BSP_USING_I2C3
#define HW_I2C3_BADURATE_100kHZ
#define BSP_USING_SPI
#define BSP_USING_SPI1
#define BSP_SPI1_USING_DMA
#define BSP_SPI1_RX_DMA_CHANNEL 2
#define BSP_SPI1_TX_DMA_CHANNEL 3
#define BSP_USING_SPI3
#define BSP_SPI3_USING_DMA
#define BSP_SPI3_RX_DMA_CHANNEL 4
#define BSP_SPI3_TX_DMA_CHANNEL 5
#define BSP_USING_SPI4
#define BSP_SPI4_USING_DMA
#define BSP_SPI4_RX_DMA_CHANNEL 12
#define BSP_SPI4_TX_DMA_CHANNEL 13
#define BSP_USING_RTC
#define BSP_USING_WDT
#define BSP_USING_WDT1
#define BSP_USING_ADC
#define BSP_USING_ADC1
#define BSP_USING_ADC2
#define BSP_USING_SDIO
#define BSP_USING_CAN
#define BSP_USING_CAN1
#define BSP_USING_CAN2

/* Onboard Peripheral Drivers */

#define BSP_USING_SDRAM

#endif
