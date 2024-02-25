/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   25 FEB 2024                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI_CallBack[3]) (void) = { NULL } ;

void EXTI_voidInit( void )
{
#ifdef EXTI_LINE

		#if EXTI_LINE == EXTI_LINE1
				DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN3,DIO_INPUT);

			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR , 2 ); CLR_BIT( MCUCR , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR , 2 ); CLR_BIT( MCUCR , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR , 2 ); SET_BIT( MCUCR , 3 );
				DIO_enumSetPinValue(DIO_PORTD, DIO_PIN3,DIO_HIGH);

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR , 2 ); SET_BIT( MCUCR , 3 );

			#endif


		#elif EXTI_LINE == EXTI_LINE0

			DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN2,DIO_INPUT);
			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR , 0 ); CLR_BIT( MCUCR , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR , 0 ); CLR_BIT( MCUCR , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR , 0 ); SET_BIT( MCUCR , 1 );
				DIO_enumSetPinValue(DIO_PORTD, DIO_PIN2,DIO_HIGH);

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR , 0 ); SET_BIT( MCUCR , 1 );

			#endif

		#elif EXTI_LINE == EXTI_LINE2
				DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN2,DIO_INPUT);

				#if     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

					CLR_BIT( MCUCSR , 6 );
					DIO_enumSetPinValue(DIO_PORTB, DIO_PIN2,DIO_HIGH);

				#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

					SET_BIT( MCUCSR , 6 );

				#endif

		#endif

	#endif
}

void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line ){

	if( Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1 ){

		Copy_u8Line = ( 6 - Copy_u8Line ) * -2 ;

		switch( Copy_u8SenseMode ){

		case EXTI_LOW_LEVEL    : CLR_BIT( MCUCR , Copy_u8Line ); CLR_BIT( MCUCR , (Copy_u8Line + 1) ); break;
		case EXTI_ON_CHANGE    : SET_BIT( MCUCR , Copy_u8Line ); CLR_BIT( MCUCR , (Copy_u8Line + 1) ); break;
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCR , Copy_u8Line ); SET_BIT( MCUCR , (Copy_u8Line + 1) );
								 if(Copy_u8Line == 0){DIO_enumSetPinValue(DIO_PORTD, DIO_PIN2,DIO_HIGH);}
								 else{DIO_enumSetPinValue(DIO_PORTD, DIO_PIN3,DIO_HIGH);}break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCR , Copy_u8Line ); SET_BIT( MCUCR , (Copy_u8Line + 1) ); break;

		}

	}

	else{

		switch( Copy_u8SenseMode ){

		case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR , 6 );DIO_enumSetPinValue(DIO_PORTB, DIO_PIN2,DIO_HIGH);break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCSR , 6 );  break;

		}

	}

}

void EXTI_voidDisableInterrupt   ( u8 Copy_u8Line ){

	CLR_BIT( GICR , Copy_u8Line );

}

void EXTI_voidEnableInterrupt    ( u8 Copy_u8Line ){

	SET_BIT( GICR , Copy_u8Line );

}
void EXTI_voidClearFlag ( u8 Copy_u8Line ){

	SET_BIT( GIFR , Copy_u8Line );

}

u8 EXTI_u8GetFlag( u8 Copy_u8Line ){

	return GET_BIT( GIFR , Copy_u8Line );

}


void EXTI_voidSetCallBack( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine ){

	if( Copy_pvoidCallBack != NULL ){

		EXTI_CallBack[Copy_u8EXTILine - 5] = Copy_pvoidCallBack ;

	}

}
void EXTI_voidDisableGlobalInterrupt  (void)
{
	SREG &=0b01111111;
}
void EXTI_voidEnableGlobalInterrupt   (void)
{
	SREG |=0b10000000;
}

/* ISR --> Implementation */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[1] != NULL ){

		EXTI_CallBack[1]();
		EXTI_voidClearFlag( EXTI_LINE0 );

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[2] != NULL ){

		EXTI_CallBack[2]();
		EXTI_voidClearFlag( EXTI_LINE1 );

	}

}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if( EXTI_CallBack[0] != NULL ){

		EXTI_CallBack[0]();
		EXTI_voidClearFlag( EXTI_LINE2 );

	}

}
