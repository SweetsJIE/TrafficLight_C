/********************************************************************
            ����i2c���ⲿe2prom���ж�д����
********************************************************************/
#include <iom16v.h>
#include <macros.h>
#include"twi.h"


void TWI_init(void)
{  
   TWBR=0X0F;      //������
   TWSR=0;         //1��Ƶ
}

uchar TWI_Write(uchar SlaveAddress,uchar Wdata,uchar RegAddress)
{
   Start();      		 	   //TWI����
   Wait();
   if(Satus()!=START) 
   return FALSE;    
   
   Write8Bit(SlaveAddress); //д �ӻ���ַ��д��ʽ
   Wait();
   if(Satus()!=MT_SLA_ACK) 
   return FALSE;     
      
   Write8Bit(RegAddress);  	   //д �ӻ���Ӧ�Ĵ�����ַ
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;        
  
   Write8Bit(Wdata);     	   //д���ݵ� �ӻ���Ӧ�Ĵ���
   Wait();
   if(Satus()!=MT_DATA_ACK) 
   return FALSE;         
   
   Stop();        	 		   //TWIֹͣ
   delay_nms(10);   		   	   //��ʱ
   return TRUE;
}


uchar TWI_Read(uchar SlaveAddress_W,uchar SlaveAddress_R,uchar RegAddress)
{
   uchar temp;
   Start();	   			  	   //TWI����
   Wait();
   //if (Satus()!=START) 
   // return FALSE;        
    
   Write8Bit(SlaveAddress_W); //д �ӻ���ַ��д��ʽ
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //д �ӻ���Ӧ�Ĵ�����ַ
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI��������
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(SlaveAddress_R); //д �ӻ���ַ�Ͷ���ʽ
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //������TWI����ʽ
   Wait();
   if(Satus()!=MR_DATA_NOACK)//����һ����ֹͣ�������� ���������յ����ٽ���Ӧ���ź� ������������յ�Ӧ���ź�
   							  //˵��������������������Ϊ����	 													 																		 
    return FALSE;     
    
   temp=TWDR;        		   //��ȡ TWI��������
   Stop();          		   //TWIֹͣ
   return temp;
} 

uchar TWI_Read_1307(uchar SlaveAddress_W,uchar SlaveAddress_R,uchar RegAddress,uchar *data)
{
   Start();	   			  	   //TWI����
   Wait();
   if (Satus()!=START) 
    return FALSE;        
    
   Write8Bit(SlaveAddress_W); //д �ӻ���ַ��д��ʽ
   Wait(); 
   if (Satus()!=MT_SLA_ACK) 
    return FALSE;        
    
   Write8Bit(RegAddress);      //д �ӻ���Ӧ�Ĵ�����ַ
   Wait();
   if (Satus()!=MT_DATA_ACK) 
    return FALSE;
    
   Start();            	       //TWI��������
   Wait();
   if (Satus()!=RE_START)  
    return FALSE;
    
   Write8Bit(SlaveAddress_R); //д �ӻ���ַ�Ͷ���ʽ
   Wait();
   if(Satus()!=MR_SLA_ACK)  
    return FALSE;      
    
   TWI_READ();          	   //������TWI����ʽ
   Wait();
   if(Satus()!=MR_DATA_NOACK)//����һ����ֹͣ�������� ���������յ����ٽ���Ӧ���ź� ������������յ�Ӧ���ź�						  
                             //˵��������������������Ϊ����	 													 																		 
    return FALSE;     
    
   /*temp=TWDR;        		   //��ȡ TWI��������
   Stop();          		   //TWIֹͣ
   return temp;*/
} 


void Twi_write_data(void)
{
   uint i;
   for(i=0;i<4;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'0'+i,i);     //д��0-3
   }
   
   for(i=0;i<26;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'A'+i,(4+i)); //д���д��ĸ��
   }
   
   for(i=0;i<26;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'a'+i,(30+i));//д��Сд��ĸ��
   }
   
   for(i=56;i<=255;i++)
   {
      TWI_Write(WD_AT2402C_ADDR,'0',i);       //����д��0
   }
}