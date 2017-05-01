#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);
void LCD_SendData(u_int8 data);
void LCD_Send_Command(u_int8 cmd);
void LCD_Clear(void);
void LCD_GotoXY(u_int8 x, u_int8 y);
void LCD_SendString(u_int8 *str);
void LCD_SendString_XY(u_int8 *str, u_int8 x, u_int8 y);


/**
 *
 * to write a another symbol access CGROM
 * send command (0x40)
 * send 8 bytes
 *
 * */
#endif
