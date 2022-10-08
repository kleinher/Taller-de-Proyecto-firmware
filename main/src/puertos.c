#include "sapi.h"
#include "puertos.h"

void puertos_init() {
   gpioInit(RELAY_OUT,GPIO_OUTPUT);	   // establecer modalidad de los pines
   gpioInit(TOGGLE_IN,GPIO_INPUT);	   // GPIO de la EDU-CIAA que se
   gpioInit(PIR_IN,GPIO_INPUT);		   // van a usar.
   gpioInit(LED_TOGGLE,GPIO_INPUT);
   
   /* Establecer el estado inicial del relay -> podría verse un destello en la luz al
      iniciar el sistema */
   
   gpioWrite(RELAY_OUT,ON);      // inicialmente apagado
   
   /* Inicializar AnalogIO */
   /* Posibles configuraciones:
    *    ADC_ENABLE,  ADC_DISABLE,
    *    ADC_ENABLE,  ADC_DISABLE,
    */
   
   //adcConfig( ADC_ENABLE ); /* ADC */
   //dacConfig( DAC_ENABLE ); /* DAC */
}