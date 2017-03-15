/******************************************
    �����жϽ��մ��ڽ������ݣ��ٶ����ݽ���
	�����жϺ�ִ�����Ȼ�����ĸ���
******************************************/


#include<iom16v.h>
#include<macros.h>
#include<string.h>
#include"usart.h"
#include"twi.h"

uchar k=0;
uchar getData[20];   //��������

uchar urgencyFlag=0,daytimeFlag=1,nightFlag=0;  //�¼�״̬��־λ
uchar yellowTime,greenTime,redTime;


void usart_init(void)     //����usart�Ĵ���
{
     DDRD&=~(1<<PD0);PORTD|=1<<PD0;
	 DDRD|=1<<PD1;PORTD|=1<<PD1;
	 UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);        //8λ�ַ�����
	 UBRRL = 51;                                          //9600bps   8M
	 UCSRB = (1<<RXCIE) | (1<<RXEN) | (1<<TXEN);          //�����жϣ������жϣ�����ʹ�ܣ�����ʹ��                                     
} 

#pragma interrupt_handler usart_read:12
void usart_read(void)                   
{       
     while ( !(UCSRA & (1<<RXC)) );     // �ȴ����ջ�������
     getData[k]=UDR;
     k++;
	 if((strncmp("green",getData,5))==0)   //�޸����ɵ��̵�ʱ��
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		greenTime = dataBuf;
		Write_EEprom(greenTime,1);
		usart_send('1');
        k=0;
	 }
	 if((strncmp("red",getData,3))==0)   //�޸�֧�ɵ����ʱ��
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		redTime = dataBuf;
        Write_EEprom(redTime,0);
        k=0;
	 }
	 if((strncmp("yellow",getData,6))==0)   //�޸ĻƵ�ʱ�� 
	 { 
	    uchar dataBuf;          
		dataBuf = (usart_get()-0x30)*10;
		dataBuf = dataBuf + (usart_get()-0x30);
		yellowTime = dataBuf;
		Write_EEprom(yellowTime,2);
        k=0;
	 }
	 if((strncmp("urgencystart",getData,12))==0)   //�����������
	 { 
	    urgencyFlag = 1;
		daytimeFlag = 0;
		nightFlag = 0;
	 }
	 if((strncmp("urgencystop",getData,11))==0)   //�������ֹͣ
	 { 
	    urgencyFlag = 0;
		daytimeFlag = 1;
		nightFlag = 0;
	 }
	 if((strncmp("timechange",getData,10))==0)   //�������ֹͣ
	 { 
	    uchar buf,time_buf;
		
		time_buf = (usart_get()-0x30)*10;
		time_buf = time_buf + (usart_get()-0x30);
		TWI_Write(WD_DS1307_ADDR,time_buf,2);
		
		usart_send(time_buf);
	 }

}

void usart_send(uchar data)             //TXD��������
{
     
    while(!(UCSRA & (1<<UDRE)));   //�ȴ����ͻ�������
    UDR = data;
    while(!(UCSRA & (1<<TXC)));    //�ȴ����ͽ���
}

uchar usart_get()             //RXD��������
{
    
    while ( !(UCSRA & (1<<RXC)) );     // �ȴ����ջ�������
	return UDR;
}
