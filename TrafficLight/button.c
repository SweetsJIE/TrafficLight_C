
#include<iom16v.h>
#include"button.h"

uchar S_flag=0;

void Int0_button_init()
{
 	MCUCR = (1<<ISC01);								 		//下降沿触发
	GICR = (1<<INT0);										//使能外部中断0
}
#pragma interrupt_handler Int0_button: 2
void Int0_button()
{
 	S_flag=!S_flag;
}