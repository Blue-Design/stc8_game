#include "touch.h"

//========================================================================
// ����: ��ȡX����.
// ����: none.
// ����: ����������.
//========================================================================
uint16 touch_read_raw_x()
{
	uint16 i, j;
	uint16 buf[TOUCH_READ_TIMES];
	uint16 sum=0;
	uint16 temp;
	if(lcddev.id == 0x9341)
	{
		LCD9341_SET_XM_OUT;
		LCD9341_SET_XP_OUT;
		LCD9341_SET_YP_IN;   
		LCD9341_SET_YM_IN;
		LCD9341_TOUCH_XP_PIN = 1;
		LCD9341_TOUCH_YP_PIN = 0;
		LCD9341_TOUCH_YM_PIN = 0;
		LCD9341_TOUCH_XM_PIN = 0;
		adc_init(LCD9341_YP_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);
		for(i=0;i<TOUCH_READ_TIMES;i++)buf[i]=adc_read(LCD9341_YP_ADC_PIN); 		    
		for(i=0;i<TOUCH_READ_TIMES-1; i++)//����
		{
			for(j=i+1;j<TOUCH_READ_TIMES;j++)
			{
				if(buf[i]>buf[j])//��������
				{
					temp=buf[i];
					buf[i]=buf[j];
					buf[j]=temp;
				}
			}
		}	 
		sum=0;
		for(i=TOUCH_LOST_VAL;i<TOUCH_READ_TIMES-TOUCH_LOST_VAL;i++)sum+=buf[i];
		temp=sum/(TOUCH_READ_TIMES-2*TOUCH_LOST_VAL);
		LCD9341_SET_YP_OUT;
		LCD9341_SET_YM_OUT;
		return temp;
	}
	else
	{
		SM245_SET_XM_OUT;
		SM245_SET_XP_OUT;
		SM245_SET_YP_IN;   
		SM245_SET_YM_IN;
		SM245_TOUCH_XP_PIN = 1;
		SM245_TOUCH_YP_PIN = 0;
		SM245_TOUCH_YM_PIN = 0;
		SM245_TOUCH_XM_PIN = 0;
		adc_init(SM245_YP_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);
		for(i=0;i<TOUCH_READ_TIMES;i++)buf[i]=adc_read(SM245_YP_ADC_PIN); 		    
		for(i=0;i<TOUCH_READ_TIMES-1; i++)//����
		{
			for(j=i+1;j<TOUCH_READ_TIMES;j++)
			{
				if(buf[i]>buf[j])//��������
				{
					temp=buf[i];
					buf[i]=buf[j];
					buf[j]=temp;
				}
			}
		}	 
		sum=0;
		for(i=TOUCH_LOST_VAL;i<TOUCH_READ_TIMES-TOUCH_LOST_VAL;i++)sum+=buf[i];
		temp=sum/(TOUCH_READ_TIMES-2*TOUCH_LOST_VAL);
		SM245_SET_YP_OUT;
		SM245_SET_YM_OUT;
		return temp;
	}
}

