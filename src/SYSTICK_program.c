/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


static void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;

void SYSTICK_VoidInit(void)
{
    #if SYSTICK_CLOCK_SOURCE == AHB1_CLOCK_SOURCE_DIVIDE_8
            CLEAR_BIT(STK_CTRL , STK_CTRL_CLKSOURCE);
    #elif SYSTICK_CLOCK_SOURCE == AHB1_CLOCK_SOURCE
             SET_BIT(STK_CTRL , STK_CTRL_CLKSOURCE);
    #else
        //error
    #endif

    /*enable peripheral*/
    #if SYSTICK_ENABLE  == ENABLE
        SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
    #elif SYSTICK_ENABLE  == DISABLE
        CLEAR_BIT(STK_CTRL,STK_CTRL_ENABLE);
    #endif

     #if SYSTICK_INTERRUPT  == ENABLE
        /*enable peripheral intterupt*/
        SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
    #elif SYSTICK_INTERRUPT  == DISABLE
        CLEAR_BIT(STK_CTRL,STK_CTRL_TICKINT);
    #endif
    
   
   
}
void SYSTICK_VoidEnableInterrupt(void)
{
    /*enable peripheral intterupt*/
    SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
}
void SYSTICK_VoidDisableInterrupt(void)
{
    /*enable peripheral intterupt*/
    CLEAR_BIT(STK_CTRL,STK_CTRL_TICKINT);
}
void SYSTICK_VoidEnableSystick(void)
{
    SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
}
void SYSTICK_VoidDisableSystick(void)
{
    CLEAR_BIT(STK_CTRL,STK_CTRL_ENABLE);
}

void SYSTICK_VoidBusyWait(u32 Copy_u32WAitTime)
{
    STK_LOAD = Copy_u32WAitTime;
    while (GET_BIT(STK_CTRL ,STK_CTRL_COUNTFLAG )==0);
    STK_VAL = 0 ;   
}
void SYSTICK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	/*Disable STK*/
	CLEAR_BIT(STK_CTRL, 0);
	/*Reset STK*/
	STK_VAL = 0;

	/*Set PreLoad Value*/
	STK_LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL;

	/*Enable STK Interrupt*/
	SET_BIT(STK_CTRL, 1);
	/*Enable STK*/
	SET_BIT(STK_CTRL, 0);
}
u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK_LOAD - STK_VAL;
	return Local_u32ElapsedTime;
}
void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		STK_LOAD = 0;
		STK_VAL = 0;
		CLEAR_BIT(STK_CTRL, 0);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT(STK_CTRL, 16);
}
