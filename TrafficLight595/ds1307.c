
#include <iom16v.h>
#include <macros.h>
#include"twi.h"
#include"usart.h"

uchar time[7]={0};         //读取ds1207内部存储的数据
uchar secCount=0;


void int2_init(void)       //配置外部中断2
{
    DDRB&=~BIT(2);
	PORTB|=BIT(2);
}

#pragma interrupt_handler int2:19          //一次外部中断读取一次ds1307内部存储的数据
void int2(void)
{   
    uchar i;
	
	GICR &= ~(1<<INT2);			//关闭下降沿触发INT2
	
	secCount++;
	if(secCount>=(greenTime+yellowTime+redTime+yellowTime))
	{
	    uchar buf=0,time_buf=12;
		secCount=0;
		
		time[2]=TWI_Read(WD_DS1307_ADDR,RD_DS1307_ADDR,2);
		
		if(time[2]>=0 && time[2] <= 5 && urgencyFlag==0)   //凌晨0-5点夜间模式
		{
		  nightFlag = 1;
		  daytimeFlag = 0;
		}else
		{
		  if(urgencyFlag==0)
		  {
		    nightFlag = 0;
	        daytimeFlag = 1;
		  }
		}
	}
	
	   
	if(secCount%10==0)
	{
	  for(i=0;i<20;i++)                //清空串口暂存数组
	  {
	    getData[i]=0;
	  }
	  delay_nms(1);
	}
	
	
	GICR |= (1<<INT2);			//下降沿触发INT2
}