//========================================================================
// ����: ��ȡY����.
// ����: none.
// ����: ����������.
//========================================================================
uint16 touch_read_raw_y()
{
	uint16 i, j;
	uint16 buf[TOUCH_READ_TIMES];
	uint16 sum=0;
	uint16 temp;
	if(lcddev.id == 0x9341)
	{
		LCD9341_SET_YP_OUT;
		LCD9341_SET_YM_OUT;
		LCD9341_SET_XP_IN;   
		LCD9341_SET_XM_IN;
		LCD9341_TOUCH_YP_PIN = 1;
		LCD9341_TOUCH_YM_PIN = 0;
		LCD9341_TOUCH_XP_PIN = 0;
		LCD9341_TOUCH_XM_PIN = 0;
	
		adc_init(LCD9341_XM_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);

		for(i=0;i<TOUCH_READ_TIMES;i++)buf[i]=adc_read(LCD9341_XM_ADC_PIN); 		    
		for(i=0;i<TOUCH_READ_TIMES-1; i++)//����
		{
			for(j=i+1;j<TOUCH_READ_TIMES;j++)
			{
				if(buf[i]>buf[j])//��������
				{
					temp=buf[i];
					buf[i]=buf[j];
					buf[j]=temp;
				}
			}
		}	 
		sum=0;
		for(i=TOUCH_LOST_VAL;i<TOUCH_READ_TIMES-TOUCH_LOST_VAL;i++)sum+=buf[i];
		temp=sum/(TOUCH_READ_TIMES-2*TOUCH_LOST_VAL);
		LCD9341_SET_XM_OUT;
		LCD9341_SET_XP_OUT;
		return temp;
	}
	else
	{
		SM245_SET_YP_OUT;
		SM245_SET_YM_OUT;
		SM245_SET_XP_IN;   
		SM245_SET_XM_IN;
		SM245_TOUCH_YP_PIN = 1;
		SM245_TOUCH_YM_PIN = 0;
		SM245_TOUCH_XP_PIN = 0;
		SM245_TOUCH_XM_PIN = 0;
	
		adc_init(SM245_XM_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);

		for(i=0;i<TOUCH_READ_TIMES;i++)buf[i]=adc_read(SM245_XM_ADC_PIN); 		    
		for(i=0;i<TOUCH_READ_TIMES-1; i++)//����
		{
			for(j=i+1;j<TOUCH_READ_TIMES;j++)
			{
				if(buf[i]>buf[j])//��������
				{
					temp=buf[i];
					buf[i]=buf[j];
					buf[j]=temp;
				}
			}
		}	 
		sum=0;
		for(i=TOUCH_LOST_VAL;i<TOUCH_READ_TIMES-TOUCH_LOST_VAL;i++)sum+=buf[i];
		temp=sum/(TOUCH_READ_TIMES-2*TOUCH_LOST_VAL);
		SM245_SET_XM_OUT;
		SM245_SET_XP_OUT;
		return temp;
	}
}

//========================================================================
// ����: ��ȡ������ѹ��ֵ.
// ����: none.
// ����: ������ѹ��ֵ.
//========================================================================
uint16 touch_read_pressure()
{
    int z1,z2;
	if(lcddev.id == 0x9341)
	{
		LCD9341_SET_XP_OUT;
		LCD9341_SET_YM_OUT;
		LCD9341_SET_XM_IN;
		LCD9341_SET_YP_IN;
		LCD9341_TOUCH_XP_PIN = 0;
		LCD9341_TOUCH_YM_PIN = 1; 
		LCD9341_TOUCH_XM_PIN = 0;
		LCD9341_TOUCH_YP_PIN = 0;

		adc_init(LCD9341_XM_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);
		adc_init(LCD9341_YP_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);

		z1 = adc_read(LCD9341_XM_ADC_PIN); 
		z2 = adc_read(LCD9341_YP_ADC_PIN);

		LCD9341_SET_XM_OUT;
		LCD9341_SET_YP_OUT;
		LCD9341_TOUCH_YP_PIN = 1;
		LCD9341_TOUCH_XM_PIN = 1;
		return (4095 - (z2-z1));
	}
	else
	{
		SM245_SET_XP_OUT;
		SM245_SET_YM_OUT;
		SM245_SET_XM_IN;
		SM245_SET_YP_IN;
		SM245_TOUCH_XP_PIN = 0;
		SM245_TOUCH_YM_PIN = 1; 
		SM245_TOUCH_XM_PIN = 0;
		SM245_TOUCH_YP_PIN = 0;

		adc_init(SM245_XM_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);
		adc_init(SM245_YP_ADC_PIN, ADC_SYSclk_DIV_2, ADC_12BIT);

		z1 = adc_read(SM245_XM_ADC_PIN); 
		z2 = adc_read(SM245_YP_ADC_PIN);

		SM245_SET_XM_OUT;
		SM245_SET_YP_OUT;
		SM245_TOUCH_YP_PIN = 1;
		SM245_TOUCH_XM_PIN = 1;
		return (4095 - (z2-z1));
	}
}

//========================================================================
// ����: ͨ��2�β������õ���׼ȷ������ֵ.
// ����: x,y:�����õ�����������.
// ����: �����50���ڷ���1�����򷵻�0.
//========================================================================
#define ERR_RANGE 	50      //��Χ 
uint8 tp_read_xy2(uint16 *x,uint16 *y) 
{
	uint16 x1,y1;
 	uint16 x2,y2;

	x1 = touch_read_raw_x();
	y1 = touch_read_raw_y();
	x2 = touch_read_raw_x();
	y2 = touch_read_raw_y();

    if(((x2<=x1&&x1<x2+ERR_RANGE)||(x1<=x2&&x2<x1+ERR_RANGE))//ǰ��2�β��������50����
    &&((y2<=y1&&y1<y2+ERR_RANGE)||(y1<=y2&&y2<y1+ERR_RANGE)))
    {
        *x=(x1+x2)/2;
        *y=(y1+y2)/2;
        return 1;
    }else return 0;	  
} 

