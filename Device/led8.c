#include "led8.h"
#include "sys.h"

//========================================================================
// ����: ʹ��LED.
// ����: none.
// ����: none.
//========================================================================
void led8_enable()
{
    LED8_CONTROL_MODE;//�������
    LED8_CONTROL_PIN = 0;
}

//========================================================================
// ����: ����LED.
// ����: none.
// ����: none.
//========================================================================
void led8_disable()
{
    LED8_CONTROL_MODE;//�������
    LED8_CONTROL_PIN = 1;
}

void led8_run(){
    static uint8 led_b = 0xfe;
    static uint8 flag = 0;
    if(led_b == 0x7f){
        flag = !flag;
    }else if(led_b == 0xfe && flag){
        flag = !flag;
    }
    LED8 = led_b;
    led_b = !flag?(led_b<<1)|0x01:(led_b>>1)|0x80;
}
