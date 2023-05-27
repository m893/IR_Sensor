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

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"


/* SELECT PIN MODE OPTIONS : INPUT ,OUTPUT , ALTERNATIVE FUNCTION , ANALOG */

void MGPIO_VoidSetPinMode(u8 Copy_u8PortName  , u8 Copy_u8GPIOPin , u8 Copy_u8Mode)
{
    /*EVERY PIN HAS TWO BIT 2* NUMBER OF PIN AND (2*NUMBER OF PIN) +1*/
    /*
        00 : INPUT MODE
        01 :OUTPUT MODE
        10 :ALTERNATIVE FUNCTION
        11 : ANALOG 
    */
    switch (Copy_u8PortName)
    {
    case GPIO_A:
    
        switch (Copy_u8Mode)
        {
        case INPUT:
        /*00*/
        CLEAR_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case OUTPUT:
       /*01*/ 
        SET_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case ALTRNATIVE_FUN:
       /*10*/ 
        CLEAR_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case ANALOG:
       /*11*/ 
        SET_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }

        break;

   
    case GPIO_B:
    
        switch (Copy_u8Mode)
        {
        case INPUT:
        CLEAR_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case OUTPUT: 
        SET_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case ALTRNATIVE_FUN:
        CLEAR_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case ANALOG: 
        SET_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
        break;
        
    /*P13,P14,P15 ONLY*/
    case GPIO_C:
    
        switch (Copy_u8Mode)
        {
        case INPUT:
        CLEAR_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case OUTPUT: 
        SET_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        CLEAR_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case ALTRNATIVE_FUN: 
        CLEAR_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
             
       case ANALOG: 
        SET_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
        break;
        
    
    default:
    /*Return Error*/
        break;
    }

}
void MGPIO_VoidSetOutPutType(u8 Copy_u8PortName  , u8 Copy_u8PinNum , u8 Copy_u8OutPutType)
{

    /* PUSH_PULL  OR OPEN DRAIN PIN AS OUTPUT  */
    switch(Copy_u8PortName)
    {
        case GPIO_A :
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                        CLEAR_BIT(GPIOA -> OTYPER , Copy_u8PinNum);
                break;
             case OPEN_DRAIN :
                        SET_BIT(GPIOA -> OTYPER , Copy_u8PinNum);
                break;
            default:
                break;
            }
         break;
         case GPIO_B:
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                        CLEAR_BIT(GPIOB -> OTYPER , Copy_u8PinNum);
                break;
             case OPEN_DRAIN :
                        SET_BIT(GPIOB -> OTYPER , Copy_u8PinNum);
                break;
            default:
                break;
            }
         break;
         case GPIO_C :
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                        CLEAR_BIT(GPIOC -> OTYPER , Copy_u8PinNum);
                break;
             case OPEN_DRAIN :
                        SET_BIT(GPIOC -> OTYPER , Copy_u8PinNum);
                break;
            default:
                break;
            }
         break;
         default:
            
         break;
    }

}
void MGPIO_VoidSetOutPutSpeed(u8 Copy_u8PortName  , u8 Copy_u8GPIOPin , u8 Copy_u8OutPutSpeed)
{
    /*
        OPTIONS :
            LOW : 00
            MEDUIM : 01
            HIGH : 10 
            VERY HIGH : 11
    */
    switch (Copy_u8PortName)
    {
     case GPIO_A :
            switch (Copy_u8OutPutSpeed)
            {
            case LOW_SPEED :
                        CLEAR_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
                        CLEAR_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                break;
             case MEDIUMM_SPEED :
                         SET_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
                         CLEAR_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                break;
             case HIGH_SPEED :
                         CLEAR_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
                         SET_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                break;
             case VERY_HIGH_SPEED :
                        SET_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
                        SET_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                break;
                 default:
                break;
            }
            break;
        case GPIO_B :
                    switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                                CLEAR_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case MEDIUMM_SPEED :
                                SET_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case HIGH_SPEED :
                                CLEAR_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case VERY_HIGH_SPEED :
                                SET_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                        default:
                        break;
                    }
            break;
             case GPIO_C :
                    switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                                CLEAR_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case MEDIUMM_SPEED :
                                SET_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case HIGH_SPEED :
                                CLEAR_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                    case VERY_HIGH_SPEED :
                                SET_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
                        break;
                        default:
                        break;
                    }
                break;    
        default:
            break;
    }
  
}
                /*    pullup  pulldown*/
