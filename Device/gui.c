#include "gui.h"

//��Բ��ָ�����
//x��y�������ĵ�
//size:���̴�С
//d:���̷ָ���ӵĸ߶�
void calendar_circle_clock_drawpanel(uint16 x,uint16 y,uint16 size,uint16 d)
{
	uint16 r=size/2;//�õ��뾶
	uint16 sx=x-r;
	uint16 sy=y-r;
	uint16 px0,px1;
	uint16 py0,py1; 
	uint16 i;

	tft_lcd_draw_circle(x, y, r, TFT_LCD_WHITE, 1);
	tft_lcd_draw_circle(x, y, r-4, TFT_LCD_BLACK, 1);

	for(i=0;i<60;i++)   //�����Ӹ�
	{ 
		px0=sx+r+(r-4)*sin((app_pi/30)*i); 
		py0=sy+r-(r-4)*cos((app_pi/30)*i); 
		px1=sx+r+(r-d)*sin((app_pi/30)*i); 
		py1=sy+r-(r-d)*cos((app_pi/30)*i);  
		tft_lcd_draw_line1(px0,py0,px1,py1,0, TFT_LCD_WHITE);
	}
	for(i=0;i<12;i++)   //��Сʱ��
	{ 
		px0=sx+r+(r-5)*sin((app_pi/6)*i); 
		py0=sy+r-(r-5)*cos((app_pi/6)*i); 
		px1=sx+r+(r-d)*sin((app_pi/6)*i); 
		py1=sy+r-(r-d)*cos((app_pi/6)*i);  
		tft_lcd_draw_line1(px0,py0,px1,py1,2, TFT_LCD_YELLOW);
	}
	for(i=0;i<4;i++)    //��3Сʱ��
	{ 
		px0=sx+r+(r-5)*sin((app_pi/2)*i); 
		py0=sy+r-(r-5)*cos((app_pi/2)*i); 
		px1=sx+r+(r-d-3)*sin((app_pi/2)*i); 
		py1=sy+r-(r-d-3)*cos((app_pi/2)*i);  
		tft_lcd_draw_line1(px0,py0,px1,py1,2, TFT_LCD_YELLOW);
	}
	//gui_circle(x,y,d/2,WHITE);		//������Բ
	tft_lcd_draw_circle(x, y, d/2, TFT_LCD_WHITE, 1);
}

//��ʾʱ��
//x,y:�������ĵ�
//size: ���̴�С
//d:���̷ָ���Ӹ߶�
//hour:ʱ��
//min:����
//sec:����
void calendar_circle_clock_showtime(uint16 x,uint16 y,uint16 size,uint16 d,uint8 hour,uint8 min,uint8 sec)
{
	static uint8 oldhour=0;	//���һ�ν���ú�����ʱ������Ϣ
	static uint8 oldmin=0;
	static uint8 oldsec=0;
	float temp;
	uint16 r=size/2;           //�õ��뾶 
	uint16 sx=x-r;
	uint16 sy=y-r;
	uint16 px0,px1;
	uint16 py0,py1;  
	uint8 r1; 
	if(hour>11)hour-=12;
///////////////////////////////////////////////
	//���Сʱ
	r1=d/2+4;
	//�����һ������
	temp=(float)oldmin/60;
	temp+=oldhour;
	px0=sx+r+(r-3*d-7)*sin((app_pi/6)*temp); 
	py0=sy+r-(r-3*d-7)*cos((app_pi/6)*temp); 
	px1=sx+r+r1*sin((app_pi/6)*temp); 
	py1=sy+r-r1*cos((app_pi/6)*temp); 
	tft_lcd_draw_line1(px0,py0,px1,py1,2, TFT_LCD_BLACK);
	//�������
	r1=d/2+3;
	temp=(float)oldsec/60;
	temp+=oldmin;
	//�����һ������
	px0=sx+r+(r-2*d-7)*sin((app_pi/30)*temp); 
	py0=sy+r-(r-2*d-7)*cos((app_pi/30)*temp); 
	px1=sx+r+r1*sin((app_pi/30)*temp); 
	py1=sy+r-r1*cos((app_pi/30)*temp); 
	tft_lcd_draw_line1(px0,py0,px1,py1,1, TFT_LCD_BLACK);
	//�������
	r1=d/2+3;
	//�����һ������
	px0=sx+r+(r-d-7)*sin((app_pi/30)*oldsec); 
	py0=sy+r-(r-d-7)*cos((app_pi/30)*oldsec); 
	px1=sx+r+r1*sin((app_pi/30)*oldsec); 
	py1=sy+r-r1*cos((app_pi/30)*oldsec); 
	tft_lcd_draw_line1(px0,py0,px1,py1,0, TFT_LCD_BLACK);
///////////////////////////////////////////////
	//��ʾСʱ
	r1=d/2+4; 
	//��ʾ�µ�ʱ��
	temp=(float)min/60;
	temp+=hour;
	px0=sx+r+(r-3*d-7)*sin((app_pi/6)*temp); 
	py0=sy+r-(r-3*d-7)*cos((app_pi/6)*temp); 
	px1=sx+r+r1*sin((app_pi/6)*temp); 
	py1=sy+r-r1*cos((app_pi/6)*temp); 
	tft_lcd_draw_line1(px0,py0,px1,py1,2, TFT_LCD_YELLOW);
	//��ʾ����
	r1=d/2+3; 
	temp=(float)sec/60;
	temp+=min;
	//��ʾ�µķ���
	px0=sx+r+(r-2*d-7)*sin((app_pi/30)*temp); 
	py0=sy+r-(r-2*d-7)*cos((app_pi/30)*temp); 
	px1=sx+r+r1*sin((app_pi/30)*temp); 
	py1=sy+r-r1*cos((app_pi/30)*temp); 
	tft_lcd_draw_line1(px0,py0,px1,py1,1, TFT_LCD_GREEN);
	//��ʾ����
	r1=d/2+3;
	//��ʾ�µ�����
	px0=sx+r+(r-d-7)*sin((app_pi/30)*sec); 
	py0=sy+r-(r-d-7)*cos((app_pi/30)*sec); 
	px1=sx+r+r1*sin((app_pi/30)*sec); 
	py1=sy+r-r1*cos((app_pi/30)*sec); 
	tft_lcd_draw_line1(px0,py0,px1,py1,0, TFT_LCD_RED);
	oldhour=hour;	//����ʱ
	oldmin=min;		//�����
	oldsec=sec;		//������
}	    