//========================================================================
// ����: ��һ��������.
// ����: x,y:����; color:��ɫֵ.
// ����: none.
//========================================================================
void tp_drow_touch_point(uint16 x,uint16 y,uint16 color)
{
	_tft_lcd_point_color = color;
	tft_lcd_draw_line(x-12,y,x+13,y,color);    //����
	tft_lcd_draw_line(x,y-12,x,y+13,color);    //����
	tft_lcd_draw_point(x+1,y+1);
	tft_lcd_draw_point(x-1,y+1);
	tft_lcd_draw_point(x+1,y-1);
	tft_lcd_draw_point(x-1,y-1);
	tft_lcd_draw_circle(x,y,6,color,0);         //������Ȧ
}

//������������
typedef struct
{		
	uint16 x;      	
	uint16 y;		
	uint8  sta;	              		
    /////////////////////������У׼����//////////////////////								
	float xfac;					
	float yfac;
	int xoff;
	int yoff;	   

	uint8 touchtype;	//��Ļ����
}_m_tp_dev;

_m_tp_dev tp_dev=
{
	0,
	0, 
	0,
	0,
	0,
	0,	  	 		
	0,
	0	  	 		
};

//========================================================================
// ����: ����У׼����.
// ����: none.
// ����: none.
//========================================================================
void touch_adjust()
{
	uint16 pos_temp[4][2];//���껺��ֵ
	uint8  cnt=0;	
	uint16 d1,d2;
	uint32 tem1,tem2;
	float fac; 	
	uint16 outtime=0;
 	cnt=0;				
	_tft_lcd_point_color=TFT_LCD_BLUE;
	_tft_lcd_back_color =TFT_LCD_WHITE;
	tft_lcd_clear(TFT_LCD_WHITE);   //���� 
	_tft_lcd_point_color=TFT_LCD_RED;    //��ɫ
	tft_lcd_clear(TFT_LCD_WHITE);   //����   
	_tft_lcd_point_color=TFT_LCD_BLACK;
	tft_lcd_show_string(70,40,"touch adjust",TFT_LCD_RED,TFT_LCD_WHITE,16,1);//��ʾ��ʾ��Ϣ
	tp_drow_touch_point(20,20,TFT_LCD_RED);     //����1
	tp_dev.sta=0;       //���������ź� 
	tp_dev.xfac=0;      //xfac���У׼��־	
    while(1)            //�������10sû�а��£����Զ��˳�
    {
        if( tp_read_xy2(&tp_dev.x,&tp_dev.y) && touch_read_pressure() > 100)     //�����а�������
        {
            outtime = 0;
          	tp_dev.sta=1;       //��ǰ����Ѿ����������

			if(lcddev.id == 0x9341)
			{
				pos_temp[cnt][0] = tp_dev.y;
				pos_temp[cnt][1] = tp_dev.x; 		
			}
			else if(lcddev.id == 0x9340)
			{
				pos_temp[cnt][0] = tp_dev.y;
				pos_temp[cnt][1] = tp_dev.x; 
			}
			else if(tp_dev.touchtype == 0)
			{
				pos_temp[cnt][0] = 4095 - tp_dev.y;
				pos_temp[cnt][1] = 4095 - tp_dev.x; 
			}
			else if(tp_dev.touchtype == 1)
			{
				pos_temp[cnt][0] = tp_dev.y;
				pos_temp[cnt][1] = tp_dev.x; 
			}
            cnt++;
            switch(cnt)
			{			   
				case 1:						 
					tp_drow_touch_point(20,20,TFT_LCD_WHITE);				//�����1
					tp_drow_touch_point(lcddev.width-20,20,TFT_LCD_RED);	//����2
					break;
				case 2:
 					tp_drow_touch_point(lcddev.width-20,20,TFT_LCD_WHITE);	//�����2
					tp_drow_touch_point(20,lcddev.height-20,TFT_LCD_RED);	//����3
					break;
				case 3:
 					tp_drow_touch_point(20,lcddev.height-20,TFT_LCD_WHITE);			//�����3
 					tp_drow_touch_point(lcddev.width-20,lcddev.height-20,TFT_LCD_RED);	//����4
					break;
				case 4:	 //ȫ��4�����Ѿ��õ�
	    		    //�Ա����
					tem1=fabs(pos_temp[0][0]-pos_temp[1][0]);//x1-x2
					tem2=fabs(pos_temp[0][1]-pos_temp[1][1]);//y1-y2
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);     //�õ�1��2�ľ���
					
					tem1=fabs(pos_temp[2][0]-pos_temp[3][0]);//x3-x4
					tem2=fabs(pos_temp[2][1]-pos_temp[3][1]);//y3-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�3��4�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05||d1==0||d2==0)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,TFT_LCD_WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,TFT_LCD_RED);								//����һ 
 						continue;
					}
					tem1=fabs(pos_temp[0][0]-pos_temp[2][0]);    //x1-x3
					tem2=fabs(pos_temp[0][1]-pos_temp[2][1]);    //y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//�õ�1��3�ľ���
					
					tem1=fabs(pos_temp[1][0]-pos_temp[3][0]);//x2-x4
					tem2=fabs(pos_temp[1][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�2��4�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,TFT_LCD_WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,TFT_LCD_RED);								//����1
						continue;
					}//��ȷ��
								   
					//�Խ������
					tem1=fabs(pos_temp[1][0]-pos_temp[2][0]);//x1-x3
					tem2=fabs(pos_temp[1][1]-pos_temp[2][1]);//y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);    //�õ�1��4�ľ���
	
					tem1=fabs(pos_temp[0][0]-pos_temp[3][0]);//x2-x4
					tem2=fabs(pos_temp[0][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//�õ�2��3�ľ���
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//���ϸ�
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,TFT_LCD_WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,TFT_LCD_RED);								//����1
						continue;
					}//��ȷ��
					//������
					tp_dev.xfac=(float)(lcddev.width-40)/(pos_temp[1][0]-pos_temp[0][0]);//�õ�xfac		 
					tp_dev.xoff=(lcddev.width-tp_dev.xfac*(pos_temp[1][0]+pos_temp[0][0]))/2;//�õ�xoff
						  
					tp_dev.yfac=(float)(lcddev.height-40)/(pos_temp[2][1]-pos_temp[0][1]);//�õ�yfac
					tp_dev.yoff=(lcddev.height-tp_dev.yfac*(pos_temp[2][1]+pos_temp[0][1]))/2;//�õ�yoff  
					if(fabs(tp_dev.xfac)>2||fabs(tp_dev.yfac)>2)//������Ԥ����෴��
					{
						cnt=0;
 				    	tp_drow_touch_point(lcddev.width-20,lcddev.height-20,TFT_LCD_WHITE);	//�����4
   	 					tp_drow_touch_point(20,20,TFT_LCD_RED);								//����1
						tft_lcd_show_string(40,26,"TP Need readjust!",TFT_LCD_RED,TFT_LCD_WHITE,16,1);
						if(lcddev.id == 0x9340)
						{
							lcddev.id = 0;
							tp_dev.touchtype = 0;
						}
						//tp_dev.touchtype=!tp_dev.touchtype;//�޸Ĵ�������		    
						continue;
					}		
					_tft_lcd_point_color=TFT_LCD_BLUE;
					tft_lcd_clear(TFT_LCD_WHITE);//����
					tft_lcd_show_string(35,110,"Touch Screen Adjust OK!",TFT_LCD_RED,TFT_LCD_WHITE,16,1);//У�����
					delay(200);
					//��У׼����д�봥����
                    eeprom_sector_erase(TOUCH_EEPROM_ADDR);
    				eeprom_write_float(TOUCH_EEPROM_ADDR,tp_dev.xfac);
					eeprom_write_float(TOUCH_EEPROM_ADDR+sizeof(float),tp_dev.yfac);
					eeprom_write_int(TOUCH_EEPROM_ADDR+2*sizeof(float),tp_dev.xoff);
					eeprom_write_int(TOUCH_EEPROM_ADDR+2*sizeof(float)+sizeof(int),tp_dev.yoff);

 					tft_lcd_clear(TFT_LCD_WHITE);//����  
					return;//У�����				 
			}
            while(touch_read_pressure() > 100);
		}
		delay(10);
		outtime++;
		if(outtime>1000)
		{
            tft_lcd_clear(TFT_LCD_WHITE);
			//�Ӵ洢���еõ�У׼����
            tp_dev.xfac = eeprom_read_float(TOUCH_EEPROM_ADDR);
			tp_dev.yfac = eeprom_read_float(TOUCH_EEPROM_ADDR+sizeof(float));
			tp_dev.xoff = eeprom_read_int(TOUCH_EEPROM_ADDR+2*sizeof(float));
			tp_dev.yoff = eeprom_read_int(TOUCH_EEPROM_ADDR+2*sizeof(float)+sizeof(int));
			return;
	 	} 
 	}            
}

