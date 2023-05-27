/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*
    OPTIONS:
        PORT NAME
        A , B, C
*/
#define GPIO_A      0
#define GPIO_B      1
#define GPIO_C      2
/*
    OPTIONS:
       PINS FROM 0 TO 15
*/
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

/*
    OPTIONS:
        PIN MODE 
        INPUT , OUTPUT , ALTRNATIVE FUNCTION ,  ANALOG 
*/
#define INPUT               0
#define OUTPUT              1
#define ALTRNATIVE_FUN      2
#define ANALOG              3

/*
    OPTIONS:
        OUTPUT PIN MODE 
        PUSH PULL  , OPEN DRAIN 
*/
#define PUSH_PULL       0
#define OPEN_DRAIN      1

/*
    OPTIONS:
        OUTPUT PIN SPEED MODE TURN FROM 0 TO 1  
        
*/
#define LOW_SPEED               0
#define MEDIUMM_SPEED           1
#define HIGH_SPEED              2
#define VERY_HIGH_SPEED         3
/*
    OPTIONS:
        INPUT PIN MODE 
        NO PULLUP , PULLUP , PULLDOWN
*/
#define NO_PULL_UP      0
#define PULL_UP         1
#define PULL_DOWN       2
/*
    OPTIONS:
        OUTPUT PIN VALUE
        HIGH , LOW       
*/
#define HIGH    1
#define LOW     0


void MGPIO_VoidSetPinMode(u8 Copy_u8PortName  , u8 Copy_u8GPIOPin , u8 Copy_u8Mode);
void MGPIO_VoidSetOutPutType(u8 Copy_u8PortName  , u8 Copy_u8PinNum , u8 Copy_u8OutPutType);
void MGPIO_VoidSetOutPutSpeed(u8 Copy_u8PortName  , u8 Copy_u8GPIOPin , u8 Copy_u8OutPutSpeed);
void MGPIO_VoidSetPinConnectiontype(u8 Copy_u8PortName  , u8 Copy_u8PinNum , u8 Copy_u8ConnectionType);
void MGPIO_voidOutputSetPinValue(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOValue );
u8 MGPIO_voidInputGetPin(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin );
void MGPIO_VoidSetFirstHalfPortOutput(u8 Copy_u8PortName);
void MGPIO_VoidSetSecondHalfPortOutput(u8 Copy_u8PortName);
void MGPIO_VoidSetFirstHalfPortOutPutSpeed(u8 Copy_u8PortName , u8 Copy_u8OutPutSpeed);
void MGPIO_VoidSetSecondHalfPortOutPutSpeed(u8 Copy_u8PortName , u8 Copy_u8OutPutSpeed);
void MGPIO_VoidSetSecondHalfPortOutPutType(u8 Copy_u8PortName  ,  u8 Copy_u8OutPutType);
void MGPIO_VoidSetSecondHalfPortOutPutSpeed(u8 Copy_u8PortName , u8 Copy_u8OutPutSpeed);
void MGPIO_VoidSetFirstHalfPortValue(u8 Copy_u8GPIOPort , u32 Copy_u8Value);
void MGPIO_VoidSetSecondHalfPortValue(u8 Copy_u8GPIOPort , u8 Copy_u8Value);


#endif
