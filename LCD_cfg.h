#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_PORT 1
#define LCD_RS 8
#define LCD_EN 9
/*
 * wait 15ms before start initialization
 * Rs = 0 instruction command code register selected
 * Rs = 1 data register selected
 * r/w = 0 writing
 * E = 1 when write data or command for at least 450ns
 * 0x28 ---> 4bit mode
 * wait 100 micro sec after each data or command
 * for clear lcd 2ms
 *
 * */
#endif
