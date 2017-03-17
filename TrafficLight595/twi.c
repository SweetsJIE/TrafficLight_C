/********************************************************************
            利用i2c对外部e2prom进行读写操作
********************************************************************/
#include <iom16v.h>
#include <macros.h>
#include"twi.h"


void TWI_init(void)
{  
   TWBR=0X0F;      //比特率
   TWSR=0;         //1分频
}

uchar TWI_Write(uchar SlaveAddress,uchar Wdata,uchar RegAddress)
{
   Start();      		 	   //TWI启动
   Wait();
   if(Satus()!=START) 
   return FALSE;    
   
   Write8Bit(SlaveAddress); //写 从机地址和写方式
   Wait();
   if(Satus()!=MT_SLA_ACK) 
   return FALSE;     
      
   Write8Bit(RegAddress);  	   //写 从机相应寄存器地址
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;        
  
   Write8Bit(Wdata);     	   //写数据到 从机相应寄存器
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;         
   
   Stop();        	 		   //TWI停止
   delay_nms(10);   		   	   //延时
   return TRUE;
}


uchar TWI_Read(uchar SlaveAddress_W,uchar SlaveAddress_R,uchar RegAddress)
{
   uchar temp;
   Start();	   			  	   //TWI启动
   Wait();
   //if (Satus()!=START) 
   // return FALSE;        
    
   Write8Bit(SlaveAddress_W); //写 从机地址和写方式
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //写 从机相应寄存器地址
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI重新启动
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(SlaveAddress_R); //写 从机地址和读方式
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //启动主TWI读方式
   Wait();
   if(Satus()!=MR_DATA_NOACK)//读完一个数停止接收数据 ，主机接收到不再接收应答信号 ，如果继续接收到应答信号
   							  //说明主机继续接收数据则为错误	 													 																		 
    return FALSE;     
    
   temp=TWDR;        		   //读取 TWI接收数据
   Stop();          		   //TWI停止
   return temp;
} 

uchar TWI_Read_1307(uchar SlaveAddress_W,uchar SlaveAddress_R,uchar RegAddress,uchar *data)
{
   Start();	   			  	   //TWI启动
   Wait();
   if (Satus()!=START) 
    return FALSE;        
    
   Write8Bit(SlaveAddress_W); //写 从机地址和写方式
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //写 从机相应寄存器地址
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI重新启动
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(SlaveAddress_R); //写 从机地址和读方式
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //启动主TWI读方式
   Wait();
   if(Satus()!=MR_DATA_NOACK)//读完一个数停止接收数据 ，主机接收到不再接收应答信号 ，如果继续接收到应答信号						  
                             //说明主机继续接收数据则为错误	 													 																		 
    return FALSE;     
    
   /*temp=TWDR;        		   //读取 TWI接收数据
   Stop();          		   //TWI停止
   return temp;*/
} 


void Twi_write_data(void)
{
   uint i;
   for(i=0;i<4;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'0'+i,i);     //写入0-3
   }
   
   for(i=0;i<26;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'A'+i,(4+i)); //写入大写字母表
   }
   
   for(i=0;i<26;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'a'+i,(30+i));//写入小写字母表
   }
   
   for(i=56;i<=255;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'0',i);       //其他写入0
   }
}