/*
   INICIALIZACION DE PUERTOS Y PERIFERICOS EDU-CIAA-NXP
   
   CONSTANTINO PALACIO, OCT-22.
*/

#include "sapi.h"
#include "puertos.h"

/*
   FUNCION PUERTOS_INIT()
      RECIBE:  NADA
      RETORNA: NADA
      
      INICIALIZA LOS PUERTOS DE LA EDU-CIAA
*/

void puertos_init() {
   int valor;
   
   /*
      INICIALIZAR LOS PUERTOS DIGITALES A UTILIZAR
   */
   gpioInit(RELAY_OUT,  GPIO_OUTPUT);     // salida RELAY
   
   gpioInit(TOGGLE_IN,  GPIO_INPUT);      // entrada toggle  RELAY
   gpioInit(LED_TOGGLE, GPIO_INPUT);      // entrada toggle  LED
   
   gpioInit(PIR_IN,     GPIO_INPUT);      // entrada sensor  PIR
   gpioInit(PIR_ENABLE, GPIO_INPUT);      // entrada control PIR
   gpioInit(PIR_ST_OUT, GPIO_OUTPUT);     // salida  estado  PIR
   
   gpioInit(LUX_ST_OUT, GPIO_OUTPUT);     // salida  estado  LUX
   gpioInit(LUX_ENABLE, GPIO_INPUT);      // entrada control LUX
   
   gpioInit(MODE_TOGGLE,GPIO_INPUT);      // entrada control modo
   gpioInit(MODE_ST_OUT,GPIO_OUTPUT);     // salida  estado  modo
   
   /*
      INICIALIZAR PERIFERICOS ANALOGICOS USADOS: ADC Y PWM
   */
   adcConfig(ADC_ENABLE);                          // habilitar ADC
   
   valor = pwmConfig(0, PWM_ENABLE);               // Configurar PWM
   valor = pwmConfig(LED_OUT, PWM_ENABLE_OUTPUT);  // salida de LED
}