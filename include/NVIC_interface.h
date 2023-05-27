/***********
 * Author :   Mohammed Akram
 * Date  :   21 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              21 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define MNVIC_EXTI0     6

#define MNVIC_EXTI1     7


void MNVIC_VoidInit();

void MNVIC_VoidEnablePeripheralInterrupt(u8 Copy_u8PerioheralId);

void MNVIC_VoidDisablePeripheralInterrupt(u8 Copy_u8PerioheralId);

void MNVIC_VoidSetPendingFlag(u8 Copy_u8PerioheralId);

void MNVIC_VoidClearPendingFlag(u8 Copy_u8PerioheralId);

u8 MNVIC_u8GetActivateFlag(u8 Copy_u8PerioheralId);


void MNVIC_VoidSetPeripheralPriority(u8 Copy_u8PerioheralId , u8 Copy_u8Priority);



#endif
