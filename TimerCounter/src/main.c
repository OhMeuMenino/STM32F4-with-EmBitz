/*
 Timer Counter

 This projects configure the timer 9 (TIM9) as counter
 and blink the LED3 (PG13)

**********************************************************************

   Last changed by:    OhMeuMenino
   Last changed date:  May 2017

**********************************************************************/
#include "stm32f4xx_conf.h"

void PinConfig(void);
void TIMConfig(void);

int main(void)
{
    PinConfig();
    TIMConfig();

    while(1)
    {

        int timerValue = TIM_GetCounter(TIM9);
        if (timerValue == 400)
            GPIO_ToggleBits(GPIOG, GPIO_Pin_13);
    }
}

/*
** Pin configuration
*/
void PinConfig(void){
        /* GPIOG Peripheral clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

    /* Configure the PIN13 on PORTG */
    GPIO_InitTypeDef  PORTG;
    PORTG.GPIO_Pin = GPIO_Pin_13;       // Pin 13
    PORTG.GPIO_Mode = GPIO_Mode_OUT;    // Output
    PORTG.GPIO_OType = GPIO_OType_PP;   // Output Type - Push-pull mode
    PORTG.GPIO_Speed = GPIO_Speed_100MHz;
    PORTG.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOG, &PORTG);
}

/*
** Timer configuration
*/
void TIMConfig(void){

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);

    TIM_TimeBaseInitTypeDef Timer9;
    Timer9.TIM_Prescaler = 40000;
    Timer9.TIM_CounterMode = TIM_CounterMode_Up;
    Timer9.TIM_Period = 500;
    Timer9.TIM_ClockDivision = TIM_CKD_DIV1;
    Timer9.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM9, &Timer9);
    TIM_Cmd(TIM9, ENABLE);

}
