/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef  SYSTICK_INTERFACE_H
#define  SYSTICK_INTERFACE_H


void SYSTICK_VoidInit(void);
void SYSTICK_VoidEnableInterrupt(void);
void SYSTICK_VoidDisableInterrupt(void);
void SYSTICK_VoidEnableSystick(void);
void SYSTICK_VoidDisableSystick(void);
void SYSTICK_VoidBusyWait(u32 Copy_u32WAitTime);
void SYSTICK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));
u32 MSTK_u32GetElapsedTime(void);





#endif
