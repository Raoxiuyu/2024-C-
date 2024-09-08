#ifndef DAC_H
#define DAC_H
//****************tlv5638头文件******************//
#include "ti/driverlib/dl_gpio.h"

#define uint unsigned int
#define uchar unsigned char

/*** 参数定义 ***/
//速度模式参数
#define FASTSP 1 //快速模式
#define SLOWSP 0 //慢速模式

//电源模式参数
#define PWR_DOWN 1 //掉电模式
#define PWR_ON 0 //正常模式

//寄存器选择参数
#define DACB_BUFFER 0 //写DACB和BUFFER
#define BUFFER 1 //写BUFFER
#define DACA_BUFFERTOB 2 //写DACA和BUFFER的值更新DACB
#define CONTROL 3 //写控制寄存器

//参考源选择参数
#define EXTERNAL 0 //外部参考源
#define IN_1024 1 //内部1.024V参考源
#define IN_2048 2 //内部2.048V参考源

//引脚定义
//sbit PinDIN=P0^0;
//sbit PinSCLK=P0^2;
//sbit PinCS=P0^4;

//引脚定义 p1.5 DIN ; P1.4 SCLK;P1.3 CS;

// #define PinDIN BIT5
// #define PinSCLK BIT4
// #define PinCS BIT3

#define Set_PinDIN()   DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_19) //
#define Set_PinSCLK()  DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_22)
#define Set_PinCS()    DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_18)


#define Clr_PinDIN()   DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_19)
#define Clr_PinSCLK()  DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_22) //
#define Clr_PinCS()    DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_18)


void Init_DA5638();

//函数功能：短延时
void nNOP(uchar x);

//函数功能：长延时
void LongDelay(uint i);

//函数功能：置/复位CS信号
//说明：x=1—置位，x=0—复位
//#define SetCS(x)(PinCS=(x)?1:0)

//函数功能：置/复位SCLK信号
//说明：x=1—置位，x=0—复位
//#define SetSCLK(x) (PinSCLK=(x)?1:0)

//函数功能：向SPI写16位数据
//说明：temp为16位的数据
void SPIWrite(uint temp);

//函数功能：将电压值转换为对应的12位数字量
//说明：ref为参考源，ex_ref为当选择外部参考源的电压值，
// out_volt为输出模拟电压值
// 返回12数字量
int VoltToData(uint ref,float ex_ref,float out_volt);

//函数功能：设置DAC A（即A通道）输出
//说明：speed为速度模式，ref为参考源选择，temp为需要输出的电压
// ex_ref为当选择外部参考源的电压值
void SetDAC_A(uint speed,uint ref,float ex_ref,float temp);

//函数功能：设置DAC B（即B通道）输出
//说明：speed为速度模式，ref为参考源选择，temp为需要输出的电压
// ex_ref为当选择外部参考源的电压值
void SetDAC_B(uint speed,uint ref,float ex_ref,float temp);

//函数功能：设置DAC A与DAC B同时输出
//说明：speed为速度模式，ref为参考源选择，
// temp1为A通道需要输出的电压，temp2为B通道需要输出的电压
// ex_ref为当选择外部参考源的电压值
void SetDAC_AB(uint speed,uint ref,float ex_ref,float temp1,float temp2);


#endif//




