/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   29 NOV 2023                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;

    switch (Copy_u8Port)
    {
    case PORTA:DDRA_REG = Copy_u8Direction; break; 
    case PORTB:DDRB_REG = Copy_u8Direction; break;
    case PORTC:DDRC_REG = Copy_u8Direction; break;
    case PORTD:DDRD_REG = Copy_u8Direction; break;
    default: Loc_enumState = DIO_NOK; break;
    }
    return Loc_enumState;
}



DIO_ErrorStatus DIO_enumSetPinDirection(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8Direction)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;

    if( Copy_u8PinNumber >= 0 && Copy_u8PinNumber <=7 )
    {

        switch (Copy_u8Port)
        {
        case PORTA: if(Copy_u8Direction == DIO_INPUT){CLR_BIT(DDRA_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Direction == DIO_OUTPUT){SET_BIT(DDRA_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        case PORTB:if(Copy_u8Direction == DIO_INPUT){CLR_BIT(DDRB_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Direction == DIO_OUTPUT){SET_BIT(DDRB_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        case PORTC:if(Copy_u8Direction == DIO_INPUT){CLR_BIT(DDRC_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Direction == DIO_OUTPUT){SET_BIT(DDRC_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        case PORTD:if(Copy_u8Direction == DIO_INPUT){CLR_BIT(DDRD_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Direction == DIO_OUTPUT){SET_BIT(DDRD_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        default: Loc_enumState = DIO_NOK; break;
        }

    }
    else
    {
        Loc_enumState = DIO_NOK;
    }

    return Loc_enumState;
}

DIO_ErrorStatus DIO_enumSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;

    switch (Copy_u8Port)
    {
    case PORTA:PORTA_REG = Copy_u8Value; break; 
    case PORTB:PORTB_REG = Copy_u8Value; break;
    case PORTC:PORTC_REG = Copy_u8Value; break;
    case PORTD:PORTD_REG = Copy_u8Value; break;
    default: Loc_enumState = DIO_NOK; break;
    }
    return Loc_enumState;
}

DIO_ErrorStatus DIO_enumSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8Value)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;

    if( Copy_u8PinNumber >= 0 && Copy_u8PinNumber <=7 )
    {

        switch (Copy_u8Port)
        {
        case PORTA: if(Copy_u8Value == DIO_LOW){CLR_BIT(PORTA_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Value == DIO_HIGH){SET_BIT(PORTA_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        case PORTB:if(Copy_u8Value == DIO_LOW){CLR_BIT(PORTB_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Value == DIO_HIGH){SET_BIT(PORTB_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break;  
        case PORTC:if(Copy_u8Value == DIO_LOW){CLR_BIT(PORTC_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Value == DIO_HIGH){SET_BIT(PORTC_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        case PORTD:if(Copy_u8Value == DIO_LOW){CLR_BIT(PORTD_REG,Copy_u8PinNumber);} 
                    else if (Copy_u8Value == DIO_HIGH){SET_BIT(PORTD_REG,Copy_u8PinNumber);}
                    else{Loc_enumState = DIO_NOK;} break; 
        default: Loc_enumState = DIO_NOK; break;
        }

    }
    else
    {
        Loc_enumState = DIO_NOK;
    }

    return Loc_enumState;
}

DIO_ErrorStatus DIO_enumGetPortValue(u8 Copy_u8Port, u8 * Copy_ptrData)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;
    switch (Copy_u8Port)
    {
    case PORTA:*Copy_ptrData = PINA_REG; break; 
    case PORTB:*Copy_ptrData = PINB_REG; break;
    case PORTC:*Copy_ptrData = PINC_REG; break;
    case PORTD:*Copy_ptrData = PIND_REG; break;
    default: Loc_enumState = DIO_NOK; break;
    }
    return Loc_enumState;
}
DIO_ErrorStatus DIO_enumGetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 * Copy_ptrData)
{
    DIO_ErrorStatus Loc_enumState = DIO_OK;

    if( Copy_u8PinNumber >= 0 && Copy_u8PinNumber <=7 )
    {

        switch (Copy_u8Port)
        {
        case PORTA: GET_BIT(PINA_REG,Copy_u8PinNumber); break; 
        case PORTB: GET_BIT(PINB_REG,Copy_u8PinNumber);  break; 
        case PORTC: GET_BIT(PINC_REG,Copy_u8PinNumber);  break; 
        case PORTD: GET_BIT(PIND_REG,Copy_u8PinNumber);  break; 
        default: Loc_enumState = DIO_NOK; break;
        }

    }
    else
    {
        Loc_enumState = DIO_NOK;
    }

    return Loc_enumState;
}

DIO_ErrorStatus DIO_enumTogglePortValue(u8 copy_u8PORT)
{
	DIO_ErrorStatus Loc_enumState = DIO_OK;
	u8 Loc_u8Value;
	Loc_enumState = DIO_enumGetPortValue(copy_u8PORT,&Loc_u8Value);
	Loc_enumState = DIO_enumSetPortValue(copy_u8PORT, ~Loc_u8Value);
	return Loc_enumState;
}

DIO_ErrorStatus DIO_enumTogglePinValue(u8 copy_u8PORT,u8 copy_u8Pin)
{
	DIO_ErrorStatus Loc_enumState = DIO_OK;
	u8 Loc_u8Value;
	Loc_enumState = DIO_enumGetPinValue(copy_u8PORT, copy_u8Pin,&Loc_u8Value);
	Loc_enumState = DIO_enumSetPinValue(copy_u8PORT, copy_u8Pin,!Loc_u8Value);
	return Loc_enumState;
	
}

