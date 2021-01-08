#include "pcf8563.h"

//========================================================================
// ����: д����ֽ�����.
// ����: addr:д��ļĴ�����ַ; p:д�������; number:��Ҫд�����ݸ���.
// ����: none.
//========================================================================
void pcf8563_write_nbyte(uint8 addr, uint8 *p, uint8 number)
{
    hardiic_start();                        //��ʼ�ź�
    hardiic_send_byte(PCF8563_ADDR_W);      //��������д��ַ
    hardiic_wait_ack();
    hardiic_send_byte(addr);                //���ͼĴ�����ַ
    hardiic_wait_ack();
    do
    {
        hardiic_send_byte(*p++);             //��������
        hardiic_wait_ack();
    }while(--number);
    hardiic_stop();                          //����ֹͣ����
}

//========================================================================
// ����: ��ȡ�������.
// ����: addr:��ȡ�ļĴ�����ַ; p:������������; number:��Ҫ�������ݸ���.
// ����: none.
//========================================================================
void pcf8563_read_nbyte(uint8 addr, uint8 *p, uint8 number)
{
    hardiic_start();                        //��ʼ�ź�
    hardiic_send_byte(PCF8563_ADDR_W);      //��������д��ַ
    hardiic_wait_ack();
    hardiic_send_byte(addr);                //���ͼĴ�����ַ
    hardiic_wait_ack();

    hardiic_start();                        //�ظ���ʼ�ź�
    hardiic_send_byte(PCF8563_ADDR_W | 0x01);      //������������ַ
    hardiic_wait_ack();	
    do
    {
        *p = hardiic_read_byte();
        p++;
        if(number != 1) hardiic_ack();     

    }while(--number);
    hardiic_nack(); 
    hardiic_stop();
}

//========================================================================
// ����: ��ʼ��.
// ����: none.
// ����: none.
//========================================================================
void pcf8563_init()
{
    uint8 vlaue = 0;
    hardiic_init();
    pcf8563_write_nbyte(0,&vlaue,1);
}

//========================================================================
// ����: ���������ջ�ȡ����.
// ����: ������.
// ����: none.
//========================================================================
uint8 get_weekday(uint16 year,uint8 month, uint8 day)
{
    int c,y,w;
    uint8 dow;
  	int m = month;
    int d = day;  // �����·ݶ���ݺ��·ݽ��е���
    if(m <= 2)
    {
        year -= 1;
        m += 12;
    }
    c =year / 100; // ȡ�����ǰ��λ
    y =year % 100; // ȡ����ݺ���λ
    w = (int)(c/4) - 2*c + y + (int)(y/4) + (int)(13*(m+1)/5) + d - 1;   // ����̩�չ�ʽ��������
    if((w%7)==0){
       dow=7;
    }else{
      dow=w%7;
    }
    return dow;
}

//========================================================================
// ����: ��ȡrtc����.
// ����: none.
// ����: none.
//========================================================================
void pcf8563_read_rtc(pcf8563_Time *tim)
{
    uint8  tmp[7];

    pcf8563_read_nbyte(2, tmp, 7);

    tim->second = ((tmp[0] >> 4) & 0x07) * 10 + (tmp[0] & 0x0f);    //����
    tim->minute = ((tmp[1] >> 4) & 0x07) * 10 + (tmp[1] & 0x0f);    //����
    tim->hour   = ((tmp[2] >> 4) & 0x03) * 10 + (tmp[2] & 0x0f);    //Сʱ

    tim->day = ((tmp[3] >> 4) & 0x07) * 10 + (tmp[3] & 0x0f);                //��
    tim->weekday = tmp[4] + 1;                                          //����
    tim->month = ((tmp[5] >> 4) & 0x07) * 10 + (tmp[5] & 0x0f);              //��
    tim->year = 2000 + ((tmp[6] >> 4) & 0x07) * 10 + (tmp[6] & 0x0f);        //��
}

//========================================================================
// ����: дrtc����.
// ����: �꣬�£��գ����ڣ�ʱ���֣���.
// ����: none.
//========================================================================
void pcf8563_write_rtc(pcf8563_Time *tim)
{
    uint8  tmp[7];
    tim->year = tim->year - 2000;

    tmp[0] = ((tim->second / 10) << 4) + (tim->second % 10);      //��
    tmp[1] = ((tim->minute / 10) << 4) + (tim->minute % 10);      //��
    tmp[2] = ((tim->hour / 10) << 4) + (tim->hour % 10);          //Сʱ

    tmp[3] = ((tim->day / 10) << 4) + (tim->day % 10);            //��
    tmp[4] = tim->weekday - 1;                                    //����
    tmp[5] = ((tim->month / 10) << 4) + (tim->month % 10);        //��
    tmp[6] = ((tim->year / 10) << 4) + (tim->year % 10);          //��

    pcf8563_write_nbyte(2, tmp, 7);
}
