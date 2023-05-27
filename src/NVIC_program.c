/***********
 * Author :   Mohammed Akram
 * Date  :   21 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              21 MAY, 2023               Mohammed Akram
***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"



void MNVIC_VoidInit()
{
    SCB_AIRCR = (AIRCR_PRIVATE_KEY <<16) | (MNVIC_GROUP_SUB_DISTRUBUTION << 8 ) ;
}

void MNVIC_VoidEnablePeripheralInterrupt(u8 Copy_u8PerioheralId)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PerioheralId / 32 ;
    MNVIC->ISER[Local_u8ISERIndex]= (1 <<(Copy_u8PerioheralId % 32));
}

void MNVIC_VoidDisablePeripheralInterrupt(u8 Copy_u8PerioheralId)
{
     u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PerioheralId / 32 ;
    MNVIC->ICER[Local_u8ISERIndex]= (1 <<(Copy_u8PerioheralId % 32));
}
void MNVIC_VoidSetPendingFlag(u8 Copy_u8PerioheralId)
{

     u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PerioheralId / 32 ;
    MNVIC->ISPR[Local_u8ISERIndex]= (1 <<(Copy_u8PerioheralId % 32));

}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8PerioheralId)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PerioheralId / 32 ;
    MNVIC->ICPR[Local_u8ISERIndex]= (1 <<(Copy_u8PerioheralId % 32));
}
void MNVIC_VoidSetPeripheralPriority(u8 Copy_u8PerioheralId , u8 Copy_u8Priority)
{
    MNVIC->IPR[Copy_u8PerioheralId]=(Copy_u8Priority<<4);
}