//========================================================================
// ����: �����ĳ�ʼ������.
// ����: t:0,������У׼����;����ֵ:����У׼����.
// ����: none.
//========================================================================
void touch_init(uint8 t)
{
	if(t == 0)	//ֱ�Ӵ�eeprom�л�ȡУ׼����
	{
		tp_dev.xfac = eeprom_read_float(TOUCH_EEPROM_ADDR);
		tp_dev.yfac = eeprom_read_float(TOUCH_EEPROM_ADDR+sizeof(float));
		tp_dev.xoff = eeprom_read_int(TOUCH_EEPROM_ADDR+2*sizeof(float));
		tp_dev.yoff = eeprom_read_int(TOUCH_EEPROM_ADDR+2*sizeof(float)+sizeof(int));		
	}else{
		touch_adjust();	//����У׼����
	}
}

//========================================================================
// ����: ��ȡ�����������Լ�ѹ��ֵ.
// ����: none.
// ����: ����������.
//========================================================================
void touch_get_point(uint16 *tspoint)
{
 	uint16 x,y;
	tp_read_xy2(&x,&y);
	if(lcddev.id == 0x9341)
	{
		//��ȡX����
		tspoint[0] = tp_dev.xfac*(y)+tp_dev.xoff;	
		//��ȡY����
		tspoint[1] = tp_dev.yfac*(x)+tp_dev.yoff;	
	}
	else if(lcddev.id == 0x9340)
	{
		//��ȡX����
		tspoint[0] = tp_dev.xfac*(y)+tp_dev.xoff;	
		//��ȡY����
		tspoint[1] = tp_dev.yfac*(x)+tp_dev.yoff;	
	}

	else if(tp_dev.touchtype == 0)
	{
		//��ȡX����
		tspoint[0] = tp_dev.xfac*(4095 - y)+tp_dev.xoff;	
		//��ȡY����
		tspoint[1] = tp_dev.yfac*(4095 - x)+tp_dev.yoff;
	}
	else if(tp_dev.touchtype == 1)
	{
		//��ȡX����
		tspoint[0] = tp_dev.xfac*(4095 - x)+tp_dev.xoff;	
		//��ȡY����
		tspoint[1] = tp_dev.yfac*(4095 - y)+tp_dev.yoff;	
	}

    //��ȡѹ��
    tspoint[2] = touch_read_pressure();
}

