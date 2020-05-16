#ifndef GPIO_H_
#define GPIO_H_

#include "common_macros.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <D:\Keil\EE319Kware\inc\tm4c123gh6pm.h>
#include <assert.h>


#define High 1
#define high 1
#define Low 0
#define low 0

typedef enum {
	PortA=0 ,PortB ,PortC ,PortD ,PortE ,PortF
}PORT;

typedef enum {
	Input,Output
}MODE;

typedef enum {
	P0,P1,P2,P3,P4,P5,P6,P7
}PIN;

typedef enum {
	AIN0 ,AIN1 ,AIN2 ,AIN3 ,AIN4 ,AIN5 ,AIN6 ,AIN7 ,AIN8 ,AIN9 ,AIN10 ,AIN11
}AIN;
typedef enum {
	PE3 = 3  ,PE2=2 ,PE1=1 ,PE0=0,PE4=4 ,PE5=5 ,PB4=4 ,PB5=5 ,PD3=3 ,PD2=2 ,PD1=1 ,PD0=0
	}AIN_P; // analog input written pins eg:PE0 = AIN0

void pinMode( PORT Port, PIN Pin, MODE Mode );
void digitalWrite(PORT Port, PIN Pin, bool Value);
bool digitalPinRead(PORT Port, PIN Pin);
uint8_t digitalPortRead(PORT Port);
void digitalPortWrite(PORT Port, uint8_t Value);
void analogPinInit(PORT Port, AIN_P Ain);

#endif