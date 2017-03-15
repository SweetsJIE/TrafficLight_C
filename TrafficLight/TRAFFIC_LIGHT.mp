NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0042 =     66. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0096  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0096   0CF6 =   3318. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       004B  __text_start
       004B  __start
       006D  _exit
       006E  _io_init
       007C  _main
       0308  _decode_H
       0312  _decode_L
       031C  _Write_Max7219_byte
       032D  _Write_Max7219
       033A  _Init_MAX7219
       0349  _main_red
       034C  _main_green
       034F  _main_yellow
       0352  _main_close
       0355  _second_red
       0358  _second_green
       035B  _second_yellow
       035E  _second_close
       0361  _delay_1us
       0363  _delay_nus
       0371  _delay_1ms
       037B  _delay_nms
       0389  _int2_init
       038C  _int2
       03F4  _TWI_init
       03F9  _TWI_Write
       0436  _TWI_Read
       047D  _TWI_Read_1307
       04C5  _Twi_write_data
       050B  _usart_init
       0516  _usart_read
       0637  _usart_send
       063D  _usart_get
       0641  _Read_EEprom
       065A  _Write_EEprom
       066E  _strncmp
       0682  mod8u
       0684  div8u
       0685  xdiv8u
       069A  empy16s
       06AA  pop_xgset00FC
       06B1  push_xgsetF0FC
       06B3  push_xgset30FC
       06B5  push_xgset00FC
       06B7  push_xgset003C
       06BC  push_xgset300C
       06C1  pop_xgset300C
       06C6  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0042 =     66. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _count
       0060  __data_start
       0061  _time
       0068  _secCount
       0069  _k
       006A  _urgencyFlag
       006B  _daytimeFlag
       006C  _nightFlag
       00A2  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   00A2   0019 =     25. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       00A2  __bss_start
       00A2  _Number_L
       00A3  _Number_H
       00A4  _redTime
       00A5  _greenTime
       00A6  _yellowTime
       00A7  _getData
       00BB  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   004C =     76. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
MAX7219.o	[ MAX7219.c ]
74LS139.o	[ _74LS139.c ]
delay.o	[ delay.c ]
ds1307.o	[ ds1307.c ]
twi.o	[ twi.c ]
usart.o	[ usart.c ]
eeprom.o	[ eeprom.c ]
<library>	[ strncmp.s, div8u.s, emul16s.s, gpop3.s, gpush.s, gpushx.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

