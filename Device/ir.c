#include "ir.h"

bit _b_ir_press;               //������ձ�־
xdata uint8  _ir_code;           //�������
xdata uint16 _user_code;          //�û���

//========================================================================
// ����: ������ʱ����(�ڲ�����)
// ����: time:��ʱ��ʱ�䣨����ȷ��.
// ����: none.
//========================================================================
static void ir_delayus(uint16 time)
{
    uint8 i;
    do{
        i = 6;
        while (--i);
    }while(time--);
}

//========================================================================
// ����: ���ⷢ��ʹ��(�ڲ�����)
// ����: fre:���ⷢ��Ƶ�ʣ�kHz��.
// ����: none.
//========================================================================
static void enable_ir_out(uint8 fre)
{  
    IR_SEND_PIN_OUT;
    pwm_init(IR_SEND_PWM, (fre*1000L), 0);
}

//========================================================================
// ����: ���ⷢ���ֹ(�ڲ�����)
// ����: none.
// ����: none.
//========================================================================
static void disable_ir_out()
{
    IR_SEND_PIN_INIT;
}

//========================================================================
// ����: ���ⷢ���ز��ź�(�ڲ�����)
// ����: time:�����ʱ��.
// ����: none.
//========================================================================
static void ir_tx_mark(uint16 time)
{
    // ռ�ձ� 1/3
    pwm_duty(IR_SEND_PWM, PWM_DUTY_MAX/3*2);
    ir_delayus(time);
}

//========================================================================
// ����: ���ⷢ������ź�(�ڲ�����)
// ����: time:�����ʱ��.
// ����: none.
//========================================================================
static void ir_tx_space(uint16 time)
{
    pwm_duty(IR_SEND_PWM, PWM_DUTY_MAX);
    ir_delayus(time);
}

//========================================================================
// ����: ���ⷢ��NEC��
// ����: address:���͵ĵ�ַ ;command: ���͵�����.
// ����: none.
//========================================================================
void ir_send_nec(uint8 address, uint8 command)
{
    uint8 i;
    uint8 inverse_address = ~address;
    uint8 inverse_command = ~command;

    // 1. �ز�����
    enable_ir_out(38);
    // 2. ����������
    ir_tx_mark(NEC_HDR_MARK);
    ir_tx_space(NEC_HDR_SPACE);
    // 3. ���͵�ַ
    for (i=0;i<8;i++)
    {
        if (address & 0x01) 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ONE_SPACE);
        } 
        else 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ZERO_SPACE);
        }
        address >>= 1;
    }
    // 4. ���͵�ַ����
    
    for (i=0;i<8;i++)
    {
        if (inverse_address & 0x01) 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ONE_SPACE);
        } 
        else 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ZERO_SPACE);
        }
        inverse_address >>= 1;
    }

    // 5. ��������
    for (i=0;i<8;i++)
    {
        if (command & 0x01) 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ONE_SPACE);
        } 
        else 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ZERO_SPACE);
        }
        command >>= 1;
    }

    // 6. ���������
    for (i=0;i<8;i++)
    {
        if ((inverse_command) & 0x01) 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ONE_SPACE);
        } 
        else 
        {
            ir_tx_mark(NEC_BIT_MARK);
            ir_tx_space(NEC_ZERO_SPACE);
        }
        inverse_command >>= 1;
    }
    ir_tx_mark(NEC_BIT_MARK);
    ir_tx_space(1);// Ϊ0��������ѭ��
    disable_ir_out();
}

//========================================================================
// ����: ������ջص���������������100uS��
// ����: none.
// ����: none.
//========================================================================
void ir_rec_callback()
{
    static xdata uint8  IR_SampleCnt;       //��������
    static xdata uint8  IR_BitCnt;          //����λ��
    static xdata uint8  IR_UserH;           //�û���(��ַ)���ֽ�
    static xdata uint8  IR_UserL;           //�û���(��ַ)���ֽ�
    static xdata uint8  IR_data;            //����ԭ��
    static xdata uint8  IR_DataShift;        //������λ

    static bit P_IR_RX_temp;             //Last sample
    static bit B_IR_Sync;                //���յ�ͬ����־

    uint8  SampleTime;
    uint8  IR_TemShit;

    IR_SampleCnt++;                         //Sample + 1

    F0 = P_IR_RX_temp;                      //Save Last sample status
    P_IR_RX_temp = IR_REC_PIN;                 //Read current status
    if(F0 && !P_IR_RX_temp)                 //Pre-sample is high��and current sample is low, so is fall edge
    {
        SampleTime = IR_SampleCnt;          //get the sample time
        IR_SampleCnt = 0;                   //Clear the sample counter

        if(SampleTime > D_IR_SYNC_MAX)     B_IR_Sync = 0;  //large the Maxim SYNC time, then error
        else if(SampleTime >= D_IR_SYNC_MIN)                    //SYNC
        {
            if(SampleTime >= D_IR_SYNC_DIVIDE)
            {
                B_IR_Sync = 1;                  //has received SYNC
                IR_BitCnt = D_IR_BIT_NUMBER;    //Load bit number
            }
        }
        else if(B_IR_Sync)                      //has received SYNC
        {
            if(SampleTime > D_IR_DATA_MAX)      B_IR_Sync=0;    //data samlpe time too large
            else
            {
                IR_DataShift >>= 1;                  //data shift right 1 bit
                if(SampleTime >= D_IR_DATA_DIVIDE)  IR_DataShift |= 0x80;    //devide data 0 or 1
                if(--IR_BitCnt == 0)                //bit number is over?
                {
                    B_IR_Sync = 0;                  //Clear SYNC

                    // if(~IR_DataShift == IR_data)     //�ж�����������
                    IR_TemShit = ~IR_DataShift;
                    if(IR_TemShit == IR_data);
                    {
                        _user_code = ((uint16)IR_UserH << 8) + IR_UserL;
                        _ir_code      = IR_data;
                        _b_ir_press   = 1;           //������Ч
                    }
                }
                else if((IR_BitCnt & 7)== 0)        //one byte receive
                {
                    IR_UserL = IR_UserH;            //Save the User code high byte
                    IR_UserH = IR_data;             //Save the User code low byte
                    IR_data  = IR_DataShift;         //Save the IR data byte
                }
            }
        }
    }
}

//========================================================================
// ����: ������ճ�ʼ��
// ����: none.
// ����: none.
//========================================================================
void ir_rx_init()
{
    IR_REC_PIN_MODE;
}

//========================================================================
// ����: ���յ������ź�
// ����: none.
// ����: 1,���յ������ź�;0,û�н��յ���������.
//========================================================================
uint8 ir_rx_available()
{
    if(_b_ir_press)
    {
        _b_ir_press = 0;
        return 1;
    }
    return 0;
}

//========================================================================
// ����: ���յ��û���
// ����: none.
// ����:  ���յ����û���.
//========================================================================
uint8 ir_rx_user_code()
{
    return _user_code;
}

//========================================================================
// ����: ���ռ���
// ����: none.
// ����: ���յ��ļ���.
//========================================================================
uint8 ir_rx_ircode()
{
     return _ir_code;
}
