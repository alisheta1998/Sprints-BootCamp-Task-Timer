

#ifndef TIMER_H_
#define TIMER_H_
/*ITS RECOMMENDED TO UNIFY THE SOURCE FRREQUENCY FOR ALL DRIVERS WORKING WITH CLK*/
/*Available operating frequencies for this device:
 * Category(1). For (1MHz  clk --> 3.9KHz  - 0.5KHz)
 * Category(2). For (16MHz clk --> 62.5KHz - 7.8KHz)
 * */
/*Its no Recommended to change the frequencies from diffrent Categories */
#define Normal	0
#define CTC		1
#define Timer0_Mode Normal


#define No_Prescaler 0
#define Prescaler_8  1
#define Frequency Prescaler_8

void TIM0_Init (void);
void TIM0_Start(void);
void TIM0_Stop (void);
void TIM0_SetISR(void (*ptr0) (void));





#endif /* TIMER_H_ */
