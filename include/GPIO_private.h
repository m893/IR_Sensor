/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA_BASE_ADDRESS        0x40020000
#define GPIOB_BASE_ADDRESS        0x40020400
#define GPIOC_BASE_ADDRESS        0x40020800

typedef struct
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
}GPIO_t;

         /*Pointer To Structure Started From BaseAddress*/
#define GPIOA         ((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB         ((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC         ((volatile GPIO_t*)GPIOC_BASE_ADDRESS)



#endif