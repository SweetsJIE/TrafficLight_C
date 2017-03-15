#include<iom16v.h>
#include"MAX7219.h"
#include"delay.h"


//--------------------------------------------
//���ܣ���MAX7219(U3)д���ֽ�
//��ڲ�����DATA 
//���ڲ�������
//˵����
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
//���ܣ���MAX7219д������
//��ڲ�����address��dat
//���ڲ�������
//˵����
void Write_Max7219(uchar address,uchar dat)
{ 
     Max7219_pinCS_L;
	 Write_Max7219_byte(address);           //д���ַ��������ܱ��
     Write_Max7219_byte(dat);               //д�����ݣ����������ʾ���� 
	 Max7219_pinCS_H;                        
}

void Init_MAX7219(void)
{
 Write_Max7219(0x09, 0xff);       //���뷽ʽ��BCD��
 Write_Max7219(0x0a, 0x03);       //����
 Write_Max7219(0x0b, 0x07);       //ɨ����ޣ�4���������ʾ
 Write_Max7219(0x0c, 0x01);       //����ģʽ��0����ͨģʽ��1
 Write_Max7219(0x0f, 0x01);       //��ʾ���ԣ�1�����Խ�����������ʾ��0
}
