/***********
 * Author :   Mohammed Akram
 * Date  :   22 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              22 MAY, 2023               Mohammed Akram
***************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void(*pvCallBack[16])(void)={{NULL}};

void EXTI_VoidEnableInterrupt(u8 Copy_u8InterruptLine)
{
    if (Copy_u8InterruptLine >15)
    {

    }
    
    SET_BIT(EXTI->IMR ,Copy_u8InterruptLine );
}
void EXTI_VoidDisableInterrupt(u8 Copy_u8InterruptLine)
{
    if (Copy_u8InterruptLine >15)
    {

    }
    CLEAR_BIT(EXTI->IMR ,Copy_u8InterruptLine );
}
void EXTI_VoidChangeSenceMode(u8 Copy_u8InterruptLine , u8 Copy_u8SenceSignal)
{   

        switch (Copy_u8SenceSignal)
         {
            case  MEXTI_RISING_EDGE :
                SET_BIT(EXTI->RTSR ,Copy_u8InterruptLine );
                CLEAR_BIT(EXTI->FTSR ,Copy_u8InterruptLine );
            
            break;
            case  MEXTI_FALLING_EGDE :
                CLEAR_BIT(EXTI->RTSR ,Copy_u8InterruptLine );
                SET_BIT(EXTI->FTSR ,Copy_u8InterruptLine );
            
            break;
            case  MEXTI_ON_CHANGE :
                SET_BIT(EXTI->RTSR ,Copy_u8InterruptLine );
                SET_BIT(EXTI->FTSR ,Copy_u8InterruptLine );
            
            break;
        
        default:
            break;
        }

}
void EXTI_voidSetCallBack(u8 Copy_u8InterruptLine , void (*pNotificationFunction)(void))
{

    if(Copy_u8InterruptLine > 15)
    {

    }

        pvCallBack[Copy_u8InterruptLine]=pNotificationFunction;

}


void EXTI0_IRQHandler(void)
{
    if(pvCallBack[0] != NULL)
    {
        pvCallBack[0]();
    }
    SET_BIT((EXTI->PR),0);
    
}
void EXTI1_IRQHandler(void)
{
    if(pvCallBack[1] != NULL)
    {
        pvCallBack[1]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI2_IRQHandler(void)
{
    if(pvCallBack[2] != NULL)
    {
        pvCallBack[2]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI3_IRQHandler(void)
{
    if(pvCallBack[3] != NULL)
    {
        pvCallBack[3]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI4_IRQHandler(void)
{
    if(pvCallBack[4] != NULL)
    {
        pvCallBack[4]();
    }
}
void EXTI5_IRQHandler(void)
{
    if(pvCallBack[5] != NULL)
    {
        pvCallBack[5]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI6_IRQHandler(void)
{
    if(pvCallBack[6] != NULL)
    {
        pvCallBack[6]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI7_IRQHandler(void)
{
    if(pvCallBack[7] != NULL)
    {
        pvCallBack[7]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI8_IRQHandler(void)
{
    if(pvCallBack[8] != NULL)
    {
        pvCallBack[8]();
    }
    SET_BIT((EXTI->PR),0);
}
void EXTI9_IRQHandler(void)
{
    if(pvCallBack[9] != NULL)
    {
        pvCallBack[9]();
    }
    SET_BIT((EXTI->PR),0);

}
void EXTI10_IRQHandler(void)
{
    if(pvCallBack[10] != NULL)
    {
        pvCallBack[10]();
    }
    SET_BIT((EXTI->PR),0);

}
void EXTI11_IRQHandler(void)
{
    if(pvCallBack[11] != NULL)
    {
        pvCallBack[11]();
    }
    SET_BIT((EXTI->PR),0);
}
