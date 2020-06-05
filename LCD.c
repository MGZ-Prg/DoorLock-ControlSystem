#include "LCD.h"



void Control_Pins_Init(void){ 
SYSCTL_RCGCGPIO_R|=(1<<CONTROLPORT);																	//ENABLE CLK FOR PORTA 
while((SYSCTL_PRGPIO_R&(1<<CONTROLPORT))==0){} 															//WAIT UNTIL CLK IS READY 
CONTROLPORT_DIR_R |=(1<<RS) | (1<<RW) | (1<<ENB);														//RS,RW,ENB OUTPUT
CONTROLPORT_DEN_R |=(1<<RS) | (1<<RW) | (1<<ENB); 														//ENABLE DIGITAL COMMUNICATION FOR RS,RW,ENB
CONTROLPORT_AMSEL_R &=~ (1<<RS);CONTROLPORT_AMSEL_R &=~ (1<<RW);CONTROLPORT_AMSEL_R &=~ (1<<ENB);		//DISABLE ANALOG COMMUNICATION
CONTROLPORT_LOCK_R = 0x4C4F434B; 																		//UNLOCK COMMIT REGISTER
CONTROLPORT_CR_R |= (1 << RS) | (1 << RW) | (1 << ENB); 												//ENABLE BITS
CONTROLPORT_AFSEL_R &=~(1<<RS);CONTROLPORT_AFSEL_R &=~(1<<RW);CONTROLPORT_AFSEL_R &=~(1<<ENB);			//DISABLE ALT FUNCTION
}

void Data_Port_Init(void){
SYSCTL_RCGCGPIO_R|=(1<<DATAPORT);																		//ENABLE CLK FOR DATAPORT 
while((SYSCTL_PRGPIO_R&(1<<DATAPORT))==0){}																//WAIT UNTIL CLK IS READY 
DATAPORT_DIR_R = 0XFF;																					//DATAPORT IS OUTPUT	
DATAPORT_DEN_R |= 0XFF;																					//ENABLE DIGITAL COMMUNICATION
DATAPORT_AMSEL_R = 0X00;																				//DISABLE ANALOG COMMUNICATION	
DATAPORT_LOCK_R = 0x4C4F434B;																			//UNLOCK COMMIT REGISTER
DATAPORT_CR_R = 0XFF;																					//ENABLE BITS
DATAPORT_AFSEL_R = 0X00;																				//DISABLE ALT FUNCTION
}

void Delay(uint32_t counter){
uint32_t x,y;
	for(x=0;x<counter;x++){
	for(y=0;y<counter;y++){
	}
	}
}
 

void Send_Command(uint8_t command){
CONTROLPORT_DATA_R &=~(1<<RS);												//WRITING COMMAND==>RS=0
CONTROLPORT_DATA_R &=~(1<<RW);												//WRITING TO LCD==>RW=0
CONTROLPORT_DATA_R |=(1<<ENB);												//ENABLE==>HIGH
Delay(1000000);
DATAPORT_DATA_R=command;													//SEND COMMAND
Delay(1000000);
CONTROLPORT_DATA_R &=~(1<<ENB);												//ENABLE==>LOW
Delay(1000000);	
}

void Display_Character(uint8_t character){
CONTROLPORT_DATA_R |=(1<<RS);												//WRITING DATA==>RS=1
CONTROLPORT_DATA_R &=~(1<<RW);												//WRITING TO LCD==>RW=0
CONTROLPORT_DATA_R |=(1<<ENB);												//ENABLE==>HIGH
Delay(100);
DATAPORT_DATA_R=character;													//SEND CHARACTER
Delay(100);
CONTROLPORT_DATA_R &=~(1<<ENB);												//ENABLE==>LOW
Delay(100);
}

void Display_String(const char* ptr2string){
	uint8_t i =0;
while(*(ptr2string+i) != '\0'){ 
	Display_Character(*(ptr2string+i));
	i++;
}



}




void Set_Position(uint8_t row , uint8_t col){

	uint8_t real_address;
	switch(row)
	{
		case 0 : 
			real_address=col;
			break;
		
		case 1 :
			real_address=col+0x40; 			//SHIFT TO THE 2nd LINE LOCATION IN LCD RAM
			break;
		
		case 2:
				real_address=col+0x10;		//SHIFT TO THE 3rD LINE LOCATION IN LCD RAM
				break;
		case 3:
				real_address=col+0x50;		//SHIFT TO THE 4th LINE LOCATION IN LCD RAM
				break;

	}
	Send_Command(real_address|SET_CURSOR_LOCATION);

}










void Delete_Last_Char(void){
Send_Command(CURSOR_OFF);	
Send_Command(0x10);			//SHIFT CURSOR TO THE LEFT
Display_Character(' ');	
Send_Command(0x14);			//SHIFT CURSOR TO THE RIGHT
Send_Command(CURSOR_ON);

}












void LCD_Init(void){

Send_Command(TWO_LINE_LCD_Eight_BIT_MODE);
Send_Command(CLEAR_COMMAND);
Send_Command(CURSOR_BLINKING);
Set_Position(0,0);

}

void Clear_Screen(void) {
Send_Command(CLEAR_COMMAND);
}

