#include <stdio.h>
#include "STM32F407.h"

int main (void)
{
	GPIO_Handle_t pinLed;
	pinLed.pGPIOx = GPIOD;
	pinLed.GPIO_PinConfig.pinMode = GPIO_MODE_OUTPUT;
	pinLed.GPIO_PinConfig.pinNumber = 12;
	pinLed.GPIO_PinConfig.pinOPSpeed = GPIO_OPSPEED_HIGH;
	pinLed.GPIO_PinConfig.pinOPType = GPIO_OPTYPE_PUSHPULL;
	pinLed.GPIO_PinConfig.pinPUPD = GPIO_PUPD_NO;

	GPIO_ClockControl(GPIOD, ENABLE);
	GPIO_Init(&pinLed);

	while (1)
	{
		GPIO_PinWrite(GPIOD, 12, 1);
		for (uint32_t i = 0; i <1000000; i++);
		GPIO_PinWrite(GPIOD, 12, 0);
		for (uint32_t i = 0; i <1000000; i++);
	}

	return 0;
}
