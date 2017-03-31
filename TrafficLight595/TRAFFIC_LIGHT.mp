NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0055 =     85. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       00A9  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00AA   0E6E =   3694. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0055  __start
       0055  __text_start
       0077  _exit
       0078  _main_red
       007B  _main_green
       007E  _main_yellow
       0081  _main_close
       0084  _second_red
       0087  _second_green
       008A  _second_yellow
       008D  _second_close
       0090  _Int0_button_init
       0095  _Int0_button
       00AB  _delay_1us
       00AD  _delay_nus
       00BB  _delay_1ms
       00C5  _delay_nms
       00D3  _int2_init
       00D6  _int2
       015E  _Read_EEprom
       0177  _Write_EEprom
       018B  _io_init
       0199  _main
       0446  _decode_H
       0450  _decode_L
       045A  _Write_Max7219_byte
       046B  _Write_Max7219
       0478  _Init_MAX7219
       0487  _TWI_init
       048C  _TWI_Write
       04C9  _TWI_Read
       0510  _TWI_Read_1307
       0558  _Twi_write_data
       059E  _usart_init
       05A9  _usart_read
       06D1  _usart_send
       06D7  _usart_get
       06DB  _HC_595_init
       06E2  _Send_Seg
       06F2  _Send_Dip
       0702  _Drive_HC595
       0716  _Write_Data
       0734  _strncmp
       0748  mod8u
       074A  div8u
       074B  xdiv8u
       0760  empy16s
       0770  pop_xgset00FC
       0777  push_xgsetF0FC
       0779  push_xgset30FC
       077B  push_xgset00FC
       077D  push_xgset003C
       0782  push_xgset300C
       0787  pop_xgset300C
       078C  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0055 =     85. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _S_flag
       0060  __data_start
       0061  _time
       0068  _secCount
       0069  _count
       006A  _i
       006B  _k
       006C  _urgencyFlag
       006D  _daytimeFlag
       006E  _nightFlag
       00A4  _seg
       00B0  _dip
       00B5  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   00B5   0019 =     25. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       00B5  __bss_start
       00B5  _Number_L
       00B6  _Number_H
       00B7  _redTime
       00B8  _greenTime
       00B9  _yellowTime
       00BA  _getData
       00CE  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   004C =     76. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
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

