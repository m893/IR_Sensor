/***********
 * Author :   Mohammed Akram
 * Date  :   21 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              21 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


typedef struct 
{

    volatile u32 ISER[8];
    volatile u32 Reserved0[24];
    volatile u32 ICER[8];
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[56];
    volatile u8 IPR[240];
    volatile u32 Reserved5[580];
    volatile u32 STIR;


}NVIC_t;


#define     MNVIC   ((volatile NVIC_t * )0xE000E100)


#define     SCB_AIRCR  *((volatile u32 *)0xE000ED0C)

#define GRP_4_SUB_0_BITS        0b000
#define GRP_3_SUB_1_BITS        0b100
#define GRP_2_SUB_2_BITS        0b101
#define GRP_1_SUB_1_BITS        0b110
#define GRP_0_SUB_0_BITS        0b111


#define  AIRCR_PRIVATE_KEY  0X05FA




#endif
