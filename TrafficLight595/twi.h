
#ifndef _TWI_H
#define _TWI_H

//����ģʽ����״̬��
#define START    	  0x08    //����      
#define RE_START  	  0x10	  //�������� 

//��������ģʽ״̬��
#define MT_SLA_ACK    0x18	  //SLA+W �ѷ���,���յ� ACK    
#define MT_SLA_NOACK  0x20	  //SLA+W �ѷ���,���յ� NOT ACK 	   
#define MT_DATA_ACK   0x28	  //�����ѷ���,���յ� ACK 	 
#define MT_DATA_NOACK 0x30	  //�����ѷ���,���յ� NOT ACK 

//��������ģʽ״̬��
#define MR_SLA_ACK    0x40	  //SLA+R �ѷ���,���յ� ACK	 
#define MR_SLA_NOACK  0x48	  //SLA+R �ѷ���,���յ� NOT ACK 
#define MR_DATA_ACK   0x50	  //�����ѽ���,���յ� ACK    
#define MR_DATA_NOACK 0x58    //�����ѽ���,���յ� NOT ACK	  

//AT24C02C��ַ��ʽΪ 1 0 1 0 A0 A1 A2 R/W 
//ǰ4λ�����̶�,����λ������,���1λ�Ƕ�дָ��λ ,1Ϊ�� ��0Ϊд 
#define RD_AT2402C_ADDR 0xA1   
#define WD_AT2402C_ADDR 0xA0

//DS1307��ַ��ʽΪ     1 1 0 1 0 0 0 R/W 
//ǰ4λ�����̶�,����λ������,���1λ�Ƕ�дָ��λ ,1Ϊ�� ��0Ϊд 
#define RD_DS1307_ADDR 0xD1   
#define WD_DS1307_ADDR 0xD0

//����TWI����(��ģʽд�Ͷ�)
#define Start()      (TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN))    	//���� START �ź� ������TWINT������start
#define Stop()       (TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN))  	//���� STOP �ź�
#define Wait()       {while(!(TWCR&(1<<TWINT)));}               //�ȴ�TWINT ��λ ��TWINT ��λ��ʾSTART �ź��ѷ���
#define Satus()      (TWSR&0xf8)                                //����TWI ״̬�Ĵ���
#define SetAck       (TWCR|=(1<<TWEA))                          //���� ACKӦ��
#define SetNoAck     (TWCR&=~(1<<TWEA))                         //���� Not AckӦ��
#define TWI_READ()   (TWCR=(1<<TWINT)|(1<<TWEN))           		//������TWI����ʽ
#define Write8Bit(x) {TWDR=(x);TWCR=(1<<TWINT)|(1<<TWEN);}      //д���ݵ�TWDR

//����TWI����״̬�ļ���
#define TRUE  0
#define FALSE 1

void TWI_init(void);
uchar TWI_Write(uchar SlaveAddress,uchar Wdata,uchar RegAddress);
uchar TWI_Read(uchar SlaveAddress_W,uchar SlaveAddress_R,uchar RegAddress);
void Twi_write_data(void);



#endif
