/***********
 * Author :   Mohammed Akram
 * Date  :   22 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              22 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define MEXTI_LINE0			0
#define MEXTI_RISING_EDGE     0
#define MEXTI_FALLING_EGDE    1
#define MEXTI_ON_CHANGE       2
void EXTI_VoidInit();
void EXTI_VoidEnableInterrupt(u8 Copy_u8InterruptLine);
void EXTI_VoidDisableInterrupt(u8 Copy_u8InterruptLine);
void EXTI_VoidChangeSenceMode(u8 Copy_u8InterruptLine , u8 Copy_u8SenceSignal);
void EXTI_voidSetCallBack(u8 Copy_u8InterruptLine , void (*pNotificationFunction)(void));



#endif
