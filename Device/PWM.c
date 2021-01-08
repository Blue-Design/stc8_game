#include "PWM.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM_gpio����
//  @param      pwmch       PWMͨ��
//  @return     void
//  Sample usage:           
//-------------------------------------------------------------------------------------------------------------------
void pwm_set_gpio(PWM_CH pwmch)
{
	switch (pwmch)
	{
		case PWM1P_P10:
		{
			pinMode(P1_0, GPIO_PP);
			break;
		}
		case PWM1N_P11:
		{
			pinMode(P1_1, GPIO_PP);
			break;
		}
		case PWM1P_P20:
		{
			pinMode(P2_0, GPIO_PP);
			break;
		}
		case PWM1N_P21:
		{
			pinMode(P2_1, GPIO_PP);
			break;
		}
		case PWM1P_P60:
		{
			pinMode(P6_0, GPIO_PP);
			break;
		}
		case PWM1N_P61:
		{
			pinMode(P6_1, GPIO_PP);
			break;
		}

		case PWM2P_P12:
		{
			pinMode(P1_2, GPIO_PP);
			break;
		}
		case PWM2N_P13:
		{
			pinMode(P1_3, GPIO_PP);
			break;
		}
		case PWM2P_P22:
		{
			pinMode(P2_2, GPIO_PP);
			break;
		}
		case PWM2N_P23:
		{
			pinMode(P2_3, GPIO_PP);
			break;
		}
		case PWM2P_P62:
		{
			pinMode(P6_2, GPIO_PP);
			break;
		}
		case PWM2N_P63:
		{
			pinMode(P6_3, GPIO_PP);
			break;
		}

		case PWM3P_P14:
		{
			pinMode(P1_4, GPIO_PP);
			break;
		}
		case PWM3N_P15:
		{
			pinMode(P1_5, GPIO_PP);
			break;
		}
		case PWM3P_P24:
		{
			pinMode(P2_4, GPIO_PP);
			break;
		}
		case PWM3N_P25:
		{
			pinMode(P2_5, GPIO_PP);
			break;
		}
		case PWM3P_P64:
		{
			pinMode(P6_4, GPIO_PP);
			break;
		}
		case PWM3N_P65:
		{
			pinMode(P6_5, GPIO_PP);
			break;
		}
		case PWM4P_P16:
		{
			pinMode(P1_6, GPIO_PP);
			break;
		}
		case PWM4N_P17:
		{
			pinMode(P1_7, GPIO_PP);
			break;
		}
		case PWM4P_P26:
		{
			pinMode(P2_6, GPIO_PP);
			break;
		}
		case PWM4N_P27:
		{
			pinMode(P2_7, GPIO_PP);
			break;
		}
		case PWM4P_P66:
		{
			pinMode(P6_6, GPIO_PP);
			break;
		}
		case PWM4N_P67:
		{
			pinMode(P6_7, GPIO_PP);
			break;
		}
		case PWM4P_P34:
		{
			pinMode(P3_4, GPIO_PP);
			break;
		}
		case PWM4N_P33:
		{
			pinMode(P3_3, GPIO_PP);
			break;
		}
		case PWM5_P20:
		{
			pinMode(P2_0, GPIO_PP);
			break;
		}
		case PWM5_P17:
		{
			pinMode(P1_7, GPIO_PP);
			break;
		}
		case PWM5_P00:
		{
			pinMode(P0_0, GPIO_PP);
			break;
		}
		case PWM5_P74:
		{
			pinMode(P7_4, GPIO_PP);
			break;
		}
		case PWM6_P21:
		{
			pinMode(P2_1, GPIO_PP);
			break;
		}
		case PWM6_P54:
		{
			pinMode(P5_4, GPIO_PP);
			break;
		}
		case PWM6_P01:
		{
			pinMode(P0_1, GPIO_PP);
			break;
		}
		case PWM6_P75:
		{
			pinMode(P7_5, GPIO_PP);
			break;
		}
		case PWM7_P22:
		{
			pinMode(P2_2, GPIO_PP);
			break;
		}
		case PWM7_P33:
		{
			pinMode(P3_3, GPIO_PP);
			break;
		}
		case PWM7_P02:
		{
			pinMode(P0_2, GPIO_PP);
			break;
		}
		case PWM7_P76:
		{
			pinMode(P7_6, GPIO_PP);
			break;
		}
		case PWM8_P23:
		{
			pinMode(P2_3, GPIO_PP);
			break;
		}
		case PWM8_P34:
		{
			pinMode(P3_4, GPIO_PP);
			break;
		}
		case PWM8_P03:
		{
			pinMode(P0_3, GPIO_PP);
			break;
		}
		case PWM8_P77:
		{
			pinMode(P7_7, GPIO_PP);
			break;
		}
	}
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM��ʼ��
//  @param      pwmch       PWMͨ��
//  @param      freq        PWMƵ��64Hz-3MHz)
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           
//							pwm_init(PWM0_P00, 100, 5000);     //ͨ��PWM0  ����P0.0  Ƶ��100  ռ�ձ�5000
//							PWM_DUTY_MAXΪ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(PWM_CH pwmch, uint32 freq, uint16 duty)
{

	uint16 match_temp;
	uint16 period_temp;
	uint16 freq_div = 0;

	P_SW2 |= 0x80;

	//GPIO�˿�����
	pwm_set_gpio(pwmch);

	freq_div = ((uint32)(sys_clk / freq)) >> 16;				//��Ƶ

	period_temp = (sys_clk / freq) / (freq_div + 1) - 1;		//����ʱ��

	match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);	//ռ�ձ�

	if (PWM5_P20 <= pwmch)				//PWM5-8
	{

		PWM2_ENO |= (1 << ((2 * ((pwmch >> 4) - 4))));					//ʹ�����
		PWM2_PS |= ((pwmch & 0x03) << ((2 * ((pwmch >> 4) - 4))));		//�����ѡ��

		// ����ͨ�����ʹ�ܺͼ���	
		(*(unsigned char volatile xdata*)(PWM2_CCER1_ADDR + (((pwmch >> 4) - 4) >> 1))) |= (1 << (((pwmch >> 4) & 0x01) * 4));

		//ͨ��ģʽ����
		(*(unsigned char volatile xdata*)(PWM2_CCMR1_ADDR + ((pwmch >> 4) - 4))) |= 0x06 << 4;	//
		(*(unsigned char volatile xdata*)(PWM2_CCMR1_ADDR + ((pwmch >> 4) - 4))) |= 1 << 3;		//PWMģʽ2

		//��������ʱ�䣨���ֽ���д�룩
		//PWM2_ARR = (uint16)period_temp;
		PWM2_ARRH = period_temp >> 8;
		PWM2_ARRL = period_temp;
		//PWM2_ARR=2000;

		//PWMԤ��Ƶ�����ֽ���д�룩
		PWM2_PSCRH = freq_div >> 8;
		PWM2_PSCRL = freq_div;

		//����ռ�ձȣ����ֽ���д�룩
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4) + 1)) = match_temp;
		
		PWM2_BKR = 0x80; 	//ʹ�������
		PWM2_CR1 = 0x01;	//PWM��ʼ��ʱ
	}
	else
	{
		PWM1_ENO |= (1 << (pwmch & 0x01)) << ((pwmch >> 4) * 2);	//ʹ�����	
		PWM1_PS |= ((pwmch & 0x07) >> 1) << ((pwmch >> 4) * 2);    //�����ѡ��


		// ����ͨ�����ʹ�ܺͼ���
		(*(unsigned char volatile xdata*)(PWM1_CCER1_ADDR + (pwmch >> 5))) |= (1 << ((pwmch & 0x01) * 2 + ((pwmch >> 4) & 0x01) * 0x04));


		(*(unsigned char volatile xdata*)(PWM1_CCMR1_ADDR + (pwmch >> 4))) |= 0x06 << 4;	
		(*(unsigned char volatile xdata*)(PWM1_CCMR1_ADDR + (pwmch >> 4))) |= 1 << 3;		//PWMģʽ2

		//��������ʱ�䣨���ֽ���д�룩
		//PWM1_ARR = period_temp;
		PWM1_ARRH = period_temp >> 8;
		PWM1_ARRL = period_temp;

		//PWMԤ��Ƶ�����ֽ���д�룩
		PWM1_PSCRH = freq_div >> 8;
		PWM1_PSCRL = freq_div;

		//����ռ�ձȣ����ֽ���д�룩
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4) + 1)) = match_temp;

		PWM1_BKR = 0x80; 	//ʹ�������
		PWM1_CR1 = 0x01;	//PWM��ʼ��ʱ
	}

	//P_SW2 &= 0x7F;

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM����ռ�ձ�
//  @param      pwmch       PWM����
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           pwm_duty(PWM0_P00, 5000);     //ͨ��PWM0  ����P0.0  ռ�ձ�5000
//							
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty(PWM_CH pwmch, uint16 duty)
{
	uint16 match_temp;

	//	P_SW2 |= 0x80;
	if (PWM5_P20 <= pwmch)				//PWM5-8
	{
		match_temp = PWM2_ARRH;
		match_temp = match_temp << 8;
		match_temp = match_temp + PWM2_ARRL;
		match_temp = match_temp * ((float)duty / PWM_DUTY_MAX);				//ռ�ձ�
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4) + 1)) = match_temp;
	}
	else
	{
		match_temp = PWM1_ARRH;
		match_temp = match_temp << 8;
		match_temp = match_temp + PWM1_ARRL;
		match_temp = match_temp *((float)duty / PWM_DUTY_MAX);				//ռ�ձ�
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4) + 1)) = match_temp;
	}
	//	P_SW2 &= ~0x80;

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM����Ƶ�ʺ�ռ�ձ�
//  @param      pwmch       PWMͨ��
//  @param      freq        PWMƵ��
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           pwm_freq(PWM0_P00, 50, 5000);     //ͨ��PWM0  ����P0.0  Ƶ��50  ռ�ձ�5000
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq_duty(PWM_CH pwmch, uint16 freq, uint16 duty)
{
	uint16 match_temp;
	uint16 period_temp;
	uint16 freq_div = 0;

	freq_div = (sys_clk / freq) >> 15;								//��Ƶ
	period_temp = sys_clk / freq / (freq_div + 1);					//Ƶ��

	//match_temp = period_temp * duty;
	//match_temp = match_temp / PWM_DUTY_MAX;
	match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);	//ռ�ձ�

//	P_SW2 |= 0x80;
	if (PWM5_P20 <= pwmch)				//PWM5-8
	{
		//���ڣ����ֽ���д�룩
		//PWM2_ARR = (uint16)period_temp;
		PWM2_ARRH = period_temp >> 8;
		PWM2_ARRL = period_temp;
		//PWMԤ��Ƶ�����ֽ���д�룩
		PWM2_PSCRH = freq_div>>8;
		PWM2_PSCRL = freq_div;
		//ռ�ձȣ����ֽ���д�룩
		//(*(unsigned int volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4))) = match_temp;
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM2_CCR1_ADDR + 2 * ((pwmch >> 4) - 4) + 1)) = match_temp;
		
	}
	else
	{
		//���ڣ����ֽ���д�룩
		//PWM2_ARR = (uint16)period_temp;
		PWM1_ARRH = period_temp >> 8;
		PWM1_ARRL = period_temp;
		//PWMԤ��Ƶ�����ֽ���д�룩
		PWM1_PSCR = freq_div;
		//ռ�ձȣ����ֽ���д�룩
		//(*(unsigned int volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4))) = match_temp;
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4))) = match_temp >> 8;
		(*(unsigned char volatile xdata*)(PWM1_CCR1_ADDR + 2 * (pwmch >> 4) + 1)) = match_temp;
		
	}
	//	P_SW2 &= ~0x80;
}
