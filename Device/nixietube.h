#ifndef _NIXIETUBE_H
#define _NIXIETUBE_H

#include <sys.h>

#define NIXIETUBE_PORT         P6
#define NIXIETUBE_PORT_MODE()  {P6M1=0x00;P6M0=0xff;}		// �������

#define LEFT_COLON_PIN          P07
#define LEFT_COLON_PIN_MODE()  {P0M1&=~0x80;P0M0|=0x80;}	// �������

#define RIGHT_COLON_PIN          P21
#define RIGHT_COLON_PIN_MODE()  {P2M1&=~0x02;P2M0|=0x02;}	// �������

extern uint8 nix_seg[18];

typedef enum _nix_content{
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
    SYM_A, SYM_B, SYM_C, SYM_D, SYM_E, SYM_F, SUB, NONE,
} nix_content;

void nix_init();                                            // �������ʾ��ʼ��
void nix_display_num(int32 num);                            // �������ʾ����
void nix_display_buf(uint8 begin, nix_content *buf, uint8 n);     // �������ʾbuf

#endif