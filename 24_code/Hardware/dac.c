#include "Hardware/dac.h"

/*

 */
//**************主函数*****************//

//unsigned char watchar=0;
//long watchlong=0;
unsigned int watchint=0,watchint1=0,watchint2=0 ,watchint3=0,watchint4=0,watchint5=0,watch6=0,watch7;
//短延时函数：nNop( )



void Init_DA5638()
{
    Clr_PinDIN();
    Clr_PinCS();
    Clr_PinSCLK();
}

void nNop(uchar i)
{
    for(;i>0;i--);
}

//长延时函数：LongDelay( )
void LongDelay(uint i)
{
    uint j;
    for(;i>0;i--)
    {
        for(j=1000;j>0;j--);
    }
}

//向SPI写16位数据函数：SPIWrite( )
void SPIWrite(uint temp)
{
    uint i,n;
    Clr_PinCS();
    for(i=0;i<16;i++)
    {
        n=(temp&0x8000);
        if (n==0x8000)
            {Set_PinDIN();}
        else
            {Clr_PinDIN();}
        Set_PinSCLK();
        watch6=temp;
        temp<<=1;
        watch7=temp;
        nNop(1);
        Clr_PinSCLK();
        nNop(1);
    }
    Set_PinCS();
}

//将电压值转换为对应的12位数字量函数：VoltToData( )
int VoltToData(uint ref,float ex_ref,float out_volt)
{
    int temp;
    switch(ref)
    {
        case EXTERNAL:temp=(int)((out_volt*4096)/(2*ex_ref));
        break;
        case IN_1024:temp=(int)((out_volt*4096)/(2*1.024)/1.1);
        break;
        case IN_2048:temp=(int)((out_volt*4096)/(2*2.048)/1.1);
        break;
        default:break;
    }
    watchint=temp;
    watchint1=(temp&0xfff);
    return(temp&0xfff);
}

//设置DAC A（即A通道）输出函数：SetDAC_A( )
void SetDAC_A(uint speed,uint ref,float ex_ref,float temp)
{
    int ModCMD;
    int Data;
    ModCMD=0x9000|(speed<<14)|(ref);
    Data=VoltToData(ref,ex_ref,temp);
    Data=Data|0x8000|(speed<<14);
    SPIWrite(ModCMD);
    nNop(10);
    SPIWrite(Data);
}

//设置DAC B（即B通道）输出函数：SetDAC_B( )
void SetDAC_B(uint speed,uint ref,float ex_ref,float temp)
{
    int ModCMD;
    int Data;
    ModCMD=0x9000|(speed<<14)|(ref);
    watchint5=ModCMD;
    Data=VoltToData(ref,ex_ref,temp);
    watchint2=temp;
    watchint3=Data;
    Data=Data|0x0000|(speed<<14);
    watchint4=Data;
    SPIWrite(ModCMD);
    nNop(10);
    SPIWrite(Data);
}

//设置DAC A与DAC B同时输出函数SetDAC_AB( )
void SetDAC_AB(uint speed,uint ref,float ex_ref,float temp1,float temp2)
{
    int ModCMD;
    int DataA,DataB;
    ModCMD=0x9000|(speed<<14)|(ref);
    DataA=VoltToData(ref,ex_ref,temp1);
    DataA=DataA|0x8000|(speed<<14);
    DataB=VoltToData(ref,ex_ref,temp2);
    DataB=DataB|0x1000|(speed<<14);
    SPIWrite(ModCMD);
    SPIWrite(DataB);
    SPIWrite(DataA);
}

