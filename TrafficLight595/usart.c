/******************************************
    利用中断接收串口接收数据，再对数据进行
	分类判断和执行命令，然后对字母输出
******************************************/


#include<iom16v.h>
#include<macros.h>
#include<string.h>
#include"usart.h"
#include"twi.h"
#include"ds1307.h"

uchar k=0;
uchar getData[20];   //接收数组

uchar urgencyFlag=0,daytimeFlag=1,nightFlag=0;  //事件状态标志位
uchar yellowTime,greenTime,redTime;


void usart_init(void)     //配置usart寄存器
{
     DDRD&=~(1<<PD0);PORTD|=1<<PD0;
	 DDRD|=1<<PD1;PORTD|=1<<PD1;
	 UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);        //8位字符长度
	 UBRRL = 51;                                          //9600bps   8M
	 UCSRB = (1<<RXCIE) | (1<<RXEN) | (1<<TXEN);          //接收中断，发送中断，接收使能，发送使能                                     
} 

#pragma interrupt_handler usart_read:12
void usart_read(void)                   
{       
     while ( !(UCSRA & (1<<RXC)) );     // 等待接收缓存器空
     getData[k]=UDR;
     k++;
	 if((strncmp("green",getData,5))==0)   //修改主干道绿灯时间
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		greenTime = dataBuf;
		Write_EEprom(greenTime,6);
		usart_send('1');
        k=0;
	 }
	 if((strncmp("red",getData,3))==0)   //修改支干道红灯时间
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		redTime = dataBuf;
        Write_EEprom(redTime,5);
        k=0;
	 }
	 if((strncmp("yellow",getData,6))==0)   //修改黄灯时间 
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		yellowTime = dataBuf;
		Write_EEprom(yellowTime,7);
        k=0;
	 }
	 if((strncmp("urgencystart",getData,12))==0)   //紧急情况发生
	 { 
	    urgencyFlag = 1;
		daytimeFlag = 0;
		nightFlag = 0;
		k=0;
	 }
	 if((strncmp("urgencystop",getData,11))==0)   //紧急情况停止
	 { 
	    urgencyFlag = 0;
		daytimeFlag = 1;
		nightFlag = 0;
		secCount = 0;
		k=0;
	 }
	 if((strncmp("timechange",getData,10))==0)   //紧急情况停止
	 { 
	    uchar buf,time_buf;
		
		time_buf = (usart_get()-0x30)*10;
		time_buf = time_buf + (usart_get()-0x30);
		TWI_Write(WD_DS1307_ADDR,time_buf,2);
		
		//usart_send(time_buf);
		k=0;
	 }

}

void usart_send(uchar data)             //TXD发送数据
{
     
    while(!(UCSRA & (1<<UDRE)));   //等待发送缓存器空
    UDR = data;
    while(!(UCSRA & (1<<TXC)));    //等待发送结束
}

uchar usart_get()             //RXD接收数据
{
    
    while ( !(UCSRA & (1<<RXC)) );     // 等待接收缓存器空
	return UDR;
}

