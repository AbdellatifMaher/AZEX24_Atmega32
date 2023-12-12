/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   9 DEC 2023                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#include ".STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidInit  ( LED_Type LED_Configuration )
{
	DIO_enumSetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , DIO_OUTPUT);
}
void LED_voidOn    ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_HIGH);
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_LOW );
	}
}
void LED_voidOff   ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_LOW );
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		DIO_enumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_HIGH);
	}	
}
void LED_voidToggle( LED_Type LED_Configuration )
{
	DIO_enumTogglePinValue(LED_Configuration.Port , LED_Configuration.Pin );
}
