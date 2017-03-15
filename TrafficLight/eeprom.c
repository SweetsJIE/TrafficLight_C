/********************************************************************
            对ATMEGA16内部e2prom进行读写操作
********************************************************************/
#include <iom16v.h>
#include<macros.h>
#include"eeprom.h"
#include"delay.h"
	  

/******************************************************************************/
//读内部EEPROM函数
/******************************************************************************/  				 
uchar Read_EEprom(uint address)
{
    uchar j;
	if(EECR&0x01)delay_nms(32);
	EEARH=address&0x0100;
	EEARL=address&0x00ff;
	EECR|=0x01;       //EEPROM 读使能
	delay_nms(32);
	j=EEDR;      //读取数据
	return(j);
}
/******************************************************************************/
//写入EEPORM函数
/******************************************************************************/  				  
void Write_EEprom(uchar data,uint address)
{
	EEARH=address&0x0100;
	EEARL=address&0x00ff; 
	EEDR=data;    //写入数据
	EECR|=0x04;   //EEPROM 主机写使能
    EECR|=0x02;   //EEPROM 写使能
	delay_nms(32);
}

				
			               
                       
                            
               
                


   
                      
                       
                            
               
                


