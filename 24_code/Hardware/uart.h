#ifndef _UART_H
#define _UART_H
#include <ti/driverlib/dl_uart_extend.h>
#include <ti/driverlib/dl_uart_main.h>
#include "stdint.h"


extern uint8_t rx_data[200];
extern bool rx_flag;
void uart_init(void);
void uart_pro(void);

extern uint8_t rx_data1[20];
extern bool rx_flag1;
void sendString(char *str);
void uart1_init(void);
void UART1_IRQHandler(void);
void uart1_pro(void);
void data_pro();
void dec_pro();
void rms_void();
void computer_rms();
void computer_dec();

extern float dacA;   //不衰减
extern float dacB;   //衰减

extern uint16_t rms;


#endif
