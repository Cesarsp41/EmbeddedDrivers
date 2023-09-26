/*
Autor: Cesar Soltero Perez
Fecha Creacion: 09/25/2023
Nombre Archivo: STM32F407.h
Nombre Proyecto: Desarrollo Drivers Embedidos
Este archivo define macros, direcciones de memoria y macros globales referentes al microcontrolador STM32F407
que usa el procesador ARM Cortex M4.
*/

#ifndef STM32F407_H
#define STM32F407_H

//Includes globales
#include <stdint.h>

// Macros globales
#define         __vo        volatile
#define         LOW         0
#define         HIGH        1
#define         DISABLE     LOW
#define         ENABLE      HIGH
#define         DI          DISABLE
#define         EN          ENABLE

// Direcciones base de memorias
#define     SRAM1_BASEADDR      0x20000000U
#define     SRAM2_BASEADDR      0x2001C000U
#define     SRAM3_BASEADDR      0x20020000U

#define     ROM_BASEADDR        0x1FFFFFFFU
#define     FLASH_BASEADDR      0x08000000U

// Direcciones base de buses de comunicacion
//APB Bus
#define     APB1_BASEADDR       0x40000000U
#define     APB2_BASEADDR       0x40010000U
//AHB Bus
#define     AHB1_BASEADDR       0x40020000U
#define     AHB2_BASEADDR       0x50000000U
#define     AHB3_BASEADDR       0xA0000000U

// Direciones base de perifericos
//GPIO
#define     GPIOA_BASEADDR      (AHB1_BASEADDR + 0x0000)
#define     GPIOB_BASEADDR      (AHB1_BASEADDR + 0x0400)
#define     GPIOC_BASEADDR      (AHB1_BASEADDR + 0x0800)
#define     GPIOD_BASEADDR      (AHB1_BASEADDR + 0x0C00)
#define     GPIOE_BASEADDR      (AHB1_BASEADDR + 0x1000)
#define     GPIOF_BASEADDR      (AHB1_BASEADDR + 0x1400)
#define     GPIOG_BASEADDR      (AHB1_BASEADDR + 0x1800)
#define     GPIOH_BASEADDR      (AHB1_BASEADDR + 0x1C00)
#define     GPIOI_BASEADDR      (AHB1_BASEADDR + 0x2000)
#define     GPIOJ_BASEADDR      (AHB1_BASEADDR + 0x2400)
#define     GPIOK_BASEADDR      (AHB1_BASEADDR + 0x2800)
//SPI
#define     SPI2_BASEADDR       (APB1_BASEADDR + 0x3800)
#define     SPI3_BASEADDR       (APB1_BASEADDR + 0x3C00)
#define     SPI1_BASEADDR       (APB2_BASEADDR + 0x3000)
#define     SPI4_BASEADDR       (APB2_BASEADDR + 0x3400)
//I2C
#define     I2C1_BASEADDR       (APB1_BASEADDR + 0x5400)
#define     I2C2_BASEADDR       (APB1_BASEADDR + 0x5800)
#define     I2C3_BASEADDR       (APB1_BASEADDR + 0x5C00)
//USART
#define     USART2_BASEADDR     (APB1_BASEADDR + 0x4400)
#define     USART3_BASEADDR     (APB1_BASEADDR + 0x4800)
#define     UART4_BASEADDR      (APB1_BASEADDR + 0x4C00)
#define     UART5_BASEADDR      (APB1_BASEADDR + 0x5000)
#define     UART7_BASEADDR      (APB1_BASEADDR + 0x7800)
#define     UART8_BASEADDR      (APB1_BASEADDR + 0x7C00)
#define     USART1_BASEADDR     (APB2_BASEADDR + 0x1000)
#define     USART6_BASEADDR     (APB2_BASEADDR + 0x1400)
//SYSCFG
#define     SYSCFG_BASEADDR     (APB2_BASEADDR + 0x3800)
//EXTI
#define     EXTI_BASEADDR       (APB2_BASEADDR + 0x3C00)
//RCC 
#define     RCC_BASEADDR        (AHB1_BASEADDR + 0x3800)

// Definicion de registros perifericos
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
} GPIO_RegDef_t;

