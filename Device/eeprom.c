#include "eeprom.h"

//========================================================================
// ����: ��ֹEEPROM.
// ����: none.
// ����: none.
//========================================================================
void eeprom_disable(void)        //��ֹ����EEPROM
{
		IAP_CONTR = 0;          //�ر� IAP ����
		IAP_CMD = 0;            //�������Ĵ���
		IAP_TRIG = 0;           //��������Ĵ���
		IAP_ADDRH = 0xff;       //����ַ���õ��� IAP ����
		IAP_ADDRL = 0xff;
}

//========================================================================
// ����: ����EEPROM����.
// ����: none.
// ����: none.
//========================================================================
void eeprom_trig(void)
{
    F0 = EA;    //����ȫ���ж�
    EA = 0;     //��ֹ�ж�, ���ⴥ��������Ч
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;                    //����5AH������A5H��IAP�����Ĵ�����ÿ�ζ���Ҫ���
                                        //����A5H��IAP������������������
                                        //CPU�ȴ�IAP��ɺ󣬲Ż����ִ�г���
    _nop_();
    _nop_();
    EA = F0;    //�ָ�ȫ���ж�
}

//========================================================================
// ����: ����һ������.
// ����: EE_address:  Ҫ������EEPROM�������е�һ���ֽڵ�ַ.
// ����: none.
//========================================================================
void eeprom_sector_erase(uint16 EE_address)
{
    EEPROM_IAP_ENABLE();                       //���õȴ�ʱ�䣬����IAP��������һ�ξ͹�
    EEPROM_IAP_ERASE();                        //�����, ������������������ı�ʱ����������������
                                        //ֻ������������û���ֽڲ�����512�ֽ�/������
                                        //����������һ���ֽڵ�ַ����������ַ��
    IAP_ADDRH = EE_address / 256;       //��������ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
    IAP_ADDRL = EE_address % 256;       //��������ַ���ֽ�
    eeprom_trig();                      //����EEPROM����
    eeprom_disable();                    //��ֹEEPROM����
}

//========================================================================
// ����: ��N���ֽں���.
// ����: EE_address:  Ҫ������EEPROM���׵�ַ.
//       DataAddress: Ҫ�������ݵ�ָ��.
//       length:      Ҫ�����ĳ���
// ����: 0: д����ȷ.  1: д�볤��Ϊ0����.  2: д�����ݴ���.
//========================================================================
void eeprom_read(uint16 EE_address,uint8 *DataAddress,uint8 length)
{
    EEPROM_IAP_ENABLE();                           //���õȴ�ʱ�䣬����IAP��������һ�ξ͹�
    EEPROM_IAP_READ();                             //���ֽڶ���������ı�ʱ����������������
    do
    {
        IAP_ADDRH = EE_address / 256;       //�͵�ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
        IAP_ADDRL = EE_address % 256;       //�͵�ַ���ֽ�
        eeprom_trig();                      //����EEPROM����
        *DataAddress = IAP_DATA;            //��������������
        EE_address++;
        DataAddress++;
    }while(--length);

    eeprom_disable();
}

//========================================================================
// ����: дN���ֽں���.
// ����: EE_address:  Ҫд���EEPROM���׵�ַ.
//       DataAddress: Ҫд�����ݵ�ָ��.
//       length:      Ҫд��ĳ���
// ����: 0: д����ȷ.  1: д�볤��Ϊ0����.  2: д�����ݴ���.
//========================================================================
uint8 eeprom_write(uint16 EE_address,uint8 *DataAddress,uint8 length)
{
    uint8  i;
    uint16 j;
    uint8  *p;
    
    if(length == 0) return 1;   //����Ϊ0����

    EEPROM_IAP_ENABLE();                       //���õȴ�ʱ�䣬����IAP��������һ�ξ͹�
    i = length;
    j = EE_address;
    p = DataAddress;
    EEPROM_IAP_WRITE();                            //�����, ���ֽ�д����
    do
    {
        IAP_ADDRH = EE_address / 256;       //�͵�ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
        IAP_ADDRL = EE_address % 256;       //�͵�ַ���ֽ�
        IAP_DATA  = *DataAddress;           //�����ݵ�IAP_DATA��ֻ�����ݸı�ʱ����������
        eeprom_trig();                      //����EEPROM����
        EE_address++;                       //��һ����ַ
        DataAddress++;                      //��һ������
    }while(--length);                       //ֱ������

    EE_address = j;
    length = i;
    DataAddress = p;
    i = 0;
    EEPROM_IAP_READ();                             //��N���ֽڲ��Ƚ�
    do
    {
        IAP_ADDRH = EE_address / 256;       //�͵�ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
        IAP_ADDRL = EE_address % 256;       //�͵�ַ���ֽ�
        eeprom_trig();                      //����EEPROM����
        if(*DataAddress != IAP_DATA)        //������������Դ���ݱȽ�
        {
            i = 2;
            break;
        }
        EE_address++;
        DataAddress++;
    }while(--length);

    eeprom_disable();
    return i;
}

//========================================================================
// ����: ��EEPROM�ж�����������.
// ����: EE_address:Ҫ��ȡ�ĵ�ַ.
// ����: ������float����.
//========================================================================
float eeprom_read_float(uint16 EE_address)
{
	float dat;
	eeprom_read(EE_address,(uint8 *)&dat,sizeof(float));
	return dat;
}

//========================================================================
// ����: ��EEPROM��д����������.
// ����: EE_address:Ҫ��ȡ�ĵ�ַ; dat:Ҫд���float����.
// ����: none.
//========================================================================
void eeprom_write_float(uint16 EE_address, float dat)
{	
	eeprom_write(EE_address,(uint8 *)&dat,sizeof(float));
}

//========================================================================
// ����: ��EEPROM�ж�int����.
// ����: EE_address:Ҫ��ȡ�ĵ�ַ.
// ����: ������float����.
//========================================================================
int eeprom_read_int(uint16 EE_address)
{
	int dat;
	eeprom_read(EE_address,(uint8 *)&dat,sizeof(int));
	return dat;
}

//========================================================================
// ����: ��EEPROM��дint����.
// ����: EE_address:Ҫ��ȡ�ĵ�ַ; dat:Ҫд���float����.
// ����: none.
//========================================================================
void eeprom_write_int(uint16 EE_address, int dat)
{	
	eeprom_write(EE_address, (uint8 *)&dat,sizeof(int));
}
