#include<iom16v.h>
#include<macros.h>
#include"MAX7219.h"
#include"74LS139.h"
#include"button.h"
#include"delay.h"
#include"ds1307.h"
#include"twi.h"
#include"usart.h"
#include"HC_595.h"

uchar Number_H,Number_L,count=0,i=0;


void io_init()
{
  DDRA=0xFF;
  PORTA=0x00;
  DDRB=0xff;
  PORTB=0xff;
  DDRC=0xe7;
  PORTC=0x00;
  DDRD=0x02;
  PORTD=0x04;
}

void main()
{
  io_init();
  TWI_init();
  TWI_Write(WD_DS1307_ADDR,0X10,7);           //设置ds1307输出方波
  int2_init();
  usart_init();
  HC_595_init();
  
  redTime = Read_EEprom(5);      //读取红绿黄灯的时间
  greenTime = Read_EEprom(6);
  yellowTime = Read_EEprom(7);
  
  
  SREG|=BIT(7);
  
  //修改时间
  /*
  TWI_Write(WD_DS1307_ADDR,00,0);
  TWI_Write(WD_DS1307_ADDR,21,1);
  TWI_Write(WD_DS1307_ADDR,14,2);
  TWI_Write(WD_DS1307_ADDR,17,4);
  TWI_Write(WD_DS1307_ADDR,03,5);
  TWI_Write(WD_DS1307_ADDR,17,6);
  */

  while(1)
  {
    if(daytimeFlag)
	{
	  LS139_G_L;
	  GICR |= (1<<INT2);			//打开外部中断2
	  while(secCount<=greenTime)
	  {
	    if(urgencyFlag || nightFlag)break;
	    Write_Data(1,decode_H(greenTime+yellowTime-secCount));
        Write_Data(2,decode_L(greenTime+yellowTime-secCount));
		Write_Data(3,decode_H(greenTime-secCount));
        Write_Data(4,decode_L(greenTime-secCount));
		main_green();
		second_red();
	  }
	  while(secCount>greenTime&&secCount<=(greenTime+yellowTime))
	  {
	    if(urgencyFlag || nightFlag)break;
	    Write_Data(1,decode_H(greenTime+yellowTime-secCount));
        Write_Data(2,decode_L(greenTime+yellowTime-secCount));
		Write_Data(3,decode_H(greenTime+yellowTime-secCount));
        Write_Data(4,decode_L(greenTime+yellowTime-secCount));
		i++;
		if(i==25)main_yellow();   //黄闪
		else if(i==50)
		{
		  main_close();
		  i=0;
		}
		second_red();
	  }
	  while(secCount>(greenTime+yellowTime)&&secCount<=(greenTime+yellowTime+redTime))
	  {
	    if(urgencyFlag || nightFlag)break;
	    Write_Data(1,decode_H(greenTime+yellowTime+redTime-secCount));
        Write_Data(2,decode_L(greenTime+yellowTime+redTime-secCount));
		Write_Data(3,decode_H(greenTime+yellowTime+yellowTime+redTime-secCount));
        Write_Data(4,decode_L(greenTime+yellowTime+yellowTime+redTime-secCount));
		main_red();
		second_green();
	  }
	  while(secCount>(greenTime+yellowTime+redTime)&&secCount<=(greenTime+yellowTime+redTime+yellowTime))
	  {
	    if(urgencyFlag ||nightFlag)break;
	    Write_Data(1,decode_H(greenTime+yellowTime+redTime+yellowTime-secCount));
        Write_Data(2,decode_L(greenTime+yellowTime+redTime+yellowTime-secCount));
		Write_Data(3,decode_H(greenTime+yellowTime+redTime+yellowTime-secCount));
        Write_Data(4,decode_L(greenTime+yellowTime+redTime+yellowTime-secCount));
		i++;
		if(i==25)second_yellow();   //黄闪
		else if(i==50)
		{
		  second_close();
		  i=0;
		}
		main_red();
	  }
	}
	
	if(nightFlag)            //夜间模式
	{ 
	  //Write_Max7219(0x0c, 0x00);
	  Drive_HC595(0x00,0);
	  Drive_HC595(0x00,1);
	  main_yellow();
	  second_yellow();
	  delay_nms(500);
	  main_close();
	  second_close();
	  delay_nms(500);
	}
	
	if(urgencyFlag)        //紧急模式
	{
	  //GICR &= ~(1<<INT2);			//关闭外部中断2
	  main_red();
	  second_red();
	  while(1)
	  {
	    if(urgencyFlag==0)break;
	    LS139_G_H;
		Write_Data(0,10);  //数码管全亮
		delay_nms(500);
		LS139_G_L;
		Write_Data(0,11);  //数码管全灭
		if(urgencyFlag==0)break;
		delay_nms(500);
	  }
	}
	if(0)        //紧急模式
	{
	  //main_yellow();
	  second_yellow();
	  
	}
  }
  
  
}

//把秒数十位和个位分拆开
void decode_H(uchar data)
{
  Number_H=data/10;
}
void decode_L(uchar data)
{
  Number_L=data%10;
}