//SPI
typedef struct
{
  __vo uint32_t CR1;
  __vo uint32_t CR2;
  __vo uint32_t SR;
  __vo uint32_t DR;
  __vo uint32_t CRCPR;
  __vo uint32_t RXCRCR;
  __vo uint32_t TXCRCR;
  __vo uint32_t I2SCFGR;
  __vo uint32_t I2SPR;
} SPI_RegDef_t;

//I2C
typedef struct
{
  __vo uint32_t CR1;
  __vo uint32_t CR2;
  __vo uint32_t OAR1;
  __vo uint32_t OAR2;
  __vo uint32_t DR;
  __vo uint32_t SR1;
  __vo uint32_t SR2;
  __vo uint32_t CCR;
  __vo uint32_t TRISE;
  __vo uint32_t FLTR;
} I2C_RegDef_t;

//USART
typedef struct
{
  __vo uint32_t SR;
  __vo uint32_t DR;
  __vo uint32_t BRR;
  __vo uint32_t CR1;
  __vo uint32_t CR2;
  __vo uint32_t CR3;
  __vo uint32_t GTPR;
} USART_RegDef_t;

//SYSCFG
typedef struct
{
  __vo uint32_t MEMRMP;
  __vo uint32_t PMC;
  __vo uint32_t EXTICR[4];
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
} EXTI_RegDef_t;

//RCC
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
  __vo uint32_t RESERVED7[2];
  __vo uint32_t SSCGR;
  __vo uint32_t PLLI2SCFGR;
} RCC_RegDef_t;

// Macros perifericos
//Punteros casteados
//GPIO
#define     GPIOA           ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define     GPIOB           ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define     GPIOC           ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define     GPIOD           ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define     GPIOE           ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define     GPIOF           ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define     GPIOG           ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define     GPIOH           ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define     GPIOI           ((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define     GPIOJ           ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define     GPIOK           ((GPIO_RegDef_t*)GPIOK_BASEADDR)
//SPI
#define     SPI1            ((SPI_RegDef_t*)SPI1_BASEADDR)
#define     SPI2            ((SPI_RegDef_t*)SPI2_BASEADDR)
#define     SPI3            ((SPI_RegDef_t*)SPI3_BASEADDR)
#define     SPI4            ((SPI_RegDef_t*)SPI3_BASEADDR)
//I2C
#define     I2C1            ((I2C_RegDef_t*)I2C1_BASEADDR)
#define     I2C2            ((I2C_RegDef_t*)I2C2_BASEADDR)
#define     I2C3            ((I2C_RegDef_t*)I2C3_BASEADDR)
//USART
#define     USART1          ((USART_RegDef_t*)USART1_BASEADDR)
#define     USART2          ((USART_RegDef_t*)USART2_BASEADDR)
#define     USART3          ((USART_RegDef_t*)USART3_BASEADDR)
#define     UART4           ((USART_RegDef_t*)UART4_BASEADDR)
#define     UART5           ((USART_RegDef_t*)UART5_BASEADDR)
#define     USART6          ((USART_RegDef_t*)USART6_BASEADDR)
#define     UART7           ((USART_RegDef_t*)UART7_BASEADDR)
#define     UART8           ((USART_RegDef_t*)UART8_BASEADDR)
//SYSCFG
#define     SYSCFG          ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
//EXTI
#define     EXTI            ((EXTI_RegDef_t*)EXTI_BASEADDR)
//RCC
#define     RCC             ((RCC_RegDef_t*)RCC_BASEADDR)

//Macros para habilitar relojes
/*
    Por default, la mayoria de perifericos del microcontrolador estan
    en reposo, es decir, su reloj no esta activo. Para activar el reloj 
    de un periferico en especifico, debe modificarse el registro
    correspondiente en RCC. Para esto, debe crearse un puntero
    de la estructura RCC_RegDef_t inicializado con RCC_BASEADDR y tocar
    el bit correspondiente.
    
    Logica del macro para habilitar el reloj:
    
    RCC_RegDef_t *puntero = RCC_BASEADDR;
    
    Sin embargo, RCC_BASEADDR es de tipo unsigned int, por lo que debe
    castearse al tipo correspondiente.
    
    RCC_RegDef_t *puntero = ((RCC_RegDef_t*)RCC_BASEADDR);
    
    Como existen muchos perifericos, es buena idea crear macros
    para el casteo de los punteros de las estructuras _t
    
    En caso de RCC:
    
    #define     RCC     ((RCC_RegDef_t*)RCC_BASEADDR)
    
    Como RCC ya es un puntero inicializado a RCC_BASEADDR, ya se puede
    usar el operador * para referenciar los miembros de la estructura
    RCC->xxx_xxx_xxx
*/

