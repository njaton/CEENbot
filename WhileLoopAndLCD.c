/*
 * CEENBOT2.c
 *
 * Created: 6/30/2018 7:13:35 PM
 * Author : Nick Jaton
 * In case the Libraries do not work. You need "libcapi324v22x" and "libprintf_flt"
 * This program is quick review of C using the CEENbot API. 
 */ 

#include "capi324v221.h"


void CBOT_main(void)
{
	// Open the LCD of the CEENbot and clear the LCD. 
	LCD_open();
	LCD_clear();
	
	// Start the firmware.
    while (1)
	{
		// The count for the upcoming loop.  
		int i = 0;
		
		//Title prints. 
		LCD_printf("6_30_2018");
		TMRSRVC_delay_sec(1);
		LCD_clear();
		LCD_printf("C Review");
		TMRSRVC_delay_sec(1);
		LCD_clear();
		
		// Explain operation of the program. 
		LCD_printf("The following does X * Y");
		TMRSRVC_delay_sec(1);
		LCD_clear();
		LCD_printf("The count of the loop will be added to x");
		TMRSRVC_delay_sec(2);
		LCD_clear();
		LCD_printf("This code will loop 5 times before starting over");
		TMRSRVC_delay_sec(2);
		LCD_clear();
		
		// Looping the math function.
		while (i <= 5)
		{
			int x = 2 + i;
			int y = 5;
			int z = x * y;
	
			LCD_printf("X = %d, Y + %d", x, y);
			TMRSRVC_delay_ms(500);
			LCD_clear();
			LCD_printf("X * Z = %d", z);
			TMRSRVC_delay_sec(1);
			LCD_clear();
			
			i = i + 1; 
		}
	}
}

