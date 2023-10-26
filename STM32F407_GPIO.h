/*
 * STM32F407_GPIO.h
 *
 *  Created on: 21 oct 2023
 *      Author: César
 */

#ifndef STM32F407_GPIO_H_
#define STM32F407_GPIO_H_
#include "STM32F407.h"
//------------Macros especificos para GPIO
//Modos de Pin
#define			GPIO_MODE_INPUT			0
#define			GPIO_MODE_OUTPUT		1
#define			GPIO_MODE_ALT_FUN		2
#define			GPIO_MODE_ANALOG		3
//Funciones alternativas
#define			GPIO_ALT_FUN_0			0
#define			GPIO_ALT_FUN_1			1
#define			GPIO_ALT_FUN_2			2
#define			GPIO_ALT_FUN_3			3
#define			GPIO_ALT_FUN_4			4
#define			GPIO_ALT_FUN_5			5
#define			GPIO_ALT_FUN_6			6
#define			GPIO_ALT_FUN_7			7
#define			GPIO_ALT_FUN_8			8
#define			GPIO_ALT_FUN_9			9
#define			GPIO_ALT_FUN_10			10
#define			GPIO_ALT_FUN_11			11
#define			GPIO_ALT_FUN_12			12
#define			GPIO_ALT_FUN_13			13
#define			GPIO_ALT_FUN_14			14
#define			GPIO_ALT_FUN_15			15
//Tipo de salida
#define			GPIO_OPTYPE_PUSHPULL		0
#define			GPIO_OPTYPE_OPENDRAIN		1
//Velocidad de salida
#define			GPIO_OPSPEED_LOW			0
#define			GPIO_OPSPEED_MEDIUM			1
#define			GPIO_OPSPEED_HIGH			2
#define			GPIO_OPSPEED_VHIGH			3
//Resistencia pull up / pull down
#define			GPIO_PUPD_NO			0
#define			GPIO_PUPD_PULLUP		1
#define			GPIO_PUPD_PULLDOWN		2

//Estructura de configuracion
typedef struct {
	//Parametros configurables para un pin GPIO
	uint8_t		pinNumber;
	uint8_t 	pinMode;
	uint8_t		pinOPType;
	uint8_t		pinOPSpeed;
	uint8_t		pinPUPD;
	uint8_t		pinAltFun;

}GPIO_Config_t;

//Estructura de manejo (handle)
typedef struct {
	GPIO_Config_t GPIO_PinConfig;
	GPIO_RegDef_t *pGPIOx;
}GPIO_Handle_t;


//Prototipos de funciones para GPIO

//Inicializacion
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t control);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);	//-----------------Inicializa los registros con toda la informacion del Pin
void GPIO_Reset(GPIO_RegDef_t *pGPIOx);  //-----------------Reinicia los registros del Pin

//Escritura
void GPIO_PinWrite(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_PortWrite(GPIO_RegDef_t *pGPIOx, uint16_t value);

//Lectura
uint8_t GPIO_PinRead(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_PortRead(GPIO_RegDef_t *pGPIOx);

//Interrupciones
void IRQConfig(); /* ToDo */
void IRQHandle();

#endif /* STM32F407_GPIO_H_ */
