/*
 * New_CEENbot2.c
 *
 * Created: 7/2/2018 7:13:35 PM
 * Author : Nick Jaton
 * In case the Libraries do not work. You need "libcapi324v22x" and "libprintf_flt"
 * This program will let the user create different shapes using the buttons. The robot will
 * move in the shape of the button character. Except for in X's case, X just give out a print statement. 
 */ 

#include "capi324v221.h"


void CBOT_main(void)
{
	LCD_open();
	LCD_clear();
	STEPPER_open();
	PSXC_open();
	
	PSXC_STDATA PSXC_DATA;
	
	LCD_printf("If you see this press Analog");
	while (1)
	{
		//If the Analog button is pressed the program will look for commands.
		while(PSXC_read( &PSXC_DATA) == TRUE)
		{
			LCD_printf("great! press X,SQR,TRI or Circle");
			LCD_clear();
		
			TMRSRVC_delay_ms(15);
			
			//Create a circle if Cir is pressed.
			if (!(PSXC_DATA.buttons1 & CIR_BIT))
			{
				STEPPER_move_stwt (STEPPER_BOTH,
				STEPPER_FWD, 1000, 200, 400, STEPPER_BRK_OFF,
				STEPPER_FWD, 0, 0, 0, STEPPER_BRK_OFF);
			}
			
			//Create a triangle if TRI is pressed. 
			if (!(PSXC_DATA.buttons1 & TRI_BIT))
			{
				for (int i = 0; i < 3; i = i + 1)
				{
					STEPPER_move_stwt (STEPPER_BOTH,
					STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF,
					STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF);	
					
					TMRSRVC_delay_ms(100);
					
					STEPPER_move_stwt (STEPPER_BOTH,
					STEPPER_FWD, 165, 200, 400, STEPPER_BRK_OFF,
					STEPPER_REV, 165, 200, 400, STEPPER_BRK_OFF);
					
					TMRSRVC_delay_ms(100);				
				}
			}
			
			//Create a Square if the square is pressed. 
			if (!(PSXC_DATA.buttons1 & SQR_BIT))
			{
					for (int i = 0; i < 4; i = i + 1)
					{
						STEPPER_move_stwt (STEPPER_BOTH,
						STEPPER_FWD, 200, 200, 400, STEPPER_BRK_OFF,
						STEPPER_FWD, 200, 200, 400, STEPPER_BRK_OFF);
						
						TMRSRVC_delay_ms(100);
						
						STEPPER_move_stwt (STEPPER_BOTH,
						STEPPER_FWD, 120, 200, 400, STEPPER_BRK_OFF,
						STEPPER_REV, 120, 200, 400, STEPPER_BRK_OFF);
						
						TMRSRVC_delay_ms(100);
					}
			}
			
			//If X is pressed it's print statement time. 
			if (!(PSXC_DATA.buttons1 & X_BIT))
			{
				LCD_printf("WOW! You Pressed X!");
				TMRSRVC_delay_ms(200);
				LCD_clear();

			}
			
		}
		
		TMRSRVC_delay_ms(2);
    }
}

