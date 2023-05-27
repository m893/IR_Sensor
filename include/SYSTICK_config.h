/***********
 * Author :   Mohammed Akram
 * Date  :   8 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              8 MAY, 2023               Mohammed Akram
***************************************************************************/

#ifndef  SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/*  
    SELECT CLOCK SOURCE
         OPTIONS :
            AHB1_CLOCK_SOURCE_DIVIDE_8
            AHB1_CLOCK_SOURCE
*/
#define SYSTICK_CLOCK_SOURCE    AHB1_CLOCK_SOURCE_DIVIDE_8

/*  
    options :
        ENABLE , DISABLE 
*/
#define SYSTICK_ENABLE          ENABLE 
/*  
    options :
        ENABLE , DISABLE 
*/
#define SYSTICK_INTERRUPT       ENABLE 



#endif