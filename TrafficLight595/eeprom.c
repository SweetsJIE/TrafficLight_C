/********************************************************************
            ��ATMEGA16�ڲ�e2prom���ж�д����
********************************************************************/
#include <iom16v.h>
#include<macros.h>
#include"eeprom.h"
#include"delay.h"
	  

/******************************************************************************/
//���ڲ�EEPROM����
/******************************************************************************/  				 
uchar Read_EEprom(uint address)
{
    uchar j;
	if(EECR&0x01)delay_nms(32);
	EEARH=address&0x0100;
	EEARL=address&0x00ff;
	EECR|=0x01;       //EEPROM ��ʹ��
	delay_nms(32);
	j=EEDR;      //��ȡ����
	return(j);
}
/******************************************************************************/
//д��EEPORM����
/******************************************************************************/  				  
void Write_EEprom(uchar data,uint address)
{
	EEARH=address&0x0100;
	EEARL=address&0x00ff; 
	EEDR=data;    //д������
	EECR|=0x04;   //EEPROM ����дʹ��
    EECR|=0x02;   //EEPROM дʹ��
	delay_nms(32);
}

				
			               
                       
                            
               
                


   
                      
                       
                            
               
                


