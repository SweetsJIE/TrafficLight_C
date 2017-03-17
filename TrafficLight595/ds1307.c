
#include <iom16v.h>
#include <macros.h>
#include"twi.h"
#include"usart.h"

uchar time[7]={0};         //��ȡds1207�ڲ��洢������
uchar secCount=0;


void int2_init(void)       //�����ⲿ�ж�2
{
    DDRB&=~BIT(2);
	PORTB|=BIT(2);
}

#pragma interrupt_handler int2:19          //һ���ⲿ�ж϶�ȡһ��ds1307�ڲ��洢������
void int2(void)
{   
    uchar i;
	
	GICR &= ~(1<<INT2);			//�ر��½��ش���INT2
	
	secCount++;
	if(secCount>=(greenTime+yellowTime+redTime+yellowTime))
	{
	    uchar buf=0,time_buf=12;
		secCount=0;
		
		time[2]=TWI_Read(WD_DS1307_ADDR,RD_DS1307_ADDR,2);
		
		if(time[2]>=0 && time[2] <= 5 && urgencyFlag==0)   //�賿0-5��ҹ��ģʽ
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
	  for(i=0;i<20;i++)                //��մ����ݴ�����
	  {
	    getData[i]=0;
	  }
	  delay_nms(1);
	}
	
	
	GICR |= (1<<INT2);			//�½��ش���INT2
}