/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   2021                                                                                                         */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

/* List Of Command Codes */

#define Clear_display 				0x01
#define Return_Home	  				0x02
#define Display_off   				0x08
#define Display_on   			   (0x0C | (CURSOR<<1) | (BLINK))
#define CURSOR_Shift_Right	 		0x14
#define CURSOR_Shift_left	 		0x10
#define Display_shift_left    		0x18
#define Display_shift_Right	  		0x1C
#define Data_Set 				   (0x20 |(_5x10_DOT<<2)|(TWO_LINES<<3)| (EIGHT_BITDATA<<4))
#define DDRAM_CONST 				0x80
#define CGRAM_CONST 				0x40


#endif /* CLCD_PRIVATE_H_ */
