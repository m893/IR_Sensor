/***********
 * Author :   Mohammed Akram
 * Date  :   1 MAY ,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              1 MAY , 2023               Mohammed Akram
***************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H



#define RCC_BASE_ADDRESS        0x40023800

typedef struct
{
    volatile u32 CR;                /* ENABLE HSE OR HSI*/
    volatile u32 PLLCFGR;
    volatile u32 CFGR;                  /*REGISTER TO  CHOOSE SYSTEM CLOCK */
    volatile u32 CIR;
    volatile u32 AHB1RSTR;              /*ENABLE PERIPHIRALS THAT IN AHP1 BUS*/
    volatile u32 AHB2RSTR;               /*ENABLE PERIPHIRALS THAT IN AHP2 BUS*/
    volatile u32 RESERVED[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 RESERVED2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 RESERVED3[2];
    volatile u32 APB1ENR;               /*ENABLE PERIPHIRALS THAT IN APB1 BUS*/
    volatile u32 APB2ENR;                /*ENABLE PERIPHIRALS THAT IN ABP2 BUS*/
    volatile u32 RESERVED4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 RESERVED5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 RESERVED6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 RESERVED7[2];
    volatile u32 SSCGR;
    volatile u32 _PLLI2SCFGR;
    volatile u32 RESERVED8;
    volatile u32 DCKCFGR;
}RCC_t;

        /* POINTER TO HE BASE ADDRESS OF RCC */
#define RCC     ((volatile RCC_t * )RCC_BASE_ADDRESS)

/* PRESCALER FOR APB1  AND APB2*/

#define APB1_DIVIDE_BY_2        0
#define APB1_DIVIDE_BY_4        1
#define APB1_DIVIDE_BY_8        2

/* FOR AHB BUS */
#define SYSCLOCK_DIVIDE_BY_1            0
#define SYSCLOCK_DIVIDE_BY_2            8
#define SYSCLOCK_DIVIDE_BY_4            9
#define SYSCLOCK_DIVIDE_BY_8            10
#define SYSCLOCK_DIVIDE_BY_16           11
#define SYSCLOCK_DIVIDE_BY_64           12
#define SYSCLOCK_DIVIDE_BY_128          13
#define SYSCLOCK_DIVIDE_BY_256          14
#define SYSCLOCK_DIVIDE_BY_512          15

#define HSI     0
#define HSE     1
#define PLL     2


#define  NOT_BYPASSED       0
#define  BYPASSED           1

#endif
