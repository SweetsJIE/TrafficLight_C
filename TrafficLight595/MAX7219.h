#ifndef __MAX7219_H
#define __MAX7219_H

//¶¨ÒåMax7219¶Ë¿Ú
#define Max7219_pinCLK_H  PORTC|=(1<<PC5)
#define Max7219_pinCLK_L  PORTC&=~(1<<PC5)
#define Max7219_pinCS_H   PORTC|=(1<<PC7)
#define Max7219_pinCS_L   PORTC&=~(1<<PC7)
#define Max7219_pinDIN_H  PORTC|=(1<<PC6)
#define Max7219_pinDIN_L  PORTC&=~(1<<PC6)

#endif