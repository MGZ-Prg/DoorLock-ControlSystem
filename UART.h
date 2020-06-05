#ifndef UART_H
#define UART_H
#include "common_macros.h"
#include "stdint.h"
#include "D:\Keil\EE319Kware\inc\tm4c123gh6pm.h"
#include "std_types.h"
#include "TM4C123.h"
#define SYS_CLK		16000000
#define UART_0 0
#define UART_1 1
#define UART_2 2


void UART_Init(uint8 UART_NUM,uint8 length,uint16 Baud_Rate);
void UART_Send_Char(uint8 character,uint8 UART_NUM);
uint8 UART_Receive_Char(uint8 UART_NUM);
void UART_Send_String(uint8_t Str[], uint8_t UART_NUM);
void UART_Receive_String(uint8 UART_NUM);


#endif