#include "Hardware/uart.h"
#include "Hardware/led.h"
#include "string.h"
#include "stdio.h"
#include "ti/devices/msp/m0p/mspm0g350x.h"
#include "ti/driverlib/dl_uart.h"
#include "ti/driverlib/dl_gpio.h"
#include "Hardware/key.h"
#include "math.h"
//串口屏通信

uint8_t rx_data1[20];
uint16_t rx_cent1=0;
bool rx_flag1=0;

void uart1_init(void)
{
	NVIC_ClearPendingIRQ(UART1_INT_IRQn);   //清除
	NVIC_EnableIRQ(UART1_INT_IRQn);
}

float dacA=0;   //不衰减
float dacB=0;   //衰减



uint16_t sta=0;
float dac=0;
uint16_t rms=255;
uint16_t receive_rms;
void uart1_pro(void)
{
	rx_flag1=0;
    if(rx_data1[0] == 0)         //接受CW信号
    {

        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_17);    //判断是CW还是AM

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);    //有效值  101    最高位
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        // sta=3;
        receive_rms=(rx_data1[1]+rx_data1[2]*256);    
        computer_rms();    //计算需要的系数
        // rms=255;
        rms_void();        //发送
        //控制DAC


        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);    //Ma  001
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[3]-30)/10;
        data_pro();
        delay_ms(10); 

        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //Sm_delay   010
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[4]-50)/30;
        data_pro();
        delay_ms(10); 

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[5])/2;                        //Sm_dec    衰减  110

        // computer_dec();
        // rms_void();


        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //fc      011
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[6]-30);
        data_pro(); 
        delay_ms(10); 

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   //phase   100
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[7])/30;
        data_pro(); 
        delay_ms(10);     

    }

    if(rx_data1[0] == 1)         //接受CW信号
    {

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_17);    //判断是CW还是AM

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);    //有效值  101    最高位
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        // sta=3;
        receive_rms=(rx_data1[1]+rx_data1[2]*256);    
        computer_rms();    //计算需要的系数
        // rms=255;
        rms_void();        //发送
        //控制DAC


        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);    //Ma  001
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[3]-30)/10;
        data_pro();
        delay_ms(10); 

        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //Sm_delay   010
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[4]-50)/30;
        data_pro();
        delay_ms(10); 

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[5])/2;                        //Sm_dec    衰减  110

        // computer_dec();
        // rms_void();


        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //fc      011
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[6]-30);
        data_pro(); 
        delay_ms(10); 

        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   //phase   100
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
        sta=(rx_data1[7])/30;
        data_pro(); 
        delay_ms(10);     

    }
    // if(rx_data1[0] == 1)         //接受AM信号
    // {

    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_17);    //判断是CW还是AM

    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);    //有效值  101    最高位
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);

    //     // sta=(rx_data1[1]+rx_data1[2]*256)/100;     
    //     receive_rms=(rx_data1[1]+rx_data1[2]*256)*1.0/100;

    //     computer_rms();    //计算需要的系数
    //     // rms=255;
    //     rms_void();        //发送系数


        


    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);    //Ma  001
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
    //     sta=(rx_data1[3]-30)/10;
    //     data_pro();
    //     delay_ms(10); 

    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //Sm_delay   010
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
    //     sta=(rx_data1[4]-50)/30;
    //     data_pro();
    //     delay_ms(10); 
    
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   //Sm_dec    衰减  110
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1); 
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
    //     sta=(rx_data1[5])/2;                        
    //     // rms=255;
    //     // computer_dec();
    //     // rms_void();
   

    

    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_15);   //fc      011
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_1);
    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_12);
    //     sta=(rx_data1[6]-30);
    //     data_pro(); 
    //     delay_ms(10); 

    //     DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_15);   //phase   100
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_1);
    //     DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_12);
    //     sta=(rx_data1[7])/30;
    //     data_pro(); 
    //     delay_ms(10);   

    // }
	memset(rx_data1,0,20);
	rx_cent1=0;
    delay_ms(10);
    LED2_blue_OFF();
}

