/*
   Tareas por hacer:
   
   1. corregir el bounce en las teclas
   2. implementar sensor de luminosidad con adc
   3. implementar dimmer con pwm (o con dac???)
   4. led de estado
   5. ver que si el sensor capta algo y apago la deteccion, la luz queda prendida (???)
*/

/* * * *   LIBRERIAS   * * * */

#include "sapi.h"
#include "puertos.h"
#include "pir.h"

/* * * *   DEFINICIONES DE PUERTOS DE ADC/DAC   * * * */

int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   uint8_t	valor_tecla = OFF,	// inicialmente no se pulsó nada
   		valor_relay = ON;	// inicialmente la luz está apagada (es "activo en bajo")
   		//sensor_enabled = OFF;	// por defecto, el sensor inicia apagado
   
   puertos_init();   // inicializar puertos CIAA y apagar relay
   pir_off();        // el sensor PIR inicia apagado

   /* bucle principal */
   while(1) {
      /* Leer estado de la tecla de encendido

         Si no se pulsó la tecla pero si:
             1. El sensor está habilitado, y
             2. El sensor envía '1'
         Entonces encender la luz, sin importar el estado actual. 

         Recordar que, para el relay, ON es 'apagado' y OFF es 'encendido' */

      /*if (!gpioRead(TOGGLE_IN)) {          // ver tecla de encendido
         delay(50);
         if (gpioRead(TOGGLE_IN)) {
            valor_relay=!valor_relay;
            gpioWrite(RELAY_OUT,valor_relay);
            delay(450); // retardo de relay
         }
         
      } else {*/
         if (pir_enabled()) pir_read();    // leer el sensor de movimiento (si corresponde)
      //}
      /*else if (sensor_enabled) {
         if (gpioRead(PIR_IN)) {
            delay(50);
            if (gpioRead(PIR_IN)) {
               gpioWrite(RELAY_OUT,OFF); // si hubo movimiento, prendo luz
               delay(450);
            }
         } else {
            delay(50);
            if (!gpioRead(PIR_IN)) {
               gpioWrite(RELAY_OUT,ON); // si no hubo movimiento, apago luz
               delay(450);
            }
         }
      }*/

      /* Leer el selector de modo */
      /*if (!gpioRead(MODE_IN_T)) {
         delay(50);
         if (gpioRead(MODE_IN_T)) sensor_enabled=!sensor_enabled;
      }*/
      
      // activar/desactivar sensores
      pir_toggle();         // ver el estado del PIR y actuar
      
      //gpioWrite(LED1,sensor_enabled);      // visualizar modo en LED1
      //gpioWrite(LED2,gpioRead(PIR_IN));    // encender LED2 si se detecta movimiento
   }

   return 0 ;
}