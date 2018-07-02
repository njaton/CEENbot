/*
 * New_CEENbot1.c
 *
 * Created: 7/1/2018 
 * Author : Nick Jaton
 *
 * In case the Libraries do not work. You need "libcapi324v22x" and "libprintf_flt"
 * 
 * This program is made to replicate the function of the "Bump Bot" function on the initial 
 * firmware of the robot. The robot will start to drive forward once the middle button
 * is pressed. If one (or both) of the sensors detect that the robot will run into something
 * the robot will back up and make a left turn. The middle button will stop the robot. 
 */ 

#include "capi324v221.h"


void CBOT_main(void)
{
	//The LCD, Stepper and Attiny all need to be opened. 
    LCD_open();
	LCD_clear();
	
	ATTINY_open();
	
	STEPPER_open();
	
    while (1) 
    {
		TMRSRVC_delay_ms(100); 
		
		//Confirm that the robot is displaying the values of the sensors. 
		int sensors = ATTINY_get_sensors();
		
		LCD_printf("%d\n", sensors);
		
		//This if statement is the main command of the firmware. 
		if (ATTINY_get_SW_state(ATTINY_SW4) == TRUE)
		{	
			TMRSRVC_delay_ms(500);
			
			//This while loop will function unless the middle button is pressed again. 
			while (ATTINY_get_SW_state(ATTINY_SW4) == FALSE)
			{	
				//Move Forward.
				STEPPER_move_stwt (STEPPER_BOTH,
				STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF,
				STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF);
				
				//Check for walls and things. 
				int sensors = ATTINY_get_sensors();
				LCD_printf("%d\n", sensors);
				
				//If something is detected the this action begins. 
				if (sensors == 1 || sensors == 2 || sensors == 3)
				{
					LCD_printf("%d\n", sensors);
					
					//Move Backwards.
					STEPPER_move_stwt (STEPPER_BOTH,
					STEPPER_REV, 150, 200, 400, STEPPER_BRK_OFF,
					STEPPER_REV, 150, 200, 400, STEPPER_BRK_OFF);
					
					//Turn
					STEPPER_move_stwt (STEPPER_BOTH,
					STEPPER_REV, 150 ,200, 400, STEPPER_BRK_OFF,
					STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF);
				}
			}
			
		}
		
    }
}
