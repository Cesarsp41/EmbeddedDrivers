/*
 * STM32F407_GPIO.c
 *
 *  Created on: 25 oct 2023
 *      Author: César
 */
#include "STM32F407_GPIO.h"

//Inicializacion
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t control)
{
	if (control == ENABLE)
	{
		if (pGPIOx == GPIOA) {GPIOA_CLK_ENABLE();}
		else if (pGPIOx == GPIOB) {GPIOB_CLK_ENABLE();}
		else if (pGPIOx == GPIOC) {GPIOC_CLK_ENABLE();}
		else if (pGPIOx == GPIOD) {GPIOD_CLK_ENABLE();}
		else if (pGPIOx == GPIOE) {GPIOE_CLK_ENABLE();}
		else if (pGPIOx == GPIOF) {GPIOF_CLK_ENABLE();}
		else if (pGPIOx == GPIOG) {GPIOG_CLK_ENABLE();}
		else if (pGPIOx == GPIOH) {GPIOH_CLK_ENABLE();}
		else {GPIOI_CLK_ENABLE();}
	}
	else
	{
		if (pGPIOx == GPIOA) {GPIOA_CLK_DISABLE();}
		else if (pGPIOx == GPIOB) {GPIOB_CLK_DISABLE();}
		else if (pGPIOx == GPIOC) {GPIOC_CLK_DISABLE();}
		else if (pGPIOx == GPIOD) {GPIOD_CLK_DISABLE();}
		else if (pGPIOx == GPIOE) {GPIOE_CLK_DISABLE();}
		else if (pGPIOx == GPIOF) {GPIOF_CLK_DISABLE();}
		else if (pGPIOx == GPIOG) {GPIOG_CLK_DISABLE();}
		else if (pGPIOx == GPIOH) {GPIOH_CLK_DISABLE();}
		else {GPIOI_CLK_DISABLE();}
	}
}
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	__vo uint32_t temp = 0;;

	//1- Configurar modo del pin (I/O Alt Analog)
	temp = (pGPIOHandle->GPIO_PinConfig.pinMode << (pGPIOHandle->GPIO_PinConfig.pinNumber * 2));
	pGPIOHandle->pGPIOx->MODER |= temp;
	temp = 0;

	//2- Si es salida, configurar:
	if (pGPIOHandle->GPIO_PinConfig.pinMode == GPIO_MODE_OUTPUT)
	{
		//2.1 Push pull/Open Drain
		temp = (pGPIOHandle->GPIO_PinConfig.pinOPType << (pGPIOHandle->GPIO_PinConfig.pinNumber));
		pGPIOHandle->pGPIOx->OTYPER |= temp;

		//2.2 Velocidad
		temp = (pGPIOHandle->GPIO_PinConfig.pinOPSpeed << (pGPIOHandle->GPIO_PinConfig.pinNumber * 2));
		pGPIOHandle->pGPIOx->OSPEEDR |= temp;

		temp = 0;
	}

	//3- Si es entrada, configurar:
	if (pGPIOHandle->GPIO_PinConfig.pinMode == GPIO_MODE_INPUT)
	{
		//3.1 Pullup/pulldown
		temp = (pGPIOHandle->GPIO_PinConfig.pinPUPD << (pGPIOHandle->GPIO_PinConfig.pinNumber * 2));
		pGPIOHandle->pGPIOx->PUPDR |= temp;
		temp = 0;
	}

	//4- Configurar funcion alternativa
	if (pGPIOHandle->GPIO_PinConfig.pinMode == GPIO_MODE_ALT_FUN)
	{
		//Si el pin es 0 - 7, se toca LOW ALT FUN
		if (pGPIOHandle->GPIO_PinConfig.pinNumber <= 7)
		{
			temp = (pGPIOHandle->GPIO_PinConfig.pinAltFun << (pGPIOHandle->GPIO_PinConfig.pinNumber * 4));
			pGPIOHandle->pGPIOx->AFRL |= temp;
			temp = 0;
		}
		//Si el pin es 8 - 15, se toca HIGH ALT FUN
		else
		{
			temp = (pGPIOHandle->GPIO_PinConfig.pinAltFun << (pGPIOHandle->GPIO_PinConfig.pinNumber * 4));
			pGPIOHandle->pGPIOx->AFRH |= temp;
			temp = 0;
		}
	}
}
void GPIO_Reset(GPIO_RegDef_t *pGPIOx)
{
	if (pGPIOx == GPIOA) {GPIOA_REGISTER_RESET();}
	else if (pGPIOx == GPIOB) {GPIOB_REGISTER_RESET();}
	else if (pGPIOx == GPIOC) {GPIOC_REGISTER_RESET();}
	else if (pGPIOx == GPIOD) {GPIOD_REGISTER_RESET();}
	else if (pGPIOx == GPIOE) {GPIOE_REGISTER_RESET();}
	else if (pGPIOx == GPIOF) {GPIOF_REGISTER_RESET();}
	else if (pGPIOx == GPIOG) {GPIOG_REGISTER_RESET();}
	else if (pGPIOx == GPIOH) {GPIOH_REGISTER_RESET();}
	else {GPIOI_REGISTER_RESET();}
}

//Escritura
void GPIO_PinWrite(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value)
{
	//Debe modificarse Output Data Register
	if (value == HIGH)
		pGPIOx->ODR |= (HIGH << pinNumber);
	else
		pGPIOx->ODR &= ~(HIGH << pinNumber);
}
void GPIO_PortWrite(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}

//Lectura
uint8_t GPIO_PinRead(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
	//Tiene que leerse el bit correspodiente de IDR, en otras palabras, extraer bit
	uint8_t temp;
	temp = (uint8_t)(pGPIOx->IDR >> pinNumber);
	temp &= 1;
	return temp;
}

uint16_t GPIO_PortRead(GPIO_RegDef_t *pGPIOx)
{
	uint16_t temp;
	temp = (uint16_t)(pGPIOx->IDR);
	return temp;
}

//Interrupciones
void IRQConfig() /* ToDo */
{

}
void IRQHandle()
{

}
