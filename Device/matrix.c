#include "hc595.h"
#include "matrix.h"
#include "delay.h"

void matrix_init(void){
    hc595_enable_matrix();
}

// ������̬��ʾ
void matrix_display(uint8 index, uint8 *Str_begin, uint8 *Str_end){
    uint8 n = 15 - index;
    if(Str_end - Str_begin <= 8 - index){
        while(Str_begin < Str_end){
            hc595_bit_select(n);                // hc595ѡ��
            MATRIX_ROW = *Str_begin;            // ����
            delay1ms();                         // ά��1ms
            hc595_bit_disable();                // ��Ӱ
            n--;
            Str_begin++;
        }
    }
}

// ��̬��ʾ
void matrix_run(uint8 *Str, uint8 size_n, uint8 begin){
    uint8 n, t;
    for(n=15; n>=8; n--){
        hc595_bit_select(n);		            // hc595ѡ��
        t = (begin + (15 - n)) % size_n;
        MATRIX_ROW = Str[t];		            // ����
        delay1ms();					            // ά��1ms
        hc595_bit_disable();		            // ��Ӱ
    }
}

//uint8 SKB[] = {
//    0xff, 0xff, 0xd9, 0xb6, 0xb6, 0xcd, 0xff, 0xff,		// S
//    0xff, 0xff, 0x80, 0xf7, 0xeb, 0xdd, 0xbe, 0xff,		// K
//    0xff, 0xff, 0x80, 0xb6, 0xb6, 0xc9, 0xff, 0xff,		// B
//    0xf3, 0xed, 0xdd, 0xbb, 0xbb, 0xdd, 0xed, 0xf3,		// ��
//};
// matrix_display(0, SKB+2*8, SKB+3*8);
// matrix_run(SKB, sizeof(SKB), begin);
