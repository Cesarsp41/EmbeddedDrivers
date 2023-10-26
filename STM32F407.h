/*
 * STM32F407.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Cesar
 */
#ifndef STM32F407_H_
#define STM32F407_H_

#include <stdint.h>

//Macros generales
#define		LOW				0
#define		HIGH			1
#define		DISABLE			LOW
#define		ENABLE			HIGH
#define		OFF				LOW
#define		ON				HIGH
#define		__vo			volatile

//Direcciones de memorias
#define		SRAM2_BASEADDR			0x2001C000U
#define		SRAM1_BASEADDR			0x20000000U
#define		ROM_BASEADDR			0x1FFF0000U
#define		FLASH_BASEADDR			0x08000000U

//Direcciones de buses de comunicacion
#define		APB1_BASEADDR			0x40000000U
#define		APB2_BASEADDR			0x40010000U
#define		AHB1_BASEADDR			0x40020000
#define		AHB2_BASEADDR			0x50000000U
#define		AHB3_BASEADDR			0xA0000000U

//Direcciones de perifericos
#define		SYSCFG_BASEADDR			(APB2_BASEADDR + 0x3800)
#define		EXTI_BASEADDR			(APB2_BASEADDR + 0x3C00)
#define		GPIOA_BASEADDR			(AHB1_BASEADDR + 0x0000)
#define		GPIOB_BASEADDR			(AHB1_BASEADDR + 0x0400)
#define		GPIOC_BASEADDR			(AHB1_BASEADDR + 0x0800)
#define		GPIOD_BASEADDR			(AHB1_BASEADDR + 0x0C00)
#define		GPIOE_BASEADDR			(AHB1_BASEADDR + 0x1000)
#define		GPIOF_BASEADDR			(AHB1_BASEADDR + 0x1400)
#define		GPIOG_BASEADDR			(AHB1_BASEADDR + 0x1800)
#define		GPIOH_BASEADDR			(AHB1_BASEADDR + 0x1C00)
#define		GPIOI_BASEADDR			(AHB1_BASEADDR + 0x2000)
#define		GPIOJ_BASEADDR			(AHB1_BASEADDR + 0x2400)
#define		GPIOK_BASEADDR			(AHB1_BASEADDR + 0x2800)
#define		RCC_BASEADDR			(AHB1_BASEADDR + 0x3800)

//Modelado de registros perifericos
//SYSCFG
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR1;
	__vo uint32_t EXTICR2;
	__vo uint32_t EXTICR3;
	__vo uint32_t EXTICR4;
	__vo uint32_t CMPCR;
}SYSCFG_RegDef_t;

//EXTI
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;

//GPIO
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;
}GPIO_RegDef_t;

//GPIO
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t RESERVED1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED2[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED3;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED4[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED5;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

//Macros de punteros
#define		EXTI			((EXTI_RegDef_t*)(EXTI_BASEADDR))
#define		RCC				((RCC_RegDef_t*)(RCC_BASEADDR))
#define		SYSCFG			((SYSCFG_RegDef_t*)(SYSCFG_BASEADDR))
#define		GPIOA			((GPIO_RegDef_t*)(GPIOA_BASEADDR))
#define		GPIOB			((GPIO_RegDef_t*)(GPIOB_BASEADDR))
#define		GPIOC			((GPIO_RegDef_t*)(GPIOC_BASEADDR))
#define		GPIOD			((GPIO_RegDef_t*)(GPIOD_BASEADDR))
#define		GPIOE			((GPIO_RegDef_t*)(GPIOE_BASEADDR))
#define		GPIOF			((GPIO_RegDef_t*)(GPIOF_BASEADDR))
#define		GPIOG			((GPIO_RegDef_t*)(GPIOG_BASEADDR))
#define		GPIOH			((GPIO_RegDef_t*)(GPIOH_BASEADDR))
#define		GPIOI			((GPIO_RegDef_t*)(GPIOI_BASEADDR))
#define		GPIOJ			((GPIO_RegDef_t*)(GPIOJ_BASEADDR))
#define		GPIOK			((GPIO_RegDef_t*)(GPIOK_BASEADDR))

//Macros de habilitacion de reloj
#define		GPIOA_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 0))
#define		GPIOB_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 1))
#define		GPIOC_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 2))
#define		GPIOD_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 3))
#define		GPIOE_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 4))
#define		GPIOF_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 5))
#define		GPIOG_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 6))
#define		GPIOH_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 7))
#define		GPIOI_CLK_ENABLE()		(RCC->AHB1ENR |= (1 << 8))
#define		SYSCFG_CLK_ENABLE()		(RCC->APB2ENR |= (1 << 14))

//Macros de deshabilitacion de reloj
#define		GPIOA_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 0))
#define		GPIOB_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 1))
#define		GPIOC_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 2))
#define		GPIOD_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 3))
#define		GPIOE_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 4))
#define		GPIOF_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 5))
#define		GPIOG_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 6))
#define		GPIOH_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 7))
#define		GPIOI_CLK_DISABLE()		(RCC->AHB1ENR &= ~(1 << 8))
#define		SYSCFG_CLK_DISABLE()		(RCC->APB2ENR &= ~(1 << 14))

//Macros para reset de registros perifericos
#define 	GPIOA_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 0))
#define 	GPIOB_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 1))
#define 	GPIOC_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 2))
#define 	GPIOD_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 3))
#define 	GPIOE_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 4))
#define 	GPIOF_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 5))
#define 	GPIOG_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 6))
#define 	GPIOH_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 7))
#define 	GPIOI_REGISTER_RESET()		(RCC->AHB1RSTR |= (1 << 8))

#include "STM32F407_GPIO.h"

#endif /* STM32F407_H_ */
