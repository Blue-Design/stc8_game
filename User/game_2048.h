#ifndef __GAME_2048_H
#define __GAME_2048_H

#include "sys.h"
#include "tftlcd.h"
#include <stdlib.h>
#include "eeprom.h"

void game2048_init();                   // 2048��ʼ����Ϸ����
void game2048_run();                    // ������Ϸ
void game2048_updateStatus(uint8 key);  // ��������

#endif
