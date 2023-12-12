/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   29 NOV 2023                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"

/* DIO PORTS */
#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3


/* DIO PINS*/

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

/* DIO Direction */

#define DIO_INPUT  0
#define DIO_OUTPUT 1

/* DIO OUTPUT Value */
#define DIO_LOW  0
#define DIO_HIGH 1

/* DIO Input Circuits*/

#define DIO_INPUT_FLOATING 0
#define DIO_INPUT_PULLUP   1

/* enum */

typedef enum
{
    DIO_NOK,
    DIO_OK
}DIO_ErrorStatus;



DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8Direction);

DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8Value);

DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8Port, u8 * Copy_ptrData);
DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 * Copy_ptrData);

DIO_ErrorStatus DIO_enumTogglePortValue(u8 copy_u8PORT);
DIO_ErrorStatus DIO_enumTogglePinValue(u8 copy_u8PORT,u8 copy_u8Pin);

#endif