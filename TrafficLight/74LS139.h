#ifndef __LS139_H
#define __LS139_H


#define LS139_1A_H  PORTA|=(1<<PA0)
#define LS139_1A_L  PORTA&=~(1<<PA0)
#define LS139_1B_H  PORTA|=(1<<PA1)
#define LS139_1B_L  PORTA&=~(1<<PA1)
#define LS139_2A_H  PORTA|=(1<<PA2)
#define LS139_2A_L  PORTA&=~(1<<PA2)
#define LS139_2B_H  PORTA|=(1<<PA3)
#define LS139_2B_L  PORTA&=~(1<<PA3)
#define LS139_G_H   PORTA&=~(1<<PA4)
#define LS139_G_L   PORTA&=~(1<<PA4)

#endif