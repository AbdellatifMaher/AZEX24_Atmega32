/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   2021                                                                                                         */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_extrachar.h"
#include "util/delay.h"

void CLCD_voidInit        ( void ){

	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_OUTPUT  );
	
	#if EIGHT_BITDATA
		/* Set the Direction of the 8 Data pins to Output */
		DIO_enumSetPortDirection ( CLCD_DATA_PORT    , 255);
	#else
			
			#if UPPER_DATA_PORT
				/* Set The Direction of The Upper Pins to OP*/
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN4 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN5 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN6 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN7 , DIO_OUTPUT);
			#else
				/* Set The Direction of The LOWER Pins to OP*/
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN0 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN1 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN2 , DIO_OUTPUT);
			DIO_enumSetPinDirection( CLCD_DATA_PORT, DIO_PIN3 , DIO_OUTPUT);
			#endif
			CLCD_voidSendCommend(Return_Home);
	#endif
	
	_delay_ms(50);
	/*FUNCTION SET COMMEND*/
	CLCD_voidSendCommend( Data_Set );
	_delay_ms(1);
	/* DISPLAY ON / OFF */
	CLCD_voidSendCommend( Display_on );
	_delay_ms(1);
	/* DISPLAY CLEAR */
	CLCD_voidSendCommend( Clear_display );
	_delay_ms(2);
	/* DISPLAY ENTRY MODE */
	CLCD_voidSendCommend( Return_Home );
	_delay_ms(1);

}
void CLCD_voidClear        ( void )
{

	/* Clear Screen */
	CLCD_voidSendCommend( Clear_display );

}

void CLCD_voidSendData    ( u8 Copy_u8Data ){


	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_LOW  );

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
	_delay_ms(1);
	
	#if EIGHT_BITDATA		
			DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data );
			/* Data set-up time delay  Tdsw = 195 ns */
				_delay_ms(1);
	#else 
			u8 LOC_u8SendPins;
			u8 LOC_u8Temp;
			DIO_enumGetPortValue( CLCD_DATA_PORT , &LOC_u8SendPins);
			#if UPPER_DATA_PORT
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0x0F ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				/* Send MSB (4-bits )*/
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Data & 0xF0 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0xF0 ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				/* Send MSB (4-bits )*/
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Data >> 4 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			#endif
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1);
		
			/* disable LCD E=0 */
			DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
			/* Data Hold delay Th = 10ns */
			_delay_ms(1);
			
			/* Enable LCD E=1 */
			DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
			/* delay for processing PW min 450ns */
			_delay_ms(1);
			
			#if UPPER_DATA_PORT
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0x0F ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Data << 4 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0xF0 ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Data & 0x0F ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			#endif
				/* Data set-up time delay  Tdsw = 195 ns */
				_delay_ms(1);
	#endif
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
	_delay_ms(1);

}

void CLCD_voidSendCommend ( u8 Copy_u8Commend ){

	
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_LOW  );
	/* Delay of Address Set 60ns minimum  ~~ */
	_delay_ms(1);
	
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
	/* Data Hold delay Th = 10ns */
	_delay_ms(1);
	
	#if EIGHT_BITDATA		
			DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Commend     );
			/* Data set-up time delay  Tdsw = 195 ns ~~ */
			_delay_ms(1); 
	#else 
			u8 LOC_u8SendPins;
			u8 LOC_u8Temp;
			DIO_enumGetPortValue( CLCD_DATA_PORT , &LOC_u8SendPins);
			#if UPPER_DATA_PORT
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0x0F ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Commend & 0xF0 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0xF0 ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Commend >> 4 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			#endif
			/* Data set-up time delay  Tdsw = 195 ns */
			_delay_ms(1);
		
			/* disable LCD E=0 */
			DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
			/* Data Hold delay Th = 10ns */
			_delay_ms(1);
			
			/* Enable LCD E=1 */
			DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_HIGH );
			/* delay for processing PW min 450ns */
			_delay_ms(1);
			#if UPPER_DATA_PORT
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0x0F ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Commend << 4 ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			
			#else	/* Lower Port */
				/* clear the Prev Data */
				LOC_u8Temp = LOC_u8SendPins & 0xF0 ;
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8Temp     );
				LOC_u8SendPins = (LOC_u8Temp | (Copy_u8Commend & 0x0F ) );
				DIO_enumSetPortValue ( CLCD_DATA_PORT    , LOC_u8SendPins     );
			#endif
				/* Data set-up time delay  Tdsw = 195 ns */
				_delay_ms(1);
		#endif
	
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_LOW  );
	_delay_ms(1);


}


void CLCD_voidSendString  ( u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}


void CLCD_voidSendNumber   ( u64 Copy_s64Number    ){

	u64 LOC_u64Reversed = 1 ;
	if( Copy_s64Number == 0 ){ CLCD_voidSendData('0'); }

	else{

		while( Copy_s64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_s64Number % 10 );
			Copy_s64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}
void CLCD_voidSendFloatNumber   ( f64 Copy_f64Number    )
{
	CLCD_voidSendNumber((u64)Copy_f64Number);
	if((((u64)(Copy_f64Number * 100)) % 100) != 0 )
	{
		CLCD_voidSendData('.');
		CLCD_voidSendNumber((((u64)(Copy_f64Number * 100)) % 100));
	}
}


void CLCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	if( Copy_u8Row == CLCD_ROW_1 ){

		CLCD_voidSendCommend( ( DDRAM_CONST ) + ( Copy_u8Col - 1 ) ); // DDRAM_CONST = 0x80

	}else if( Copy_u8Row == CLCD_ROW_2 ){

		CLCD_voidSendCommend( ( DDRAM_CONST ) + (64) + ( Copy_u8Col - 1 ) );

	}

}



void CLCD_voidSendExtraChar( void ){

	u8 LOC_u8Iterator = 0 ;
	/* 1- Go To CGRAM            */
	CLCD_voidSendCommend( CGRAM_CONST ); // CGRAM_CONST = 0x40
	/* 2- Draw Character         */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; LOC_u8Iterator++){

		CLCD_voidSendData( CLCD_u8ExtraChar[LOC_u8Iterator] );

	}

	/* 3- Back To DDRAM          */
		CLCD_voidSetPosition(1,1);
}

void CLCD_voidDisplayExtraChar( u8 Copy_u8CharNumber , u8 Copy_u8Row , u8 Copy_u8Col )
{
	/* 1- Set Position        */
	CLCD_voidSetPosition(Copy_u8Row,Copy_u8Col);

	/* 2- Send Character Address (Addresses of CGRAM start from 0) */

		CLCD_voidSendData( Copy_u8CharNumber );

}

