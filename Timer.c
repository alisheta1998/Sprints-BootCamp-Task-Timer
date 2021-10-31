

#include "Bit_Operations.h"

#include <avr/interrupt.h>
#include "Timer.h"

static void (*Gptr0) (void);

/*TIMER0 FUNCTIONS*/
void TIM0_Init (void) 	//Where u make a delay for x ms and call a certain ISR after the delay is finished
{
	switch(Timer0_Mode)
	{
	case Normal :
		/*Compare Output Mode Selection*/
		CLRBIT(TCCR0,4);
		CLRBIT(TCCR0,5);
		/*Normal Mode Selection*/
		CLRBIT(TCCR0,3);	//WGM01
		CLRBIT(TCCR0,6);	//WGM00

		/*Clock Source Select*/
		/*Current Prescalar/1024  .... freq.=1ms*/
		switch(Frequency)
		{
		case No_Prescaler :
			SETBIT(TCCR0,0);	//CS00
			CLRBIT(TCCR0,1);	//CS01
			CLRBIT(TCCR0,2);	//CS02
			break;
		case Prescaler_8 :
			CLRBIT(TCCR0,0);	//CS00
			SETBIT(TCCR0,1);	//CS01
			CLRBIT(TCCR0,2);	//CS02
			break;
		default :
			break;
		}

		/*Over Flow Flag Setup*/
		SETBIT(TIMSK,0);		//TOIE0(Overflow Interrupt Enable)
		SETBIT(SREG,7);
		/*Interrupt Setup*/

		break;
	case CTC :
		break;
	default :
		break;

	}
}

ISR(TIMER0_OVF_vect)
{
	Gptr0();
}
ISR(TIMER0_COMP_vect)
{
	Gptr0();
}
void TIM0_Start(void)
{

}
void TIM0_Stop (void)
{
	CLRBIT(TCCR0,0);	//CS00
	CLRBIT(TCCR0,1);	//CS01
	CLRBIT(TCCR0,2);	//CS02
}
void TIM0_SetISR(void (*ptr0) (void))
{
	Gptr0=ptr0;
}




