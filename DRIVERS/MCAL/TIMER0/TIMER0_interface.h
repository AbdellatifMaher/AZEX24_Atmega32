/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   26 Apr 2024                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/*
 * TIMER0 MODES
 */

#define TIMER0_NORMAL_MODE          0
#define TIMER0_CTC_MODE             1
#define TIMER0_PWM_Phase_MODE       2
#define TIMER0_FAST_PWM_MODE        3

/*
 * TIMER0 PreScaller
 */

#define TIMER0_NO_CLOCK       0
#define TIMER0_NO_PRE         1
#define TIMER0_8_PRE          2
#define TIMER0_64_PRE         3
#define TIMER0_256_PRE        4
#define TIMER0_1024_PRE       5
#define TIMER0_EXT_FALLING    6
#define TIMER0_EXT_RISING     7


/*
 * TIMER0 INTERRUPT
 */

#define TIMER0_INT_DISABLE    0
#define TIMER0_INT_OVERFLOW   1
#define TIMER0_INT_COMP_MATCH 2
#define TIMER0_INT_BOTH       3

/*
 * TIMER0 COMPARE MATCH OUTPUT MODE
 */
#define TIMER0_DISCONNECTED_OC0  0
#define TIMER0_TOGGLE_OC0        1
#define TIMER0_CLEAR_OC0         2
#define TIMER0_SET_OC0           3



void TIMER0_voidInit(void);
void TIMER0_voidSetCounter(u8 Copy_u8Counter);
u8  TIMER0_u16GetCounter(void);
void TIMER0_voidSetOCR(u8 Copy_u8OCR);
void TIMER0_voidClearFlag(u8 Copy_u8Interrupt);
u8   TIMER0_u8GetFlag(u8 Copy_u8Interrupt);
void TIMER0_voidDisableInterrupt(void);
void TIMER0_voidEnableInterrupt(u8 Copy_u8Interrupt);
void TIMER0_voidPWM(u8 Copy_u8TimeOn);
void TIMER0_voidmSecDelay(u64 Copy_u64MilliSeconds);
void TIMER0_voiduSecDelay(u64 Copy_u64MicroSeconds);
void TIMER0_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt );




#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
