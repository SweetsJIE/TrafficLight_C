
#include <iom16v.h>
#include<macros.h>

void delay_1us(void)                 //1us��ʱ����
{
   NOP();
}

void delay_nus(unsigned int n)       //N us��ʱ����
{
   unsigned int i=0;
     for (i=0;i<n;i++)
         delay_1us();
}
  
void delay_1ms(void)                 //1ms��ʱ����
{
    unsigned int i;
    for (i=0;i<1140;i++);
}
  
void delay_nms(unsigned int n)       //N ms��ʱ����
{
   unsigned int  i=0;
   for (i=0;i<n;i++)
   delay_1ms();
}