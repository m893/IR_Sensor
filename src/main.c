/***********
 * Author :   Mohammed Akram
 * Date  :   26 MAY,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              26 MAY, 2023               Mohammed Akram
***************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "IR_interface.h"

void fun1();
extern u8 App_u8ButtonData ;

u32 main()
{
	HIR_VoidInit();
	MGPIO_VoidSetPinMode(GPIO_A , PIN1, OUTPUT);
	MGPIO_VoidSetPinMode(GPIO_A , PIN2 , OUTPUT);
	MGPIO_VoidSetPinMode(GPIO_A , PIN3 , OUTPUT);

	while(1)
	{
		fun1();
	}

}

void fun1()
{
	switch(App_u8ButtonData)
		{
		case 94: //3 in remote 
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , LOW);
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , HIGH);
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , LOW);
			break;
		case 12: //1
			MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , LOW);
			MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , LOW);
			MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , HIGH);
			break;
		case 24: //2
				MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , LOW);
				MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , LOW);
				MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , HIGH);
				break;
		case 69: //close
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , LOW);
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , LOW);
					MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , LOW);
					break;
		case 8: //4
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , HIGH);
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , HIGH);
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , LOW);
						break;
		case 28: //5
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN1 , LOW);
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN2 , HIGH);
						MGPIO_voidOutputSetPinValue(GPIO_A , PIN3 , HIGH);
						break;
		}

}
