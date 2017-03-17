NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0054 =     84. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       00A8  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00A8   0E06 =   3590. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __start
       0054  __text_start
       0076  _exit
       0077  _main_red
       007A  _main_green
       007D  _main_yellow
       0080  _main_close
       0083  _second_red
       0086  _second_green
       0089  _second_yellow
       008C  _second_close
       008F  _Int0_button_init
       0094  _Int0_button
       00AA  _delay_1us
       00AC  _delay_nus
       00BA  _delay_1ms
       00C4  _delay_nms
       00D2  _int2_init
       00D5  _int2
       015D  _Read_EEprom
       0176  _Write_EEprom
       018A  _io_init
       0198  _main
       0411  _decode_H
       041B  _decode_L
       0425  _Write_Max7219_byte
       0436  _Write_Max7219
       0443  _Init_MAX7219
       0452  _TWI_init
       0457  _TWI_Write
       0494  _TWI_Read
       04DB  _TWI_Read_1307
       0523  _Twi_write_data
       0569  _usart_init
       0574  _usart_read
       069C  _usart_send
       06A2  _usart_get
       06A6  _HC_595_init
       06AD  _Send_Seg
       06BD  _Send_Dip
       06CD  _Drive_HC595
       06E1  _Write_Data
       06FF  _strncmp
       0713  mod8u
       0715  div8u
       0716  xdiv8u
       072B  empy16s
       073B  pop_xgset00FC
       0742  push_xgsetF0FC
       0744  push_xgset30FC
       0746  push_xgset00FC
       0748  push_xgset003C
       074D  push_xgset300C
       0752  pop_xgset300C
       0757  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0054 =     84. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _S_flag
       0061  _time
       0068  _secCount
       0069  _count
       006A  _k
       006B  _urgencyFlag
       006C  _daytimeFlag
       006D  _nightFlag
       00A3  _seg
       00AF  _dip
       00B4  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   00B4   0019 =     25. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       00B4  __bss_start
       00B4  _Number_L
       00B5  _Number_H
       00B6  _redTime
       00B7  _greenTime
       00B8  _yellowTime
       00B9  _getData
       00CD  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   004C =     76. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
74LS139.o	[ _74LS139.c ]
button.o	[ button.c ]
delay.o	[ delay.c ]
ds1307.o	[ ds1307.c ]
eeprom.o	[ eeprom.c ]
main.o	[ main.c ]
MAX7219.o	[ MAX7219.c ]
timer.o	[ timer.c ]
twi.o	[ twi.c ]
usart.o	[ usart.c ]
HC_595.o	[ HC_595.c ]
<library>	[ strncmp.s, div8u.s, emul16s.s, gpop3.s, gpush.s, gpushx.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