//========================================================================
// ����: ��ȡ������x����.
// ����: none.
// ����: ����������.
//========================================================================
uint16 touch_read_x()	//��ȡX������
{
	uint16 x,y;
	tp_read_xy2(&x,&y);
	if(lcddev.id == 0x9341)
	{
		//��ȡX����
		return (tp_dev.xfac*(y)+tp_dev.xoff);	
	}
	else if(tp_dev.touchtype == 0)
	{
		//��ȡX����
		return (tp_dev.xfac*(4095 - y)+tp_dev.xoff);	
	}
	else if(tp_dev.touchtype == 1)
	{
		//��ȡX����
		return (tp_dev.xfac*(4095 - x)+tp_dev.xoff);		
	}
	return 0;
}

//========================================================================
// ����: ��ȡ������y����.
// ����: none.
// ����: ����������.
//========================================================================
uint16 touch_read_y()	//��ȡY������
{
	uint16 x,y;
	tp_read_xy2(&x,&y);
	if(lcddev.id == 0x9341)
	{
		//��ȡY����
		return (tp_dev.yfac*(x)+tp_dev.yoff);	
	}
	else if(tp_dev.touchtype == 0)
	{	
		//��ȡY����
		return (tp_dev.yfac*(4095 - x)+tp_dev.yoff);
	}
	else if(tp_dev.touchtype == 1)
	{
		//��ȡY����
		return (tp_dev.yfac*(4095 - y)+tp_dev.yoff);		
	}
	return 0;
}