//GPIO Clock Enable
#define         GPIOA_CLK_EN()              (RCC->AHB1ENR |= (1 << 0))
#define         GPIOB_CLK_EN()              (RCC->AHB1ENR |= (1 << 1))
#define         GPIOC_CLK_EN()              (RCC->AHB1ENR |= (1 << 2))
#define         GPIOD_CLK_EN()              (RCC->AHB1ENR |= (1 << 3))
#define         GPIOE_CLK_EN()              (RCC->AHB1ENR |= (1 << 4))
#define         GPIOF_CLK_EN()              (RCC->AHB1ENR |= (1 << 5))
#define         GPIOG_CLK_EN()              (RCC->AHB1ENR |= (1 << 6))
#define         GPIOH_CLK_EN()              (RCC->AHB1ENR |= (1 << 7))
#define         GPIOI_CLK_EN()              (RCC->AHB1ENR |= (1 << 8))
//SPI Clock Enable
#define         SPI1_CLK_EN()               (RCC->APB2ENR |= (1 << 12))
#define         SPI2_CLK_EN()               (RCC->APB1ENR |= (1 << 14))
#define         SPI3_CLK_EN()               (RCC->APB1ENR |= (1 << 15))
//I2C Clock Enable
#define         I2C1_CLK_EN()               (RCC->APB1ENR |= (1 << 21))
#define         I2C2_CLK_EN()               (RCC->APB1ENR |= (1 << 22))
#define         I2C3_CLK_EN()               (RCC->APB1ENR |= (1 << 23))
//USART Clock Enable
#define         USART1_CLK_EN()             (RCC->APB2ENR |= (1 << 4))
#define         USART2_CLK_EN()             (RCC->APB1ENR |= (1 << 17))
#define         USART3_CLK_EN()             (RCC->APB1ENR |= (1 << 18))
#define         UART4_CLK_EN()              (RCC->APB1ENR |= (1 << 19))
#define         UART5_CLK_EN()              (RCC->APB1ENR |= (1 << 20))
#define         USART6_CLK_EN()             (RCC->APB2ENR |= (1 << 5))
//SYSCFG Clock Enable
#define         SYSCFG_CLK_EN()             (RCC->APB2ENR |= (1 << 14))

//Macros para deshabilitar relojes
//GPIO Clock Disable
#define         GPIOA_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 0))
#define         GPIOB_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 1))
#define         GPIOC_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 2))
#define         GPIOD_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 3))
#define         GPIOE_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 4))
#define         GPIOF_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 5))
#define         GPIOG_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 6))
#define         GPIOH_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 7))
#define         GPIOI_CLK_DI()              (RCC->AHB1ENR &= ~(1 << 8))
//SPI Clock Disable
#define         SPI1_CLK_DI()               (RCC->APB2ENR &= ~(1 << 12))
#define         SPI2_CLK_DI()               (RCC->APB1ENR &= ~(1 << 14))
#define         SPI3_CLK_DI()               (RCC->APB1ENR &= ~(1 << 15))
//I2C Clock Disable
#define         I2C1_CLK_DI()               (RCC->APB1ENR &= ~(1 << 21))
#define         I2C2_CLK_DI()               (RCC->APB1ENR &= ~(1 << 22))
#define         I2C3_CLK_DI()               (RCC->APB1ENR &= ~(1 << 23))
//USART Clock Disable
#define         USART1_CLK_DI()             (RCC->APB2ENR &= ~(1 << 4))
#define         USART2_CLK_DI()             (RCC->APB1ENR &= ~(1 << 17))
#define         USART3_CLK_DI()             (RCC->APB1ENR &= ~(1 << 18))
#define         UART4_CLK_DI()              (RCC->APB1ENR &= ~(1 << 19))
#define         UART5_CLK_DI()              (RCC->APB1ENR &= ~(1 << 20))
#define         USART6_CLK_DI()             (RCC->APB2ENR &= ~(1 << 5))
//SYSCFG Clock Disable
#define         SYSCFG_CLK_DI()             (RCC->APB2ENR &= ~(1 << 14))

// Miscelaneos
#enfif				/* STM32F407_H */