void MGPIO_VoidSetPinConnectiontype(u8 Copy_u8PortName  , u8 Copy_u8PinNum , u8 Copy_u8ConnectionType)
{
    switch (Copy_u8PortName)
    {
     case GPIO_A :
            switch (Copy_u8ConnectionType)
                    {
                    case NO_PULL_UP :
                                CLEAR_BIT( GPIOA -> PUPDR , (2*Copy_u8PinNum));
                                CLEAR_BIT( GPIOA -> PUPDR , ((2*Copy_u8PinNum)+1));
                        break;
                    case PULL_UP :
                                SET_BIT( GPIOA -> PUPDR , (2*Copy_u8PinNum));
                                CLEAR_BIT( GPIOA -> PUPDR , ((2*Copy_u8PinNum)+1));
                        break;
                    case PULL_DOWN :
                                CLEAR_BIT( GPIOA -> PUPDR , (2*Copy_u8PinNum));
                                SET_BIT( GPIOA -> PUPDR , ((2*Copy_u8PinNum)+1));
                        break;
                        default:
                        break;
                    }
            break;
        case GPIO_B :
                switch (Copy_u8ConnectionType)
                {
                        case NO_PULL_UP :
                                    CLEAR_BIT(GPIOB -> PUPDR , 2*Copy_u8PinNum);
                                    CLEAR_BIT(GPIOB -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        case PULL_UP :
                                    SET_BIT(GPIOB -> PUPDR , 2*Copy_u8PinNum);
                                    CLEAR_BIT(GPIOB -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        case PULL_DOWN :
                                    CLEAR_BIT(GPIOB -> PUPDR , 2*Copy_u8PinNum);
                                    SET_BIT(GPIOB -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        default:
                            break;
                }
                break;
             case GPIO_C :
                    switch (Copy_u8ConnectionType)
                    {
                        case NO_PULL_UP :
                                    CLEAR_BIT(GPIOC -> PUPDR , 2*Copy_u8PinNum);
                                    CLEAR_BIT(GPIOC -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        case PULL_UP :
                                    SET_BIT(GPIOC -> PUPDR , 2*Copy_u8PinNum);
                                    CLEAR_BIT(GPIOC -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        case PULL_DOWN :
                                    CLEAR_BIT(GPIOC -> PUPDR , 2*Copy_u8PinNum);
                                    SET_BIT(GPIOC -> PUPDR , (2*Copy_u8PinNum)+1);
                            break;
                        default:
                            break;
                    }
                break;   
        default:
            break;
    }
}
void MGPIO_voidOutputSetPinValue(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOValue )
{
    /*  
        OPTIONS :
            LOW : 0  (0V)
            HIGH : 1 (3.3V)
    */
     
   switch (Copy_u8GPIOPort)
    {
    case GPIO_A:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLEAR_BIT( GPIOA -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOA -> ODR , Copy_u8GPIOPin );
            break;
            default:
            //Return Error/
            break;
        }
    break;

    case GPIO_B:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLEAR_BIT( GPIOB -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOB -> ODR , Copy_u8GPIOPin );
            break;
            default:
            //Return Error/
            break;
        }
    break;

    case GPIO_C:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLEAR_BIT( GPIOC -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOC -> ODR , Copy_u8GPIOPin );
            break;
            default:
            //Return Error/
            break;
        }
    break;
    
     default:
            //ERROR
     break;
    }

}
u8 MGPIO_voidInputGetPin(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin )
{
    /*PIN In AVR*/
    /*
    Get Input Value:
      LOW    =   0
      HIGH   =   1
    */
   
   switch (Copy_u8GPIOPort)
    {
    case GPIO_A:
        return GET_BIT(GPIOA -> IDR , Copy_u8GPIOPin);
        break;

    case GPIO_B:
        return GET_BIT(GPIOB -> IDR , Copy_u8GPIOPin);
        break;

    case GPIO_C:
        return GET_BIT(GPIOC -> IDR , Copy_u8GPIOPin);
        break;

    default:
     /*Return Error*/
     break;
    }

}
void MGPIO_VoidSetFirstHalfPortOutput(u8 Copy_u8PortName)
{

    switch (Copy_u8PortName)
    {
    case GPIO_A :
                for (int i = 0; i < 8; i++)
                {
                    SET_BIT( GPIOA -> MODER , (2*i));
                     CLEAR_BIT( GPIOA -> MODER , ((2*i)+1));
                }   
        break;
     case GPIO_B :
                for (int i = 0; i < 8; i++)
                {
                    SET_BIT( GPIOB -> MODER , (2*i));
                     CLEAR_BIT( GPIOB -> MODER , ((2*i)+1));
                }   
        break;
         case GPIO_C :
                for (int i = 0; i < 8; i++)
                {
                    SET_BIT( GPIOC -> MODER , (2*i));
                     CLEAR_BIT( GPIOC -> MODER , ((2*i)+1));
                }   
        break;
    
    default:
        break;
    }
}
void MGPIO_VoidSetSecondHalfPortOutput(u8 Copy_u8PortName)
{

    switch (Copy_u8PortName)
    {
    case GPIO_A :
                for (int i = 8; i < 16; i++)
                {
                    SET_BIT( GPIOA -> MODER , (2*i));
                     CLEAR_BIT( GPIOA -> MODER , ((2*i)+1));
                }   
        break;
     case GPIO_B :
                for (int i = 8; i < 16; i++)
                {
                    SET_BIT( GPIOB -> MODER , (2*i));
                     CLEAR_BIT( GPIOB -> MODER , ((2*i)+1));
                }   
        break;
         case GPIO_C :
                for (int i = 8 ; i < 16; i++)
                {
                    SET_BIT( GPIOC -> MODER , (2*i));
                     CLEAR_BIT( GPIOC -> MODER , ((2*i)+1));
                }   
        break;
    
    default:
        break;
    }
}
void MGPIO_VoidSetFirstHalfPortOutPutSpeed(u8 Copy_u8PortName , u8 Copy_u8OutPutSpeed)
{
    switch(Copy_u8PortName)
    {
        case GPIO_A :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                CLEAR_BIT( GPIOA -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                SET_BIT( GPIOA -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 0; i < 8; i++)
                               {
                                 CLEAR_BIT( GPIOA -> OSPEEDR , (2*i));
                                SET_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                               }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                SET_BIT( GPIOA -> OSPEEDR , (2*i));
                                SET_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;
        case GPIO_B :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                CLEAR_BIT( GPIOB -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                SET_BIT( GPIOB -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 0; i < 8; i++)
                               {
                                 CLEAR_BIT( GPIOB -> OSPEEDR , (2*i));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                               }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 0; i < 8; i++)
                            {
                                SET_BIT( GPIOB -> OSPEEDR , (2*i));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;
        case GPIO_C :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 0; i < 3; i++)
                            {
                                CLEAR_BIT( GPIOC -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 0; i < 3; i++)
                            {
                                SET_BIT( GPIOC -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 0; i < 3; i++)
                               {
                                 CLEAR_BIT( GPIOC -> OSPEEDR , (2*i));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                             }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 0; i < 3 ; i++)
                            {
                                SET_BIT( GPIOC -> OSPEEDR , (2*i));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;    
    }

}
void MGPIO_VoidSetSecondHalfPortOutPutSpeed(u8 Copy_u8PortName , u8 Copy_u8OutPutSpeed)
{
    switch(Copy_u8PortName)
    {
        case GPIO_A :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 8; i < 16; i++)
                            {
                                CLEAR_BIT( GPIOA -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 8; i < 16; i++)
                            {
                                SET_BIT( GPIOA -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 8; i < 16; i++)
                               {
                                 CLEAR_BIT( GPIOA -> OSPEEDR , (2*i));
                                SET_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                               }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 8; i < 16; i++)
                            {
                                SET_BIT( GPIOA -> OSPEEDR , (2*i));
                                SET_BIT( GPIOA -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;
        case GPIO_B :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 8; i < 16; i++)
                            {
                                CLEAR_BIT( GPIOB -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 8; i < 16; i++)
                            {
                                SET_BIT( GPIOB -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 8; i < 16; i++)
                               {
                                 CLEAR_BIT( GPIOB -> OSPEEDR , (2*i));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                               }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 8; i <16; i++)
                            {
                                SET_BIT( GPIOB -> OSPEEDR , (2*i));
                                SET_BIT( GPIOB -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;
        case GPIO_C :
            switch (Copy_u8OutPutSpeed)
                    {
                    case LOW_SPEED :
                            for (u8 i = 0; i < 3; i++)
                            {
                                CLEAR_BIT( GPIOC -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case MEDIUMM_SPEED :
                            for (u8 i = 0; i < 3; i++)
                            {
                                SET_BIT( GPIOC -> OSPEEDR , (2*i));
                                CLEAR_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                    case HIGH_SPEED :
                            for (u8 i = 0; i < 3; i++)
                               {
                                 CLEAR_BIT( GPIOC -> OSPEEDR , (2*i));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                             }
                        break;
                    case VERY_HIGH_SPEED :
                            for (u8 i = 0; i < 3 ; i++)
                            {
                                SET_BIT( GPIOC -> OSPEEDR , (2*i));
                                SET_BIT( GPIOC -> OSPEEDR , ((2*i)+1));
                            }
                        break;
                        default:
                        break;
                    }
            break;    
    }

}
void MGPIO_VoidSetSecondHalfPortOutPutType(u8 Copy_u8PortName  ,  u8 Copy_u8OutPutType)
{

    /* PUSH_PULL  OR OPEN DRAIN PIN AS OUTPUT  */
    switch(Copy_u8PortName)
    {
        case GPIO_A :
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 8; i < 16; i++)
                {
                    CLEAR_BIT(GPIOA -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 8; i < 16; i++)
                {
                     SET_BIT(GPIOA -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         case GPIO_B:
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 8; i < 16; i++)
                {
                    CLEAR_BIT(GPIOB -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 8; i < 16; i++)
                {
                     SET_BIT(GPIOB -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         case GPIO_C :
           switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 0; i < 8; i++)
                {
                    CLEAR_BIT(GPIOC -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 0; i < 8; i++)
                {
                     SET_BIT(GPIOC -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         default:
            
         break;
    }

}
void MGPIO_VoidSetFirstHalfPortOutPutType(u8 Copy_u8PortName  ,  u8 Copy_u8OutPutType)
{

    /* PUSH_PULL  OR OPEN DRAIN PIN AS OUTPUT  */
    switch(Copy_u8PortName)
    {
        case GPIO_A :
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 0; i < 8; i++)
                {
                    CLEAR_BIT(GPIOA -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 0; i < 8; i++)
                {
                     SET_BIT(GPIOA -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         case GPIO_B:
            switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 0; i < 8; i++)
                {
                    CLEAR_BIT(GPIOB -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 0; i < 8; i++)
                {
                     SET_BIT(GPIOB -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         case GPIO_C :
           switch (Copy_u8OutPutType)
            {
            case PUSH_PULL :
                for (u8 i = 0; i < 8; i++)
                {
                    CLEAR_BIT(GPIOC -> OTYPER , i);
                }     
                break;
             case OPEN_DRAIN :
                for (u8 i = 0; i < 8; i++)
                {
                     SET_BIT(GPIOC -> OTYPER , i);
                }
                        
                break;
            default:
                break;
            }
         break;
         default:
            
         break;
    }

}
void MGPIO_VoidSetFirstHalfPortValue(u8 Copy_u8GPIOPort , u32 Copy_u8Value)
{
    
     
   switch (Copy_u8GPIOPort)
    {
    case GPIO_A:
    		GPIOA ->ODR = Copy_u8Value ;
            /*GPIOA ->ODR &= 0x0000ff00 ;
            GPIOA ->ODR |= Copy_u8Value ;*/
    break;

    case GPIO_B:
            GPIOB ->ODR &= 0x0000ff00 ;
            GPIOB ->ODR |= Copy_u8Value ;
    break;

    case GPIO_C:
            GPIOC ->ODR &= 0x0000ff00 ;
            GPIOC ->ODR |= Copy_u8Value ;
    break;
    
     default:
            //ERROR
     break;
    }

}
void MGPIO_VoidSetSecondHalfPortValue(u8 Copy_u8GPIOPort , u8 Copy_u8Value)
{
    
     
   switch (Copy_u8GPIOPort)
    {
    case GPIO_A:
    		Copy_u8Value = (Copy_u8Value<<8);
            GPIOA ->ODR &= 0x00ff ;
            GPIOA ->ODR |= Copy_u8Value ;
    break;

    case GPIO_B:
    		//Copy_u8Value = (Copy_u8Value<<8);
            GPIOB ->ODR &= 0x00ff ;
            //GPIOB ->ODR |= Copy_u8Value ;
    		GPIOB ->ODR = GPIOB ->ODR | (Copy_u8Value<<8);
    break;

    case GPIO_C:
    		Copy_u8Value = (Copy_u8Value<<8);
            GPIOC ->ODR &= 0x00ff ;
            GPIOC ->ODR |= Copy_u8Value ;
    break;
    
     default:
            //ERROR
     break;
    }
    
}
