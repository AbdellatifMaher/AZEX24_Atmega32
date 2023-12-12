/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   9 DEC 2023                                                                                                   */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "STD_TYPES.h"


/* Pull state */
#define BUTTON_FLOATING 0
#define BUTTON_PULLUP   1

typedef struct 
{
    u8 Port;
    u8 Pin;
    u8 Pull_state;
}BUTTON_Type;


void BUTTON_voidInit( BUTTON_Type Button_enumConfiguration);
u8   BUTTON_u8GetPressed(BUTTON_Type Button_enumConfiguration);

#endif