//��������
//x,y���ĵ�λ��
//size:��ļ��
//d: ��Ĵ�С
void oscilloscope_axis(uint16 x,uint16 y,uint16 size,uint16 d)
{
	uint16 px0,px1;
	uint16 py0,py1;
	uint16 c1 ,c2;

	//��X��
	px0 = x;
	py0 = y + d/2;
	py1 = y - d/2;
	c1 = y;	c2 = y;
	tft_lcd_draw_line1(px0,py0,px0,py1,1, TFT_LCD_WHITE);	//��X�����ĵ�
	while(px0 <= (lcddev.width-size))
	{
		px0 = px0 +size;
		tft_lcd_draw_line1(px0,py0,px0,py1,1, TFT_LCD_WHITE);	//����x����
		while(c1 <= lcddev.height-size*5)
		{
			c1 = c1 + size * 5;
			tft_lcd_draw_circle(px0, c1, 1, TFT_LCD_WHITE, 1);
		}
		while(c2 >= size*5)
		{
			c2 = c2 - size * 5;
			tft_lcd_draw_circle(px0, c2,1, TFT_LCD_WHITE,  1);
			
		}
		c1 = y;
		c2 = y;
	}

	while(px0 >= size){
		px0 = px0 - size;
		tft_lcd_draw_line1(px0,py0,px0,py1,1, TFT_LCD_WHITE);	//����x����
		while(c1 <= lcddev.height-size*5)
		{
			c1 = c1 + size * 5;
			tft_lcd_draw_circle(px0, c1, 1, TFT_LCD_WHITE,  1);
			
		}
		while(c2 >= size*5)
		{
			c2 = c2 - size * 5;
			tft_lcd_draw_circle(px0, c2, 1, TFT_LCD_WHITE, 1);
			
		}
		c1 = y;
		c2 = y;
	}

	//��y��
	py0 = y;
	px0 = x + d/2;
	px1 = x - d/2;
	c1 = x;	c2 = x;
	tft_lcd_draw_line1(px0,py0,px1,py0,1, TFT_LCD_WHITE);	//��Y�����ĵ�
	while(py0 <= lcddev.height-size)
	{
		py0 = py0 +size;
		tft_lcd_draw_line1(px0,py0,px1,py0,1, TFT_LCD_WHITE);	//����Y����
		while(c1 <= lcddev.width-size*5)
		{
			c1 = c1 + size * 5;
			tft_lcd_draw_circle(c1, py0, 1, TFT_LCD_WHITE, 1);
			
		}
		while(c2 >= size*5)
		{	
			c2 = c2 - size * 5;
			tft_lcd_draw_circle(c2, py0, 1, TFT_LCD_WHITE, 1);
		}
		c1 = x;
		c2 = x;
	}

	while(py0 >= size){
		py0 = py0 - size;
		tft_lcd_draw_line1(px0,py0,px1,py0,1, TFT_LCD_WHITE);	//����Y����
		while(c1 <= lcddev.width-size*5)
		{
			c1 = c1 + size * 5;
			tft_lcd_draw_circle(c1, py0, 1, TFT_LCD_WHITE, 1);
			
		}
		while(c2 >= size*5)
		{
			c2 = c2 - size*5;
			tft_lcd_draw_circle(c2, py0, 1, TFT_LCD_WHITE, 1);
		}
		c1 = x;
		c2 = x;
	}
}

//�����Һ���
void oscilloscope_sin()
{
	uint16 i,tem_color;
	int y;
	int k;
	tem_color = _tft_lcd_point_color;
	for(i=0; i<339;i++){
		y = 30*sin(i/20.0);
		_tft_lcd_point_color = TFT_LCD_YELLOW;
		tft_lcd_draw_point((u16)y+161,i);
		tft_lcd_draw_point((u16)y+160,i);
		tft_lcd_draw_point((u16)y+159,i);

		k = 30*cos(i/20.0);
		_tft_lcd_point_color = TFT_LCD_GBLUE;
		tft_lcd_draw_point((u16)k+41,i);
		tft_lcd_draw_point((u16)k+40,i);
		tft_lcd_draw_point((u16)k+39,i);
		delay(10);
	}
	_tft_lcd_point_color = tem_color;
}
