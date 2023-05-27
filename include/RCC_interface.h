/***********
 * Author :   Mohammed Akram
 * Date  :   1 MAY ,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              1 MAY , 2023               Mohammed Akram
***************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*
    OPTIONS:
    CHOOSE THE BUS THAT YOUR PERIPHERAL IN 
*/
#define RCC_AHB1    0
#define RCC_AHB2    1
#define RCC_APB1    2
#define RCC_APB2    3
/*
    OPTIONS :
    CHOOSE YOUR PERIPHERAL TO ENABLE 
*/
#define GPIOA_ID   0
#define GPIOB_ID   1
#define GPIOC_ID   2
#define GPIOD_ID   3


void MRCC_VoidInit(void);
void MRCC_VoidEnablePeriperalClock(u8 Copy_u8PeriperalBus , u8 Copy_u8PeriperalId);




#endif
