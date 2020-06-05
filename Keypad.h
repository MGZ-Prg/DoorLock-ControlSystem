#ifndef KEYPAD
#define KEYPAD
#include "stdint.h"
#include <stdbool.h>
#include "GPIO.h"



#define keypad_L GPIO_PORTB_LOCK_R // lock register
#define keypad_C GPIO_PORTB_CR_R  // commit register
#define keypad_AM GPIO_PORTB_AMSEL_R // analog enable 
#define keypad_DE GPIO_PORTB_DEN_R //digital enable 
#define keypad_AF GPIO_PORTB_AFSEL_R //alternative function
#define keypad_PCTL GPIO_PORTB_PCTL_R // port control 0 for GPIO ,each 4 bits for represent 1 pin
#define keypad_PU GPIO_PORTB_PUR_R // pull up resistors
#define keypad_data GPIO_PORTB_DATA_R  // data register
#define keypad_dir GPIO_PORTB_DIR_R // driection register

#define Top 4
#define top 4

#define Bottom 0
#define Bot 0
#define bot 0


#define rows 4
#define cols 4
// i am trying to make the keypad take different ports so for example the rows take pins 4,5,6,7 from port A and columns take
// pins 0,1,2,3 from port F

// here we will make rows take a port but we didn't specify which pins
#define rows_port PortE

//here we will make columns take a port but we didn't specify which pins
#define cols_port PortA

//here we specify if we take Top(pins 4,5,6,7) or Bottom(pins 0,1,2,3) for rows
//top=Top , Bottom = Bot = bot
#define rows_pos Bot 

//here we specify if we take Top(pins 4,5,6,7) or Bottom(pins 0,1,2,3) for rows
//top=Top , Bottom = Bot = bot
#define cols_pos Top


uint8_t keypad_get_char(); //protoytpe for getting char from keyppad
void keypad_init(); //protoytpe for initializing keypad






#endif
