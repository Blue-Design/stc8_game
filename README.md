# stc8_game
**板型**: 天问51（STC8H8K64U）

**开发进度**:

- [x] 2048
  - [x] 游戏界面绘制
  - [x] 游戏逻辑实现
  - [x] 计分系统 
- [ ] 贪吃蛇
- [ ] 数独
- [ ] 五子棋 

**坑**:

- eeprom多次写入，在写入前需要先擦除扇区，否则数据无法写入
- 触摸屏的eeprom读写与game2048内eeprom的读写冲突，无法同时（不知道为啥子）

**附图**:

![2048_init](./img/1.jpg)

![2048_lose](./img/2.jpg)

![2048_win](./img/3.jpg)