void computer_dec()
{
    if((rx_data1[6]-30) == 0){   
        rms=0.00001*2*receive_rms*receive_rms+0.094012*receive_rms*sqrt(2)-1.211;
    }

    if((rx_data1[6]-30) == 1){
        rms=0.000014*2*receive_rms*receive_rms+0.090266*receive_rms*sqrt(2)+1.6688;
    }

    if((rx_data1[6]-30) == 2){
        rms=0.000011*2*receive_rms*receive_rms+0.0997*receive_rms*sqrt(2)+1.00052;
    }

    if((rx_data1[6]-30) == 3){
        rms=0.000014*2*receive_rms*receive_rms+0.098606*receive_rms*sqrt(2)+1.01269;
    }

    if((rx_data1[6]-30) == 4){
        rms=0.000013*2*receive_rms*receive_rms+0.10749*receive_rms*sqrt(2)+0.800886;
    }

    if((rx_data1[6]-30) == 5){
        rms=0.000014*2*receive_rms*receive_rms+0.108798*receive_rms*sqrt(2)+0.84808;
    }

    if((rx_data1[6]-30) == 6){
        rms=0.000017*2*receive_rms*receive_rms+0.09648*receive_rms*sqrt(2)+1.06585;
    }

    if((rx_data1[6]-30) == 7){
        rms=0.000018*2*receive_rms*receive_rms+0.112707*receive_rms*sqrt(2)+0.865955;
    }

    if((rx_data1[6]-30) == 8){
        rms=0.000022*2*receive_rms*receive_rms+0.114767*receive_rms*sqrt(2)+1.40440;
    }

    if((rx_data1[6]-30) == 9){
        rms=0.000021*2*receive_rms*receive_rms+0.128452*receive_rms*sqrt(2)+0.28544;
    }

    if((rx_data1[6]-30) == 10){
        rms=0.000021*2*receive_rms*receive_rms+0.146131*receive_rms*sqrt(2)+0.92314;
    }
    
    //开始对值修改
    if(sta==0)
        sta=sta;
    if(sta==1)
        sta=sta*0.794;
    if(sta==2)
        sta=sta*0.631;
    if(sta==3)
        sta=sta*0.5012;
    if(sta==4)
        sta=sta*0.398;
    if(sta==5)
        sta=sta*0.3162;
    if(sta==6)
        sta=sta*0.2512;
    if(sta==7)
        sta=sta*0.1995;
    if(sta==8)
        sta=sta*0.158;
    if(sta==9)
        sta=sta*0.1259;
    if(sta==10)
        sta=sta*0.1;

}


void computer_rms()
{
    if((rx_data1[6]-30) == 0){   
        rms=0.00001*2*receive_rms*receive_rms+0.094012*receive_rms*sqrt(2)-1.211;
    }

    if((rx_data1[6]-30) == 1){
        rms=0.000014*2*receive_rms*receive_rms+0.090266*receive_rms*sqrt(2)+1.6688;
    }

    if((rx_data1[6]-30) == 2){
        rms=0.000011*2*receive_rms*receive_rms+0.0997*receive_rms*sqrt(2)+1.00052;
    }

    if((rx_data1[6]-30) == 3){
        rms=0.000014*2*receive_rms*receive_rms+0.098606*receive_rms*sqrt(2)+1.01269;
    }

    if((rx_data1[6]-30) == 4){
        rms=0.000013*2*receive_rms*receive_rms+0.10749*receive_rms*sqrt(2)+0.800886;
    }

    if((rx_data1[6]-30) == 5){
        rms=0.000014*2*receive_rms*receive_rms+0.108798*receive_rms*sqrt(2)+0.84808;
    }

    if((rx_data1[6]-30) == 6){
        rms=0.000017*2*receive_rms*receive_rms+0.09648*receive_rms*sqrt(2)+1.06585;
    }

    
    if((rx_data1[6]-30) == 7){
        rms=0.000018*2*receive_rms*receive_rms+0.112707*receive_rms*sqrt(2)+0.865955;
    }

    if((rx_data1[6]-30) == 8){
        rms=0.000022*2*receive_rms*receive_rms+0.114767*receive_rms*sqrt(2)+1.40440;
    }

    if((rx_data1[6]-30) == 9){
        rms=0.000021*2*receive_rms*receive_rms+0.128452*receive_rms*sqrt(2)+0.28544;
    }

    if((rx_data1[6]-30) == 10){
        rms=0.000021*2*receive_rms*receive_rms+0.146131*receive_rms*sqrt(2)+0.92314;
    }
}


