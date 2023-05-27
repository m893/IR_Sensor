/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/
#ifndef  SYSTICK_PRIVATE_H
#define  SYSTICK_PRIVATE_H


#define STK_CTRL    *((volatile u32 *)0xE000E010)

#define STK_CTRL_ENABLE         0 
#define STK_CTRL_TICKINT        1
#define STK_CTRL_CLKSOURCE      2
#define STK_CTRL_COUNTFLAG      16  /* clear flag by reading its value */


#define STK_LOAD    *((volatile u32 *)0xE000E014)       /* 24 BIT TO PUT VALUE THE TIMER START FROM AND COUNT DOWN TO ZERO*/

/*  24 BIT TAKE THE VALUE FROM LOAD REGISTER AND COUNT TO 0 THEN FIRE INTERRUPT AND
 START FROM THE LOAD VALUE */
#define STK_VAL    *((volatile u32 *)0xE000E018)    /* can clear when i write 0 to this register flag and clear systick flag*/    




#define    AHB1_CLOCK_SOURCE_DIVIDE_8       0
#define    AHB1_CLOCK_SOURCE                1

#define ENABLE                  0
#define DISABLE                 1

#define     SINGLE_INTERVAL         0



#endif
