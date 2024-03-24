/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   2021                                                                                                         */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* D0 ------> D7 */

/*

  Options:-
 	 1-DIO_PORTA
 	 2-DIO_PORTB
 	 3-DIO_PORTC
 	 4-DIO_PORTD

 */


#define CLCD_DATA_PORT      DIO_PORTB
/* RS,RW,EN */
#define CLCD_CONTROL_PORT   DIO_PORTC

/*

 Options:-
 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 */
#define CLCD_RS             DIO_PIN0
#define CLCD_RW             DIO_PIN1
#define CLCD_EN             DIO_PIN2


/* Init Settings */
#define CURSOR			1		/* 1 to Enable , 0 to Disable */
#define BLINK			1		/* 1 to Enable , 0 to Disable */
#define EIGHT_BITDATA 	1 		/* 1 to Enable , 0 for 4 bit */
#define _5x10_DOT	 	0		/* 1 to Enable , 0 for 5 x 8 Dot */
#define TWO_LINES	 	1		/* 1 to Enable , 0 for 1 Line */

/* Define Upper Data to Use The Higher 4 Pins PD4 --> PD7 */
#if EIGHT_BITDATA == 0
	#define UPPER_DATA_PORT 1  /* 1 for Upper pins , 0 for Lower pins */
#endif          

#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
