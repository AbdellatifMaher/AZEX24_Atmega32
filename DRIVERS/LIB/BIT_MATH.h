/**************************************************************************************************************************/
/* Author: Abdellatif Maher                                                                                              */
/* Date:   29 NOV 2023                                                                                                  */ 
/* Version: V1                                                                                                         */
/**********************************************************************************************************************/

/* Guard File*/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BITNUM) (REG |= (1<<BITNUM)) 

#define CLR_BIT(REG,BITNUM) (REG &= (~(1<<BITNUM)))
 
#define TOG_BIT(REG,BITNUM) (REG ^= (1<<BITNUM))

#define GET_BIT(REG,BITNUM) ((REG >> (BITNUM))&1)

#endif