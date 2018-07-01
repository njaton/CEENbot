/*
 * CEENBOT1.c
 *
 * Created: 6/30/2018 7:13:35 PM
 * Author : Nick Jaton
 * This program will control robot movement based off of the buttons located on the robot. 
 */ 

#include "capi324v221.h"


void CBOT_main(void)
{
	LCD_open();
	LCD_clear();
	
	//Title prints. 
	LCD_printf("6_30_2018");
	TMRSRVC_delay_sec(2);
	LCD_clear();
	
	LCD_printf("Please press a button");
	TMRSRVC_delay_sec(1);
	
	// Allows us to operate the CEENbot's motors. 
	STEPPER_open(); 
		
	// Looping Movement Function
	while (1)
	{			
		// If the left most button is pressed the robot will turn to the left. 
		if (ATTINY_get_SW_state(ATTINY_SW3) == TRUE)
		{
			STEPPER_move_stwt (STEPPER_BOTH, 
				STEPPER_REV, 150 ,200, 400, STEPPER_BRK_OFF,
				STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF);
					
		}
		
		// If the middle button is pressed the robot will drive forward. 	
		else if (ATTINY_get_SW_state(ATTINY_SW4) == TRUE)
		{
			STEPPER_move_stwt(STEPPER_BOTH,
				STEPPER_FWD, 150,200,400, STEPPER_BRK_OFF,
				STEPPER_FWD, 150,200,400, STEPPER_BRK_OFF);
		}
			
		// If the right most button is pressed the robot will turn to the right. 
		else if (ATTINY_get_SW_state(ATTINY_SW5) == TRUE)
		{
			STEPPER_move_stwt (STEPPER_BOTH,
			STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF,
			STEPPER_REV, 150, 200, 400, STEPPER_BRK_OFF);	
		}
	}
}
