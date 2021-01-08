/*************  ����֧���빺��˵��    **************
��Ʒ��ҳ��http://tw51.haohaodada.com
�Ա�����������51���ɹ���Ŀǰ������99Ԫ����������׼����149Ԫ
����֧��QQȺһ��1138055784
******************************************/


#include "delay.h"
#include "intrins.h"
//========================================================================
// ����: �ӳ�1΢��.
// ����: none.
// ����: none.
//========================================================================
void delay1us()		//@24.000MHz
{
	uint8 i;

	i = 3;
	while (--i);
}
//========================================================================
// ����: �ӳ�5΢��.
// ����: none.
// ����: none.
//========================================================================
void delay5us()		//@24.000MHz
{
	uint8 i;

	i = 18;
	while (--i);
}

//========================================================================
// ����: �ӳ�10΢��.
// ����: none.
// ����: none.
//========================================================================
void delay10us()		//@24.000MHz
{
	uint8 i;

	i = 38;
	while (--i);
}

//========================================================================
// ����: �ӳ�50΢��.
// ����: none.
// ����: none.
//========================================================================
void delay50us()		//@24.000MHz
{
	uint8 i;

	i = 198;
	while (--i);
}

//========================================================================
// ����: �ӳ�100΢��.
// ����: none.
// ����: none.
//========================================================================
void delay100us()		//@24.000MHz
{
	uint8 i, j;

	_nop_();
	i = 2;
	j = 90;
	do
	{
		while (--j);
	} while (--i);
}

//========================================================================
// ����: �ӳ�1����.
// ����: none.
// ����: none.
//========================================================================
void delay1ms()	//1����@24.000MHz
{
  uint8 i, j;
  _nop_();
  i = 32;
  j = 40;
  do { while (--j);} while (--i);
}

//========================================================================
// ����: �ӳ�ָ������.
// ����: �ӳ�ʱ�䣨0-65535��.
// ����: none.
//========================================================================
void delay(uint16 time)
{
  do { delay1ms();} while (--time);
}

