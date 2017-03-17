
#ifndef _DS1307_H
#define _DS1307_H

extern uchar time[7];
extern uchar secCount;


void int2_init(void);
void time_show(void);


#endif