#include<iom16v.h>
#include"74LS139.h"

//主干道红灯
main_red()
{
  LS139_1A_L;
  LS139_1B_L;
}

//主干道绿灯
main_green()
{
  LS139_1A_H;
  LS139_1B_L;
}

//主干道黄灯
main_yellow()
{
  LS139_1A_L;
  LS139_1B_H;
}

//主干道灭灯
main_close()
{
  LS139_1A_H;
  LS139_1B_H;
}

//支干道红灯
second_red()
{
  LS139_2A_L;
  LS139_2B_L;
}

//支干道绿灯
second_green()
{
  LS139_2A_H;
  LS139_2B_L;
}

//支干道黄灯
second_yellow()
{
  LS139_2A_L;
  LS139_2B_H;
}

//支干道灭灯
second_close()
{
  LS139_2A_H;
  LS139_2B_H;
}