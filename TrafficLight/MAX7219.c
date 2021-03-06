#include<iom16v.h>
#include"MAX7219.h"
#include"delay.h"


//--------------------------------------------
//功能：向MAX7219(U3)写入字节
//入口参数：DATA 
//出口参数：无
//说明：
void Write_Max7219_byte(uchar DATA)         
{
    	uchar i;    
		Max7219_pinCS_L;		
	    for(i=8;i>=1;i--)
          {		  
            Max7219_pinCLK_L;
			if(DATA&0x80)Max7219_pinDIN_H;
			else Max7219_pinDIN_L;
            DATA=DATA<<1;
            Max7219_pinCLK_H;
           }                                 
}
//-------------------------------------------
//功能：向MAX7219写入数据
//入口参数：address、dat
//出口参数：无
//说明：
void Write_Max7219(uchar address,uchar dat)
{ 
     Max7219_pinCS_L;
	 Write_Max7219_byte(address);           //写入地址，即数码管编号
     Write_Max7219_byte(dat);               //写入数据，即数码管显示数字 
	 Max7219_pinCS_H;                        
}

void Init_MAX7219(void)
{
 Write_Max7219(0x09, 0xff);       //译码方式：BCD码
 Write_Max7219(0x0a, 0x03);       //亮度
 Write_Max7219(0x0b, 0x07);       //扫描界限；4个数码管显示
 Write_Max7219(0x0c, 0x01);       //掉电模式：0，普通模式：1
 Write_Max7219(0x0f, 0x01);       //显示测试：1；测试结束，正常显示：0
}
