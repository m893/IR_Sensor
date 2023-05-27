/***********
 * Author :   Mohammed Akram
 * Date  :   1 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              1  MAY, 2023               Mohammed Akram
***************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/*this function to select the source of system clock cycle */
void MRCC_VoidInit(void)
{
    #if CPU_CLK_SOURCE == HSI
                 /*enable HSI*/
            SET_BIT(RCC -> CR , 0);
              /* select hsi as system clock*/
            CLEAR_BIT(RCC-> CFGR ,0);
            CLEAR_BIT(RCC-> CFGR ,1);
    #elif CPU_CLK_SOURCE == HSE
             #if HSE_CLOCK_SOURCE == NOT_BYPASSED
                 CLEAR_BIT(RCC -> CR , 18);
             #elif HSE_CLOCK_SOURCE == BYPASSED
                 SET_BIT(RCC -> CR , 18);
             #else
                 /*ERROR*/
            #endif
         /*enable HSE*/
         SET_BIT(RCC->CR , 16);
          /* select hse as system clock*/
         SET_BIT(RCC-> CFGR ,0);
         CLEAR_BIT(RCC-> CFGR ,1);
    #elif CPU_CLK_SOURCE == PLL
        #if PLL_SOURCE== HSI
            
        #elif PLL_SOURCE== HSE
        #else
            #error  "PLL_SOURCE configration error"
        #endif
    #else
        #error "CPU_CLK_SOURCE configration error"
    #endif

    RCC-> CFGR |= (AHB_PRESCALER << 4);

}
    /* ENABLE THE PERIPERAL BY PASSING THE BUS THAT PERIAPERAL IN AND PERIPHERAL ID */
void MRCC_VoidEnablePeriperalClock(u8 Copy_u8PeriperalBus , u8 Copy_u8PeriperalId)
{

    switch (Copy_u8PeriperalBus)
    {
         /* SWITCH IN  BUSES AND   ENABLE PERIPERAL THAT IN THIS BUS BY PASSING PERIAPERAL ID
                 IN THIS BUS BY SET THE BIT OF PERIPERAL 
                 */
    case RCC_AHB1 :
                    SET_BIT(RCC->AHB1ENR , Copy_u8PeriperalId );
        break;
    case RCC_AHB2 :
                    SET_BIT(RCC->AHB2ENR , Copy_u8PeriperalId );
        break;
    case RCC_APB1 :
                    SET_BIT(RCC->APB1ENR , Copy_u8PeriperalId );
        break;
    case RCC_APB2 :
                    SET_BIT(RCC->APB2ENR , Copy_u8PeriperalId );
        break;
    default:
               // #error"INCORRECT PERIPHERAL BUS ";
        break;
    }

}
/* DISABLE THE PERIPERAL BY PASSING THE BUS THAT PERIAPERAL IN AND PERIPHERAL ID */
void MRCC_VoidDisablePeriperalClock(u8 Copy_u8PeriperalBus , u8 Copy_u8PeriperalId)
{
    /* SWITCH IN  BUSES AND   ENABLE PERIPERAL THAT IN THIS BUS BY PASSING PERIAPERAL ID
                 IN THIS BUS BY CLEAR THE BIT OF PERIPERAL 
                 */
    switch (Copy_u8PeriperalBus)
    {
    case RCC_AHB1 :
                    CLEAR_BIT(RCC->AHB1ENR , Copy_u8PeriperalId );
        break;
    case RCC_AHB2 :
                    CLEAR_BIT(RCC->AHB2ENR , Copy_u8PeriperalId );
        break;
    case RCC_APB1 :
                    CLEAR_BIT(RCC->APB1ENR , Copy_u8PeriperalId );
        break;
    case RCC_APB2 :
                    CLEAR_BIT(RCC->APB2ENR , Copy_u8PeriperalId );
        break;
    default:
               // #error"INCORRECT PERIPHERAL BUS ";
        break;
    }

}

