/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   25 FEB 2024                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)
#define SREG   *((volatile u8 *)0x5F)

#define NULL 0


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
