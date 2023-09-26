/*
    Nombre: Cesar Soltero Perez
    Archivo: GPIO.h
    Fecha: 9/26/2023
    Descripcion: Este archivo contiene las estructuras de configuracion
    y manejo de los pines GPIO asi como macros utiles, esto para evitar
    los numeros "magicos"
*/

#ifndef GPIO_h
#define GPIO_h

//Includes
#include "STM32F407.h"

//Macros GPIO
//Macros para GPIO_PinMode
#define     GPIO_MODE_INPUT         0
#define     GPIO_MODE_OUTPUT        1
#define     GPIO_MODE_ALTFUN        2
#define     GPIO_MODE_ANALOG        3

//Macros para los numeros de pin
#define     GPIO_PIN_0              0
#define     GPIO_PIN_1              1
#define     GPIO_PIN_2              2
#define     GPIO_PIN_3              3
#define     GPIO_PIN_4              4
#define     GPIO_PIN_5              5
#define     GPIO_PIN_6              6
#define     GPIO_PIN_7              7
#define     GPIO_PIN_8              8
#define     GPIO_PIN_9              9
#define     GPIO_PIN_10             10
#define     GPIO_PIN_11             11
#define     GPIO_PIN_12             12
#define     GPIO_PIN_13             13
#define     GPIO_PIN_14             14
#define     GPIO_PIN_15             15

//Macros para la velocidad de salida
#define     GPIO_SPEED_LOW          0
#define     GPIO_SPEED_MEDIUM       1
#define     GPIO_SPEED_HIGH         2
#define     GPIO_SPEED_VERYHIGH     3

//Macros para el tipo de salida
#define     GPIO_OPTYPE_PUSHPULL    0
#define     GPIO_OPTYPE_OPENDRAIN   1

//Macros para la resistencia de pullup/pulldown
#define     GPIO_PUPD_NO            0
#define     GPIO_PUPD_PU            1
#define     GPIO_PUPD_PD            2

//Macros para funcion alternativa
@TODO

/*
    Deben definirse las funciones que se dan al usuario en la API
    -Inicializar el Puerto
    -Activar el reloj
    -Leer pin
    -Leer Puerto
    -Escribir pin
    -Escribir Puerto
    -Funcion alt
    -Interrupciones 
    
    Para lograr estas funciones los parametros configurables deben ser:
    -Pin
    -Modo I/O
    -Speed
    -PU/PD
    -Open Drain/PUSHPULL
*/

//Estructura de Configuracion
typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinOPSpeed;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinPUPD;
    uint8_t GPIO_PinAltFun;
}GPIO_Config_t;


//Estructura de manejo
typedef struct
{
    GPIO_RegDef_t *pGPIO;
    GPIO_Config_t GPIO_PinConfig;
    
}GPIO_Handle_t;

//Prototipos de funciones para GPIO
@TODO
#endif
