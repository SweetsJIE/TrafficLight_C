#include<iom16v.h>
#include"74LS139.h"

//���ɵ����
main_red()
{
  LS139_1A_L;
  LS139_1B_L;
}

//���ɵ��̵�
main_green()
{
  LS139_1A_H;
  LS139_1B_L;
}

//���ɵ��Ƶ�
main_yellow()
{
  LS139_1A_L;
  LS139_1B_H;
}

//���ɵ����
main_close()
{
  LS139_1A_H;
  LS139_1B_H;
}

//֧�ɵ����
second_red()
{
  LS139_2A_L;
  LS139_2B_L;
}

//֧�ɵ��̵�
second_green()
{
  LS139_2A_H;
  LS139_2B_L;
}

//֧�ɵ��Ƶ�
second_yellow()
{
  LS139_2A_L;
  LS139_2B_H;
}

//֧�ɵ����
second_close()
{
  LS139_2A_H;
  LS139_2B_H;
}