
#include<iom16v.h>
#include"button.h"

uchar S_flag=0;

void Int0_button_init()
{
 	MCUCR = (1<<ISC01);								 		//�½��ش���
	GICR = (1<<INT0);										//ʹ���ⲿ�ж�0
}
#pragma interrupt_handler Int0_button: 2
void Int0_button()
{
 	S_flag=!S_flag;
}