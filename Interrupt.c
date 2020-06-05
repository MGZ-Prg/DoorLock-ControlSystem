#include "Interrupt.h"

void GPIO_Int(PORT Port ,PIN Pin )
{
	//Int_fun_ptr = fun_ptr;
	
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
		SET_BIT ( GPIO_PORTA_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTA_PUR_R , Pin );
		SET_BIT ( GPIO_PORTA_PDR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTA_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTA_IBE_R , Pin );
		SET_BIT ( GPIO_PORTA_IEV_R , Pin );
		SET_BIT ( GPIO_PORTA_IM_R , Pin );
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
		SET_BIT ( GPIO_PORTB_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTB_PUR_R , Pin );
		SET_BIT ( GPIO_PORTB_PDR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTB_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTB_IBE_R , Pin );
		SET_BIT ( GPIO_PORTB_IEV_R , Pin );
		SET_BIT ( GPIO_PORTB_IM_R , Pin );
		
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
		SET_BIT ( GPIO_PORTC_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTC_PUR_R , Pin );
		SET_BIT ( GPIO_PORTC_PDR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTC_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTC_IBE_R , Pin );
		SET_BIT ( GPIO_PORTC_IEV_R , Pin );
		SET_BIT ( GPIO_PORTC_IM_R , Pin );
		
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
		SET_BIT ( GPIO_PORTD_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTD_PUR_R , Pin );
		SET_BIT ( GPIO_PORTD_PDR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTD_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTD_IBE_R , Pin );
		SET_BIT ( GPIO_PORTD_IEV_R , Pin );
		SET_BIT ( GPIO_PORTD_IM_R , Pin );
		
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
		SET_BIT ( GPIO_PORTE_DIR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTE_PUR_R , Pin );
		SET_BIT ( GPIO_PORTE_PDR_R , Pin) ;
		
		CLEAR_BIT ( GPIO_PORTE_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTE_IBE_R , Pin );
		SET_BIT ( GPIO_PORTE_IEV_R , Pin );
		SET_BIT ( GPIO_PORTE_IM_R , Pin );
		
		
	}
	else if(Port == PortF )
	{
		int x=8;
		assert(Pin<=4);
		SET_BIT (SYSCTL_RCGC2_R , Port) ;
		while(x--){}	
		//while( BIT_IS_CLEAR( SYSCTL_PRGPIO_R , Port) ) {}
		CLEAR_BIT ( GPIO_PORTF_AFSEL_R , Pin ); 
		SET_BIT ( GPIO_PORTF_DEN_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTF_AMSEL_R , Pin );
		CLEAR_BIT ( GPIO_PORTF_DIR_R , Pin) ;
		GPIO_PORTF_PCTL_R =  GPIO_PORTF_PCTL_R & !(0x000F << Pin);
		CLEAR_BIT ( GPIO_PORTF_PUR_R , Pin );
		SET_BIT ( GPIO_PORTF_PDR_R , Pin) ;
		CLEAR_BIT ( GPIO_PORTF_IS_R , Pin );
		CLEAR_BIT ( GPIO_PORTF_IBE_R , Pin );
		SET_BIT ( GPIO_PORTF_IEV_R , Pin );
		SET_BIT ( GPIO_PORTF_IM_R , Pin );
		SET_BIT ( GPIO_PORTF_ICR_R , Pin );
		NVIC_PRI17_R  = (NVIC_PRI17_R  & 0xFF00FFFF) | 0x00A00000;
		NVIC_EN0_R = 0x40000000;
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0xFF;
	}
}