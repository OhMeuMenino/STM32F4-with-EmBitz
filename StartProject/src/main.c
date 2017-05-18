/*
** Start project. It includes all Standart Peripherals Library
**
** This projects configure the GPIO G13 to blink the LED3 (green)
**
**********************************************************************/
/*
   Last changed by:    OhMeuMenino
   Last changed date:  May 2017

**********************************************************************/
#include "stm32f4xx_conf.h"

int main(void)
{
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

    int i=1000000;
    while(1)
    {
        GPIO_ToggleBits(GPIOG,13);
        for(i=1000000;i>0;i--);
    }

}
