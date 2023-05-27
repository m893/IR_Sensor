/***********
 * Author :   Mohammed Akram
 * Date  :   26 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              26 MAY, 2023               Mohammed Akram
***************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"


#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

void APP_GetFrame(void);
void APP_TakeAction(void);


u8 StartEgdeFlag=0;
u8 App_u8ButtonData = 0;
u8  APP_u8StartEdgeFlag = 0;
u32 APP_u32ReceivedFrame[50] = {0};
u8  APP_u8EdgeCounter = 0;


void HIR_VoidInit()
{
    /* enable the port of pin that connect to IR*/
    MRCC_VoidInit();
    MRCC_VoidEnablePeriperalClock(RCC_AHB1,PORT_NAME);
    /*SET MODE OF THE PIN OF IR */
    MGPIO_VoidSetOutPutType(PORT_NAME,PIN0 , INPUT);
    MGPIO_VoidSetPinConnectiontype(GPIO_A,PIN0 , PULL_UP);

    /* INIT SYSTICK */
    SYSTICK_VoidInit();

    /* ENABLE NVIC PREPHERAL INTERRUPT */
    MNVIC_VoidInit();
    MNVIC_VoidEnablePeripheralInterrupt(MNVIC_EXTI0);

    /* ENABLE EXTERNAL INTERRUPT AND SENCE MODE*/
    EXTI_VoidChangeSenceMode(MEXTI_LINE0,MEXTI_FALLING_EGDE);
	EXTI_voidSetCallBack(MEXTI_LINE0 , & APP_GetFrame);
	EXTI_VoidEnableInterrupt(MEXTI_LINE0);

}

void APP_GetFrame(void)
{
	if(APP_u8StartEdgeFlag == 0)
	{
		SYSTICK_voidSetSingleInterval(70000, &APP_TakeAction);
		APP_u8StartEdgeFlag = 1;
	}
	else
	{
		/*count time from falling edge to second falling edge*/
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/*reset  the timer*/
		SYSTICK_voidSetSingleInterval(70000, &APP_TakeAction);
		/*increament to store in the next element in array*/
		APP_u8EdgeCounter++;
	}
}
void APP_TakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
		/*	if the number of index  less 1500 and more 1000 so the number is zero */
		if((APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
				(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			CLEAR_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
	}
	APP_u8StartEdgeFlag = 0;
	APP_u8EdgeCounter = 0;

}

u8 HIR_u8GetPressedButton()
{
	return App_u8ButtonData;
}
