
#ifndef _USART_INIT_H
#define _USART_INIT_H

extern uchar getData[20];
extern uchar urgencyFlag,daytimeFlag,nightFlag;
extern uchar yellowTime,greenTime,redTime;

void usart_init(void);
void usart_send(uchar data);
void Decide_E(uchar *data);

#endif