/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   9 DEC 2023                                                                                                   */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "BUTTON_interface.h"
#include "BUTTON_config.h"
#include "BUTTON_private.h"
#include "DIO_interface.h"

void BUTTON_voidInit( BUTTON_Type Button_enumConfiguration)
{
    DIO_enumSetPinDirection(Button_enumConfiguration.Port,Button_enumConfiguration.Pin,DIO_INPUT);
    DIO_enumSetPinValue(Button_enumConfiguration.Port,Button_enumConfiguration.Pin,Button_enumConfiguration.Pull_state);
}
u8   BUTTON_u8GetPressed(BUTTON_Type Button_enumConfiguration)
{
    u8 Loc_u8Result;
    DIO_enumGetPinValue(Button_enumConfiguration.Port,Button_enumConfiguration.Pin,&Loc_u8Result);
    return Loc_u8Result;
}