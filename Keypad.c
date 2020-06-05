#include "Keypad.h"
#if (cols == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8_t KeyPad_4x3_adjustKeyNumber(uint8_t button_number);
#elif (cols == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number);
#endif


	void keypad_init()
	{
			#if( rows_pos == top)
			pinMode(rows_port , P4 , Input);// bits 4,5,6,7 are outputs, bits 0,1,2,3 are inputs
			pinMode(rows_port , P5 , Input);
			pinMode(rows_port , P6 , Input);
			pinMode(rows_port , P7 , Input);
			#elif(rows_pos == bot)
			pinMode(rows_port , P0 , Input);// bits 4,5,6,7 are outputs, bits 0,1,2,3 are inputs
			pinMode(rows_port , P1 , Input);
			pinMode(rows_port , P2 , Input);
			pinMode(rows_port , P3 , Input);
			#endif
		
			#if( cols_pos == top)
			pinMode(cols_port , P4 , Output);
			pinMode(cols_port , P5 , Output);
			pinMode(cols_port , P6 , Output);
			pinMode(cols_port , P7 , Output);
			digitalWrite(cols_port , P4 , Low);
			digitalWrite(cols_port , P5 , Low);
			digitalWrite(cols_port , P6 , Low);
			digitalWrite(cols_port , P7 , Low);
			
			#elif(cols_pos == bot)
			
			pinMode(cols_port , P0 , Output);
			pinMode(cols_port , P1 , Output);
			pinMode(cols_port , P2 , Output);
			pinMode(cols_port , P3 , Output);
			digitalWrite(cols_port , P0 , Low);
			digitalWrite(cols_port , P1 , Low);
			digitalWrite(cols_port , P2 , Low);
			digitalWrite(cols_port , P3 , Low);
			
			#endif
			
			
			/*pinMode(PortB , P0 , Input);// bits 4,5,6,7 are outputs, bits 0,1,2,3 are inputs
			pinMode(PortB , P1 , Input);
			pinMode(PortB , P2 , Input);
			pinMode(PortB , P3 , Input);
			pinMode(PortB , P4 , Output);
			pinMode(PortB , P5 , Output);
			pinMode(PortB , P6 , Output);
			pinMode(PortB , P7 , Output);
			digitalWrite(PortB , P4 , Low);//setting all outputs to LOW, inputs are not affected
			digitalWrite(PortB , P5 , Low);
			digitalWrite(PortB , P6 , Low);
			digitalWrite(PortB , P7 , Low);  */
	}
	uint8_t keypad_get_char()
	{
		while(1)
		{
			uint8_t COL;
			uint8_t ROW;
			uint8_t temp;
			for(COL = cols_pos; COL < cols + cols_pos ; COL++)
			{
					temp = ( digitalPortRead(cols_port) & (0xF0<<cols_pos)) | (1<< COL) ; 
					digitalPortWrite(cols_port , temp);
					for (ROW = rows_pos; ROW < rows + rows_pos ; ROW++)
					{
						if( digitalPinRead(rows_port,ROW+rows_pos) )   // any key get pressed
						{
							#if (cols == 3)  
								return KeyPad_4x3_adjustKeyNumber((ROW*cols)+COL+1); 
							#elif (cols == 4)
								return KeyPad_4x4_adjustKeyNumber((ROW*cols)+COL+1);
							#endif
						
						}
					}
			}	
	}
}
#if (cols == 3) 
static uint8_t KeyPad_4x3_adjustKeyNumber(uint8_t button_number)
{
	switch(button_number)
	{
		case 10: return '*'; // ASCII Code of =
				 break;
		case 11: return 0;
				 break;		
		case 12: return '#'; // ASCII Code of +
				 break;
		default: return button_number;								 						
	}
} 

#elif (cols == 4)
 
static uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number)
{
	switch(button_number)
	{
		case 1: return 1; 
				break;
		case 2: return 2; 
				break;
		case 3: return 3; 
				break;
		case 4: return 'A'; // ASCII Code of A
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return 'B'; /* ASCII Code of '*' */
				break;		
		case 9: return 7; 
				break;
		case 10: return 8; 
				break;
		case 11: return 9; 
				break;
		case 12: return 'C'; /* ASCII Code of '-' */
				break;
		case 13: return '*';  /* ASCII of Enter */
				break;			
		case 14: return 0; 
				break;
		case 15: return '#'; /* ASCII Code of '=' */
				break;
		case 16: return 'D'; /* ASCII Code of '+' */
				break;
		default: return button_number;								 						
	}
} 

#endif