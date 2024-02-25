/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   25 FEB 2024                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_LINE0  6
#define EXTI_LINE1  7
#define EXTI_LINE2  5


#define EXTI_LOW_LEVEL    0
#define EXTI_ON_CHANGE    1
#define EXTI_FALLING_EDGE 2
#define	EXTI_RISING_EDGE  3

void EXTI_voidInit              ( void );
void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line );
void EXTI_voidDisableInterrupt  ( u8 Copy_u8Line );
void EXTI_voidEnableInterrupt   ( u8 Copy_u8Line );
void EXTI_voidClearFlag         ( u8 Copy_u8Line );

void EXTI_voidSetCallBack       ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );

void EXTI_voidDisableGlobalInterrupt  (void);
void EXTI_voidEnableGlobalInterrupt   (void);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
