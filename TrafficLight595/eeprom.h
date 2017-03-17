
#ifndef _EEPROM_H
#define _EEPROM_H


void Write_EEprom(uchar Data,uint address);//写入AVR单片机内部EERPOM函数
uchar Read_EEprom (uint address);          //读出AVR单片机内部EERPOM函数 


#endif