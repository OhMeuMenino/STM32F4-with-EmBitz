/*
 Timer Counter NVCI Interrupt

 This projects configure the timer 9 (TIM9) as counter and
 use the timer's NVCI interrupt to blink blink the LED3 and LED4 (PG13 & PG14)

**********************************************************************

   Last changed by:    OhMeuMenino
   Last changed date:  May 2017

**********************************************************************/
#include "stm32f4xx_conf.h"

void PinConfig(void);
void TIMConfig(void);
void TimerInterrupt(void);


void TIM1_BRK_TIM9_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET){
            GPIO_ToggleBits(GPIOG, GPIO_Pin_14);
            GPIO_ToggleBits(GPIOG, GPIO_Pin_13);
            TIM_ClearITPendingBit(TIM9, TIM_IT_Update);
    }
}


int main(void)
{
    PinConfig();
    TIMConfig();
    TimerInterrupt();

    while(1);
}

/*
** Pins configuration
*/
void PinConfig(void){
    /* GPIOG Peripheral clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

    /* Configure the PIN13 and PIN14 on PORTG */
    GPIO_InitTypeDef  PORTG;
    PORTG.GPIO_Pin = (GPIO_Pin_13 | GPIO_Pin_14 );       // Pin 13 and Pin 14
    PORTG.GPIO_Mode = GPIO_Mode_OUT;    // Output
    PORTG.GPIO_OType = GPIO_OType_PP;   // Output Type - Push-pull mode
    PORTG.GPIO_Speed = GPIO_Speed_100MHz;
    PORTG.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOG, &PORTG);

}

/*
** Timer configuration and Enable Timer 9 interrupt
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

    TIM_ITConfig(TIM9, TIM_IT_Update, ENABLE); // Enable interrupt
}

/*
** NVIC interrupts configuration
*/
void TimerInterrupt(void)
{
    NVIC_InitTypeDef NVICTimer9;
    NVICTimer9.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
    NVICTimer9.NVIC_IRQChannelPreemptionPriority = 0;
    NVICTimer9.NVIC_IRQChannelSubPriority = 1;
    NVICTimer9.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVICTimer9);
}
