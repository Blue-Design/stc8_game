#include "GPIO.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO��������������������
//  @param      pin         ѡ�����ţ�P00-P77��
//  @param      pull        �������������� NOPULL:������ PULL4k:����
//  @return     void
//  Sample usage:           gpio_pull_set(P00,NOPULL);       // ����P0.0����û������������
//-------------------------------------------------------------------------------------------------------------------
void pullMode(PIN_name pin, PULLUP pull)
{
	if (PULL4k == pull)
	{
		(*(unsigned char volatile xdata*)(PxPU_BASE_ADDR + (pin >> 4))) |= (1 << (pin & 0x0F));
	}
	else if (NOPULL == pull)
	{
		(*(unsigned char volatile xdata*)(PxPU_BASE_ADDR + (pin >> 4))) &= ~(1 << (pin & 0x0F));
	}
}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO��������ģʽ
//  @param      pin         ѡ�����ţ�P0_0-P5_4��
//  @param      mode        ����ģʽ GPIO:׼˫���, GPIO_PP:�������, INPUT:��������, GPIO_OD:��©���
//  @return     void
//  Sample usage:           pinMode(P00,GPIO);       // ����P0.0����Ϊ˫��IO
//-------------------------------------------------------------------------------------------------------------------
void pinMode(PIN_name pin, GPIOMODE mode)
{
	if (GPIO == mode)
	{
		if (0x00 == (pin & 0xF0))	//P0
		{
			P0M1 &= ~(1 << (pin & 0xF));
			P0M0 &= ~(1 << (pin & 0xF));
		}
		if (0x10 == (pin & 0xF0))	//P1
		{
			P1M1 &= ~(1 << (pin & 0xF));
			P1M0 &= ~(1 << (pin & 0xF));
		}
		if (0x20 == (pin & 0xF0))	//P2
		{
			P2M1 &= ~(1 << (pin & 0xF));
			P2M0 &= ~(1 << (pin & 0xF));
		}

		if (0x30 == (pin & 0xF0))	//P3
		{
			P3M1 &= ~(1 << (pin & 0xF));
			P3M0 &= ~(1 << (pin & 0xF));
		}
		if (0x40 == (pin & 0xF0))	//P4
		{
			P4M1 &= ~(1 << (pin & 0xF));
			P4M0 &= ~(1 << (pin & 0xF));
		}
		if (0x50 == (pin & 0xF0))	//P5
		{
			P5M1 &= ~(1 << (pin & 0xF));
			P5M0 &= ~(1 << (pin & 0xF));
		}
	}
	else if (GPIO_PP == mode)
	{
		if (0x00 == (pin & 0xF0))	//P0
		{
			P0M1 &= ~(1 << (pin & 0xF));
			P0M0 |= (1 << (pin & 0xF));
		}
		if (0x10 == (pin & 0xF0))	//P1
		{
			P1M1 &= ~(1 << (pin & 0xF));
			P1M0 |= (1 << (pin & 0xF));
		}
		if (0x20 == (pin & 0xF0))	//P2
		{
			P2M1 &= ~(1 << (pin & 0xF));
			P2M0 |= (1 << (pin & 0xF));
		}

		if (0x30 == (pin & 0xF0))	//P3
		{
			P3M1 &= ~(1 << (pin & 0xF));
			P3M0 |= (1 << (pin & 0xF));
		}
		if (0x40 == (pin & 0xF0))	//P4
		{
			P4M1 &= ~(1 << (pin & 0xF));
			P4M0 |= (1 << (pin & 0xF));
		}
		if (0x50 == (pin & 0xF0))	//P5
		{
			P5M1 &= ~(1 << (pin & 0xF));
			P5M0 |= (1 << (pin & 0xF));
		}
	}
	else if (INPUT == mode)
	{
		if (0x00 == (pin & 0xF0))	//P0
		{
			P0M1 |= (1 << (pin & 0xF));
			P0M0 &= ~(1 << (pin & 0xF));
		}
		if (0x10 == (pin & 0xF0))	//P1
		{
			P1M1 |= (1 << (pin & 0xF));
			P1M0 &= ~(1 << (pin & 0xF));
		}
		if (0x20 == (pin & 0xF0))	//P2
		{
			P2M1 |= (1 << (pin & 0xF));
			P2M0 &= ~(1 << (pin & 0xF));
		}

		if (0x30 == (pin & 0xF0))	//P3
		{
			P3M1 |= (1 << (pin & 0xF));
			P3M0 &= ~(1 << (pin & 0xF));
		}
		if (0x40 == (pin & 0xF0))	//P4
		{
			P4M1 |= (1 << (pin & 0xF));
			P4M0 &= ~(1 << (pin & 0xF));
		}
		if (0x50 == (pin & 0xF0))	//P5
		{
			P5M1 |= (1 << (pin & 0xF));
			P5M0 &= ~(1 << (pin & 0xF));
		}
	}
	else if (GPIO_OD == mode)
	{
		if (0x00 == (pin & 0xF0))	//P0
		{
			P0M1 |= (1 << (pin & 0xF));
			P0M0 |= (1 << (pin & 0xF));
		}
		if (0x10 == (pin & 0xF0))	//P1
		{
			P1M1 |= (1 << (pin & 0xF));
			P1M0 |= (1 << (pin & 0xF));
		}
		if (0x20 == (pin & 0xF0))	//P2
		{
			P2M1 |= (1 << (pin & 0xF));
			P2M0 |= (1 << (pin & 0xF));
		}

		if (0x30 == (pin & 0xF0))	//P3
		{
			P3M1 |= (1 << (pin & 0xF));
			P3M0 |= (1 << (pin & 0xF));
		}
		if (0x40 == (pin & 0xF0))	//P4
		{
			P4M1 |= (1 << (pin & 0xF));
			P4M0 |= (1 << (pin & 0xF));
		}
		if (0x50 == (pin & 0xF0))	//P5
		{
			P5M1 |= (1 << (pin & 0xF));
			P5M0 |= (1 << (pin & 0xF));
		}
	}
}
