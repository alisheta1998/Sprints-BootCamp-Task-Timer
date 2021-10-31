#include "Timer.h"




void Toggle_Led()
{
	int counter = 0;
	if(counter == 50)
	{
		DIO_TogglePin(PORT0,PIN0);
		counter=0;
	}
	else
	{
		counter++;
	}
	
}


int main(void)
{
	/*
	 *INITIALIZE SAFE SOFTWARE
	  */
	TIM0_Init();
	DIO_SetPinDirection(PORT0,PIN0,OUTPUT);
	TIM0_SetISR(Toggle_Led);
	TIM0_Start();




	return 0 ;
}

