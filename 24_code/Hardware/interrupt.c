#include "Hardware/interrupt.h"
#include <ti/driverlib/dl_timera.h>
#include <ti/driverlib/dl_timerg.h>
#include "ti/driverlib/dl_gpio.h"

void TIMEG0_init(void)
{
	NVIC_EnableIRQ(TIMG0_INT_IRQn);  
	DL_TimerG_startCounter(TIMG0);
}

void TIMG0_IRQHandler()            {
	DL_GPIO_togglePins(GPIOA,DL_GPIO_PIN_0);
}