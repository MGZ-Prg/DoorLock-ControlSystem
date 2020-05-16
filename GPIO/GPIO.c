#include "GPIO.h"
void pinMode( PORT Port, PIN Pin, MODE Mode )
{

	if(Port == PortA )
	{
		assert(Pin<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTA_AFSEL_R , Pin );
		GPIO_PORTA_PCTL_R =  GPIO_PORTA_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTA_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTA_DEN_R , Pin) ;
		if(Mode == Output)
			SET_BIT ( GPIO_PORTA_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTA_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTA_PUR_R , Pin );
		SET_BIT ( GPIO_PORTA_PDR_R , Pin) ;
		GPIO_PORTA_IM_R &= !(0xFF); 
		GPIO_PORTA_IS_R &= !(0xFF);
		
	}
	else if(Port == PortB )
	{
		assert(Pin<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTB_AFSEL_R , Pin );
		GPIO_PORTB_PCTL_R =  GPIO_PORTB_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTB_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTB_DEN_R , Pin) ;
		if(Mode == Output)
			SET_BIT ( GPIO_PORTB_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTB_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTB_PUR_R , Pin );
		SET_BIT ( GPIO_PORTB_PDR_R , Pin) ;
		GPIO_PORTB_IM_R &= !(0xFF); 
		GPIO_PORTB_IS_R &= !(0xFF);
		
	}
	else if(Port == PortC )
	{
		assert(Pin<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTC_LOCK_R = 0x4C4F434B;
		GPIO_PORTC_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTC_AFSEL_R , Pin );
		GPIO_PORTC_PCTL_R =  GPIO_PORTC_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTC_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTC_DEN_R , Pin) ;
		if(Mode == Output)
			SET_BIT ( GPIO_PORTC_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTC_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTC_PUR_R , Pin );
		SET_BIT ( GPIO_PORTC_PDR_R , Pin) ;
	//	GPIO_PORTC_IM_R &= !(0xFF); 
	//	GPIO_PORTC_RIS_R &= !(0xFF);
	//	GPIO_PORTC_IS_R &= !(0xFF);
		
	}
	else if(Port == PortD )
	{
		assert(Pin<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTD_LOCK_R = 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTD_AFSEL_R , Pin );
		GPIO_PORTD_PCTL_R =  GPIO_PORTD_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTD_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTD_DEN_R , Pin) ;
		if(Mode == Output)
			SET_BIT ( GPIO_PORTD_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTD_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTD_PUR_R , Pin );
		SET_BIT ( GPIO_PORTD_PDR_R , Pin) ;
		GPIO_PORTD_IM_R &= !(0xFF); 
	//	GPIO_PORTD_RIS_R &= !(0xFF);
		GPIO_PORTD_IS_R &= !(0xFF);
	}
	else if(Port == PortE )
	{
		assert(Pin<=5);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTE_LOCK_R = 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTE_AFSEL_R , Pin );
		GPIO_PORTE_PCTL_R =  GPIO_PORTE_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTE_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTE_DEN_R , Pin) ;
		if(Mode == Output)
			SET_BIT ( GPIO_PORTE_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTE_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTE_PUR_R , Pin );
		SET_BIT ( GPIO_PORTE_PDR_R , Pin) ;
		GPIO_PORTE_IM_R &= !(0xFF); 
	//	GPIO_PORTE_RIS_R &= !(0xFF);
		GPIO_PORTE_IS_R &= !(0xFF);
	}
	else if(Port == PortF )
	{
		assert(Pin<=4);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0xFF;
		CLEAR_BIT ( GPIO_PORTF_AFSEL_R , Pin );
		GPIO_PORTF_PCTL_R =  GPIO_PORTF_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTF_AMSEL_R , Pin );
		SET_BIT ( GPIO_PORTF_DEN_R , Pin) ;
			
		if(Mode == Output)
			SET_BIT ( GPIO_PORTF_DIR_R , Pin) ;
		else
			CLEAR_BIT ( GPIO_PORTF_DIR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTF_PUR_R , Pin );
		SET_BIT ( GPIO_PORTF_PDR_R , Pin) ;
		
		GPIO_PORTF_IM_R &= !(0xFF); 
	//	GPIO_PORTF_RIS_R &= !(0xFF);//READ ONLY IF WANT ICR -> 1
		GPIO_PORTF_IS_R &= !(0xFF);
		
	}
}
bool digitalPinRead(PORT Port, PIN Pin)
{
		if(Port == PortA)
			return BIT_IS_SET( GPIO_PORTA_DATA_R , Pin);
		else if(Port == PortB)
			return BIT_IS_SET( GPIO_PORTB_DATA_R , Pin);
		else if(Port == PortC)
			return BIT_IS_SET( GPIO_PORTC_DATA_R , Pin);
		else if(Port == PortD)
			return BIT_IS_SET( GPIO_PORTD_DATA_R , Pin);
		else if(Port == PortE)
			return BIT_IS_SET( GPIO_PORTE_DATA_R , Pin);
		else if(Port == PortF)
			return BIT_IS_SET( GPIO_PORTF_DATA_R , Pin);
		else
			return 0;
}
uint8_t digitalPortRead(PORT Port)
{
		if(Port == PortA)
			return GPIO_PORTA_DATA_R ;
		else if(Port == PortB)
			return GPIO_PORTB_DATA_R ;
		else if(Port == PortC)
			return GPIO_PORTC_DATA_R ;
		else if(Port == PortD)
			return GPIO_PORTD_DATA_R ;
		else if(Port == PortE)
			return GPIO_PORTE_DATA_R ;
		else if(Port == PortF)
			return GPIO_PORTF_DATA_R ;
		else
			return 0;
}
void digitalWrite(PORT Port, PIN Pin, bool Value)
{
	 if(Port == PortA)
	 {
		 if(Value == 0)
			 CLEAR_BIT ( GPIO_PORTA_DATA_R , Pin );
		else
				SET_BIT ( GPIO_PORTA_DATA_R , Pin) ;
	 }	
		else if(Port == PortB)
		{
			if(Value == 0)
				CLEAR_BIT ( GPIO_PORTB_DATA_R , Pin );
			else
				SET_BIT ( GPIO_PORTB_DATA_R , Pin) ;
		}	
		else if(Port == PortC)
		{
		 if(Value == 0)
			 CLEAR_BIT ( GPIO_PORTC_DATA_R , Pin );
		else
				SET_BIT ( GPIO_PORTC_DATA_R , Pin) ;
		}	
		else if(Port == PortD)
		 {
		 if(Value == 0)
			 CLEAR_BIT ( GPIO_PORTD_DATA_R , Pin );
		else
				SET_BIT ( GPIO_PORTD_DATA_R , Pin) ;
	}	
		else if(Port == PortE)
		 {
		 if(Value == 0)
			 CLEAR_BIT ( GPIO_PORTE_DATA_R , Pin );
		else
				SET_BIT ( GPIO_PORTE_DATA_R , Pin) ;
	}	
		else if(Port == PortF)
			 {
		 if(Value == 0)
			 CLEAR_BIT ( GPIO_PORTF_DATA_R , Pin );
		else
				SET_BIT ( GPIO_PORTF_DATA_R , Pin) ;
	}	
}
void digitalPortWrite(PORT Port, uint8_t Value)
{
	 if(Port == PortA)
			GPIO_PORTA_DATA_R = Value ;
	else if(Port == PortB)
			GPIO_PORTB_DATA_R = Value ;
	else if(Port == PortC)
			GPIO_PORTC_DATA_R = Value ;
	else if(Port == PortD)
			GPIO_PORTD_DATA_R = Value ;
	else if(Port == PortE)
			GPIO_PORTE_DATA_R = Value ;
	else if(Port == PortF)
			GPIO_PORTF_DATA_R = Value ;
}
void analogPinInit(PORT Port, AIN_P Ain)
{
	if(Port == PortA )
	{
		assert(Ain<=7);
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0xFF;
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		SET_BIT ( GPIO_PORTA_AFSEL_R , Ain );
		GPIO_PORTA_PCTL_R =  GPIO_PORTA_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTA_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTA_DEN_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTA_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTA_PUR_R , Ain );
		SET_BIT ( GPIO_PORTA_PDR_R , Ain) ;
		GPIO_PORTA_IM_R &= !(0xFF); 
		GPIO_PORTA_IS_R &= !(0xFF);
		
	}
	else if(Port == PortB )
	{
		assert(Ain<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R |= 0xFF;
		SET_BIT ( GPIO_PORTB_AFSEL_R , Ain );
		GPIO_PORTB_PCTL_R =  GPIO_PORTB_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTB_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTB_DEN_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTB_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTB_PUR_R , Ain );
		SET_BIT ( GPIO_PORTB_PDR_R , Ain) ;
		GPIO_PORTB_IM_R &= !(0xFF); 
		GPIO_PORTB_IS_R &= !(0xFF);
	}
	else if(Port == PortC )
	{
		assert(Ain<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTC_LOCK_R = 0x4C4F434B;
		GPIO_PORTC_CR_R |= 0xFF;
		SET_BIT ( GPIO_PORTC_AFSEL_R , Ain );
		GPIO_PORTC_PCTL_R =  GPIO_PORTC_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTC_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTC_DEN_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTC_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTC_PUR_R , Ain );
		SET_BIT ( GPIO_PORTC_PDR_R , Ain) ;
	//	GPIO_PORTC_IM_R &= !(0xFF); 
	//	GPIO_PORTC_RIS_R &= !(0xFF);
	//	GPIO_PORTC_IS_R &= !(0xFF);
		
	}
	else if(Port == PortD )
	{
		assert(Ain<=7);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTD_LOCK_R = 0x4C4F434B;
		GPIO_PORTD_CR_R |= 0xFF;
		SET_BIT ( GPIO_PORTD_AFSEL_R , Ain );
		GPIO_PORTD_PCTL_R =  GPIO_PORTD_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTD_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTD_DEN_R , Ain) ;		
		CLEAR_BIT ( GPIO_PORTD_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTD_PUR_R , Ain );
		SET_BIT ( GPIO_PORTD_PDR_R , Ain) ;
		GPIO_PORTD_IM_R &= !(0xFF); 
	//	GPIO_PORTD_RIS_R &= !(0xFF);
		GPIO_PORTD_IS_R &= !(0xFF);
	}
	else if(Port == PortE )
	{
		assert(Ain<=5);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTE_LOCK_R = 0x4C4F434B;
		GPIO_PORTE_CR_R |= 0xFF;
		SET_BIT ( GPIO_PORTE_AFSEL_R , Ain );
		GPIO_PORTE_PCTL_R =  GPIO_PORTE_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTE_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTE_DEN_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTE_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTE_PUR_R , Ain );
		SET_BIT ( GPIO_PORTE_PDR_R , Ain) ;
		GPIO_PORTE_IM_R &= !(0xFF); 
	//	GPIO_PORTE_RIS_R &= !(0xFF);
		GPIO_PORTE_IS_R &= !(0xFF);
	}
	else if(Port == PortF )
	{
		assert(Ain<=4);
		SET_BIT (SYSCTL_RCGCGPIO_R , Port) ;
		while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0xFF;
		SET_BIT ( GPIO_PORTF_AFSEL_R , Ain );
		GPIO_PORTF_PCTL_R =  GPIO_PORTF_PCTL_R & !(0x000F << Ain);
		SET_BIT ( GPIO_PORTF_AMSEL_R , Ain );
		CLEAR_BIT ( GPIO_PORTF_DEN_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTF_DIR_R , Ain) ;
		CLEAR_BIT ( GPIO_PORTF_PUR_R , Ain );
		SET_BIT ( GPIO_PORTF_PDR_R , Ain) ;
		GPIO_PORTF_IM_R &= !(0xFF); 
	//	GPIO_PORTF_RIS_R &= !(0xFF);//READ ONLY IF WANT ICR -> 1
		GPIO_PORTF_IS_R &= !(0xFF);
	}
}