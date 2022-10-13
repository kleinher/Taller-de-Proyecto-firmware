#include "sapi.h"
#include "puertos.h"

/*
   FUNCION PUERTOS_INIT()
      RECIBE:  NADA
      RETORNA: NADA
      
      INICIALIZA LOS PUERTOS DE LA EDU-CIAA
*/

void puertos_init() {
   /*
      INICIALIZAR LOS PUERTOS DIGITALES A UTILIZAR
   */
   //gpioInit(RELAY_OUT,  GPIO_OUTPUT);     // salida RELAY
   gpioInit(TOGGLE_IN,  GPIO_INPUT);      // entrada toggle  RELAY
   gpioInit(PIR_IN,     GPIO_INPUT);      // entrada sensor  PIR
   gpioInit(LED_TOGGLE, GPIO_INPUT);      // entrada toggle  LED
   gpioInit(PIR_ENABLE, GPIO_INPUT);      // entrada control PIR
   gpioInit(PIR_ST_OUT, GPIO_OUTPUT);     // salida  estado  PIR
   gpioInit(LUX_ST_OUT, GPIO_OUTPUT);     // salida  estado  LUX
   gpioInit(LUX_ENABLE, GPIO_INPUT);      // entrada control LUX
}