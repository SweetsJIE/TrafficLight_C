CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = main.o MAX7219.o 74LS139.o delay.o ds1307.o twi.o usart.o eeprom.o 

TRAFFIC_LIGHT:	$(FILES)
	$(CC) -o TRAFFIC_LIGHT $(LFLAGS) @TRAFFIC_LIGHT.lk   -lcatmega
main.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\MAX7219.h .\74LS139.h .\button.h .\delay.h .\ds1307.h .\twi.h .\usart.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
MAX7219.o: D:\iccv7avr\include\iom16v.h .\MAX7219.h .\delay.h
MAX7219.o:	MAX7219.c
	$(CC) -c $(CFLAGS) MAX7219.c
74LS139.o: D:\iccv7avr\include\iom16v.h .\74LS139.h
74LS139.o:	74LS139.c
	$(CC) -c $(CFLAGS) 74LS139.c
delay.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h
delay.o:	delay.c
	$(CC) -c $(CFLAGS) delay.c
ds1307.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\twi.h .\usart.h
ds1307.o:	ds1307.c
	$(CC) -c $(CFLAGS) ds1307.c
twi.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\twi.h
twi.o:	twi.c
	$(CC) -c $(CFLAGS) twi.c
usart.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h D:\iccv7avr\include\string.h D:\iccv7avr\include\_const.h .\usart.h .\twi.h
usart.o:	usart.c
	$(CC) -c $(CFLAGS) usart.c
eeprom.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\eeprom.h .\delay.h
eeprom.o:	eeprom.c
	$(CC) -c $(CFLAGS) eeprom.c
