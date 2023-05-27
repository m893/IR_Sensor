/***********
 * Author :   Mohammed Akram
 * Date  :   1 MAY ,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              1 MAY , 2023               Mohammed Akram
***************************************************************************/
#ifndef RCC_CNFIG_H
#define RCC_CNFIG_H
/*
    OPTIONS :
        HSI
        HSE
        PLL
*/
#define CPU_CLK_SOURCE           HSI
/*
    OPTIONS:
        HSI
        HSE
*/
#define PLL_SOURCE              HSE
/*
    OPTIONS :

    NOT_BYPASSED
    BYPASSED

*/


#define HSE_CLOCK_SOURCE        NOT_BYPASSED


/*  
    OPTIONS :
        SYSCLOCK_DIVIDE_BY_2    
        SYSCLOCK_DIVIDE_BY_4    
        SYSCLOCK_DIVIDE_BY_8    
        SYSCLOCK_DIVIDE_BY_16   
*/
#define AHB_PRESCALER      SYSCLOCK_DIVIDE_BY_2

/*  
    OPTIONS :
        APB1_DIVIDE_BY_2       
        APB1_DIVIDE_BY_4       
        APB1_DIVIDE_BY_8       
*/
#define APB1_PRESCALER       APB1_DIVIDE_BY_2
#define APB2_PRESCALER       APB1_DIVIDE_BY_2

#endif
