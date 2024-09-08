/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (62499U)



/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOB
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_7
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM24)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM19)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM24_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM19_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_1_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_0_FBRD_32_MHZ_9600_BAUD                                        (21)





/* Defines for PIN_0: GPIOA.0 with pinCMx 1 on package pin 33 */
#define GPIO_led_PIN_0_PORT                                              (GPIOA)
#define GPIO_led_PIN_0_PIN                                       (DL_GPIO_PIN_0)
#define GPIO_led_PIN_0_IOMUX                                      (IOMUX_PINCM1)
/* Defines for PIN_22: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_led_PIN_22_PORT                                             (GPIOB)
#define GPIO_led_PIN_22_PIN                                     (DL_GPIO_PIN_22)
#define GPIO_led_PIN_22_IOMUX                                    (IOMUX_PINCM50)
/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_key_PIN_18_PORT                                             (GPIOA)
#define GPIO_key_PIN_18_PIN                                     (DL_GPIO_PIN_18)
#define GPIO_key_PIN_18_IOMUX                                    (IOMUX_PINCM40)
/* Defines for PIN_21: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_key_PIN_21_PORT                                             (GPIOB)
#define GPIO_key_PIN_21_PIN                                     (DL_GPIO_PIN_21)
#define GPIO_key_PIN_21_IOMUX                                    (IOMUX_PINCM49)
/* Defines for PIN_CS0: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_uart_PIN_CS0_PORT                                           (GPIOB)
#define GPIO_uart_PIN_CS0_PIN                                   (DL_GPIO_PIN_12)
#define GPIO_uart_PIN_CS0_IOMUX                                  (IOMUX_PINCM29)
/* Defines for PIN_CS1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_uart_PIN_CS1_PORT                                           (GPIOB)
#define GPIO_uart_PIN_CS1_PIN                                    (DL_GPIO_PIN_1)
#define GPIO_uart_PIN_CS1_IOMUX                                  (IOMUX_PINCM13)
/* Defines for PIN_CS2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_uart_PIN_CS2_PORT                                           (GPIOB)
#define GPIO_uart_PIN_CS2_PIN                                   (DL_GPIO_PIN_15)
#define GPIO_uart_PIN_CS2_IOMUX                                  (IOMUX_PINCM32)
/* Defines for PIN_data0: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_uart_PIN_data0_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data0_PIN                                  (DL_GPIO_PIN_8)
#define GPIO_uart_PIN_data0_IOMUX                                (IOMUX_PINCM25)
/* Defines for PIN_data1: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_uart_PIN_data1_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data1_PIN                                  (DL_GPIO_PIN_6)
#define GPIO_uart_PIN_data1_IOMUX                                (IOMUX_PINCM23)
/* Defines for PIN_data2: GPIOB.0 with pinCMx 12 on package pin 47 */
#define GPIO_uart_PIN_data2_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data2_PIN                                  (DL_GPIO_PIN_0)
#define GPIO_uart_PIN_data2_IOMUX                                (IOMUX_PINCM12)
/* Defines for PIN_data3: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_uart_PIN_data3_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data3_PIN                                 (DL_GPIO_PIN_16)
#define GPIO_uart_PIN_data3_IOMUX                                (IOMUX_PINCM33)
/* Defines for PIN_CLK: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_uart_PIN_CLK_PORT                                           (GPIOB)
#define GPIO_uart_PIN_CLK_PIN                                    (DL_GPIO_PIN_4)
#define GPIO_uart_PIN_CLK_IOMUX                                  (IOMUX_PINCM17)
/* Defines for PIN_sel: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_uart_PIN_sel_PORT                                           (GPIOB)
#define GPIO_uart_PIN_sel_PIN                                   (DL_GPIO_PIN_17)
#define GPIO_uart_PIN_sel_IOMUX                                  (IOMUX_PINCM43)
/* Defines for PIN_data4: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_uart_PIN_data4_PORT                                         (GPIOA)
#define GPIO_uart_PIN_data4_PIN                                 (DL_GPIO_PIN_28)
#define GPIO_uart_PIN_data4_IOMUX                                 (IOMUX_PINCM3)
/* Defines for PIN_data5: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_uart_PIN_data5_PORT                                         (GPIOA)
#define GPIO_uart_PIN_data5_PIN                                 (DL_GPIO_PIN_31)
#define GPIO_uart_PIN_data5_IOMUX                                 (IOMUX_PINCM6)
/* Defines for PIN_data6: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_uart_PIN_data6_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data6_PIN                                 (DL_GPIO_PIN_20)
#define GPIO_uart_PIN_data6_IOMUX                                (IOMUX_PINCM48)
/* Defines for PIN_data7: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_uart_PIN_data7_PORT                                         (GPIOB)
#define GPIO_uart_PIN_data7_PIN                                 (DL_GPIO_PIN_13)
#define GPIO_uart_PIN_data7_IOMUX                                (IOMUX_PINCM30)
/* Defines for PIN_din: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_DAC_PIN_din_PORT                                            (GPIOB)
#define GPIO_DAC_PIN_din_PIN                                    (DL_GPIO_PIN_19)
#define GPIO_DAC_PIN_din_IOMUX                                   (IOMUX_PINCM45)
/* Defines for PIN_clk: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_DAC_PIN_clk_PORT                                            (GPIOA)
#define GPIO_DAC_PIN_clk_PIN                                    (DL_GPIO_PIN_22)
#define GPIO_DAC_PIN_clk_IOMUX                                   (IOMUX_PINCM47)
/* Defines for PIN_cs: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_DAC_PIN_cs_PORT                                             (GPIOB)
#define GPIO_DAC_PIN_cs_PIN                                     (DL_GPIO_PIN_18)
#define GPIO_DAC_PIN_cs_IOMUX                                    (IOMUX_PINCM44)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