void rms_void()
{
    // bool status;
    if(rms & 0x01){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);   //最低位
    }
    else {
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
    }

    if(rms & 0x02){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
    }
    else {
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
    }

    if(rms & 0x04){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_0);
    }
    else {
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
    }

    if(rms & 0x08){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_16);
    }
    else {
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
    }

//上面是低位，下面是高位
    if(rms & 0x10){
        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_28);
    }
    else {  
        DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_28);
    }

    if(rms & 0x20){
        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_31);
    }
    else {  
        DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_31);
    }

    if(rms & 0x40){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_20);
    }
    else {  
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_20);
    }

    if(rms & 0x80){
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_13);
    }
    else {  
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_13);
    }
    DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_4);
    delay_ms(2);
    DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_4);

}

void data_pro()
{
        if(sta == 0)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);    //高位
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);    //最低位
        }
        if(sta == 1)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 2)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 3)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 4)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 5)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 6)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 7)
        {
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 8)
        {
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 9)
        {
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_8);
        }
        if(sta == 10)
        {
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_16);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_0);
            DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_6);
            DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_8);
        }
        
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_4);
        delay_ms(2);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_4);
}

void dec_pro()
{
    if(sta == 0)
    {
        dacB=dacA;
    }
    if(sta == 2)
    {
        dacB=dacA*0.794;
    }
    if(sta == 4)
    {
        dacB=dacA*0.631;
    }
    if(sta == 6)
    {
        dacB=dacA*0.501;
    }
    if(sta == 8)
    {
        dacB=dacA*0.398;
    }
    if(sta == 10)
    {
        dacB=dacA*0.316;
    }
    if(sta == 12)
    {
        dacB=dacA*0.2512;
    }
    if(sta == 14)
    {
        dacB=dacA*0.2;
    }
    if(sta == 16)
    {
        dacB=dacA*0.158;
    }
    if(sta == 18)
    {
        dacB=dacA*0.126;
    }
    if(sta == 20)
    {
        dacB=dacA*0.1;
    }
}

void UART1_IRQHandler()
{
	switch (DL_UART_Main_getPendingInterrupt(UART1))
	{
		case DL_UART_MAIN_IIDX_RX:
			rx_flag1=1;
			LED2_blue_ON();
			rx_data1[rx_cent1++]=DL_UART_Main_receiveData(UART1);
			break;
		default:
			break;
	}
}



//................................................................片内通信
uint8_t rx_data[200];
uint16_t rx_cent=0;
bool rx_flag=0;


void uart_init(void)
{
	NVIC_ClearPendingIRQ(UART0_INT_IRQn);   //清除
	NVIC_EnableIRQ(UART0_INT_IRQn);

}

void UART0_IRQHandler()
{
	switch (DL_UART_Main_getPendingInterrupt(UART0))
	{
		case DL_UART_MAIN_IIDX_RX:
			rx_flag=1;
			// LED2_blue_ON();
			rx_data[rx_cent++]=DL_UART_Main_receiveData(UART0);
			break;
		default:
			break;
	}
}


void uart_pro(void)
{
	DL_UART_transmitData(UART0,rx_data[0]);
	rx_flag=0;
	memset(rx_data,0,200);
	rx_cent=0;
}

int fputc(int c, FILE* stream)
{
	DL_UART_Extend_transmitDataBlocking(UART0,c);
	return c;
}

int fputs(const char* restrict s,FILE* restrict stream)
{
    uint16_t i,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        DL_UART_Main_transmitDataBlocking(UART0,s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
    int count = fputs(_ptr,stdout);
    count += fputs("\n",stdout);
    return count;
}

void sendString(char *str)                            //任意串口发送
{
    while (*str != '\0')
    {
        DL_UART_transmitDataBlocking(UART1, *str++);
    }
}



