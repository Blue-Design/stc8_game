#ifndef _MATRIX_H
#define _MATRIX_H

#include "sys.h"

#define MATRIX_ROW      P6

void matrix_init(void);     // led���г�ʼ��
void matrix_display(uint8 index, uint8 *Str_begin, uint8 *Str_end);     // ������̬��ʾ
void matrix_run(uint8 *Str, uint8 size_n, uint8 begin);                 // ��̬��ʾ

#endif