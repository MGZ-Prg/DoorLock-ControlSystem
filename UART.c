#include "UART.h"
void UART_Init( uint8_t UART_NUM , uint8_t Data_Size , uint16_t Baud_Rate )
{
    uint16_t Clock_Div =(int)( SYS_CLK /( Baud_Rate*16 )); //Clock Div Integer Part
	
    float32 Fraction   =  (float)( SYS_CLK /( Baud_Rate*16 ))-Clock_Div; // Clock Div Fraction Part
	
		SYSCTL_RCGCUART_R |=(1<<UART_NUM); 	// Enable The Clock for UART
	
		SYSCTL_RCGCGPIO_R |=(1<<UART_NUM);	// Enable The Clock for GPIO 
	
    if(UART_NUM == UART_0)
    {
				SET_BIT(GPIO_PORTA_AFSEL_R,0);			//Set the Alt. Fun. to UART for PA0 & PA1
        SET_BIT(GPIO_PORTA_AFSEL_R,1);	
			
				SET_BIT(GPIO_PORTA_DEN_R,0);				//Enable Digital For PA0 & PA1
        SET_BIT(GPIO_PORTA_DEN_R,1);					
			
        CLEAR_BIT(GPIO_PORTA_AMSEL_R,0);		//Disable Analoge For PA0 & PA1
        CLEAR_BIT(GPIO_PORTA_AMSEL_R,1);		
			
				GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R& 0xFFFFFF00 ) + 0x00000011 ;				//DEFINE ALT FUN CODE PA0 & PA1	
			
        CLEAR_BIT(UART0_CTL_R,0);									  //Disable the UART
        UART0_IBRD_R = Clock_Div;										//Write the integer portion of the BRD
        UART0_FBRD_R=(int)(Fraction*64+0.5);			  //Write the fractional portion of the BRD
				UART0_LCRH_R |= ( Data_Size - 5) << 5;			//Set DataSize
			
        UART0_CC_R = UART0_CC_R & 0xFFFFFFF0;				//Use System clock (based on clock source and divisor factor)0x0
        
        SET_BIT(UART0_CTL_R,8);											//ENABLE RX
        SET_BIT(UART0_CTL_R,9);											//ENABLE TX
			
        SET_BIT(UART0_CTL_R,0);											//Enable the UART
    }
    else if( UART_NUM == UART_1)
    {
        uint16_t dummy;
        SET_BIT(SYSCTL_RCGCUART_R,1);																				//ENABLE CLK FOR UART1
        SET_BIT(SYSCTL_RCGCGPIO_R,1);																				//ENABLE CLK FOR PORTB
        dummy = SYSCTL_RCGCGPIO_R;																					//CLK IS STABLE
        CLEAR_BIT(UART1_CTL_R,0);																						//DISABLE UART1
        UART1_IBRD_R= Clock_Div;														  								//SET BR
        UART1_FBRD_R=(int)(Fraction*64+0.5);																//SET BR
        UART1_CC_R=0x0;																											//USE SYSTEM CLOCK
        UART1_LCRH_R =0X60;													            						//SET DATA SIZE
        SET_BIT(UART1_CTL_R,8);																							//ENABLE UART1
        SET_BIT(UART1_CTL_R,9);																							//ENABLE RX
        SET_BIT(UART1_CTL_R,0);																							//ENABLE TX
        SET_BIT(GPIO_PORTB_AFSEL_R,0);
        SET_BIT(GPIO_PORTB_AFSEL_R,1);				//ENABLE ALT FUN FOR PB0 & PB1
        GPIO_PORTB_PCTL_R=0x11;																							//DEFINE ALT FUN CODE PB0 & PB1
        SET_BIT(GPIO_PORTB_DEN_R,0);
        SET_BIT(GPIO_PORTB_DEN_R,1);						//ENABLE DIGITAL FOR PB0 & PB1
        CLEAR_BIT(GPIO_PORTB_AMSEL_R,0);
        CLEAR_BIT(GPIO_PORTB_AMSEL_R,1);		//DISABLE ANALOG FOR PB0 & PB1
    }
}


void UART_Send_Char( uint8_t character,uint8_t UART_NUM)
{
    if(UART_NUM == UART_0)
    {
        while( BIT_IS_SET(UART0_FR_R,5) ) {}
        UART0_DR_R=character;
    }
    else if(UART_NUM == UART_1 )
    {
        while( BIT_IS_SET(UART1_FR_R,5) ) {}
        UART1_DR_R=character;
		}
}
uint8_t UART_Receive_Char(uint8_t UART_NUM)
{
    if(UART_NUM == UART_0)
    {
       while(BIT_IS_SET(UART0_FR_R,4)) {}
       return UART0_DR_R;
    }
    else if(UART_NUM == UART_1)
    {
        while(BIT_IS_SET(UART1_FR_R,4)) {}
        return UART1_DR_R;
    }
}

void UART_Send_String(uint8_t Str[], uint8_t UART_NUM)
{
    uint8_t i = 0;
    while(Str[i] != '\0')
    {
        UART_Send_Char(Str[i],UART_NUM);
        i++;
    }
}
uint8_t Str[100];
void UART_Receive_String(uint8_t UART_NUM)
{
    uint8_t i = 0;
    Str[i] = UART_Receive_Char(UART_NUM);
		UART_Send_Char(  Str[i] ,UART_NUM);
    while(Str[i] != '\r')
    {
        i++;
        Str[i] = UART_Receive_Char(UART_NUM);
				UART_Send_Char(  Str[i] ,UART_NUM);
				
    }
    Str[i] = '\0';
}
