/*
   Tareas por hacer:
   
   1. corregir el bounce en las teclas
   2. implementar sensor de luminosidad con adc
   3. implementar dimmer con pwm (o con dac???)
   4. leds de estado
   5. ver que si el sensor capta algo y apago la deteccion, la luz queda prendida (???)
*/

/* * * *   LIBRERIAS   * * * */

#include "luces.h"         // control de las luces, relay y LED
#include "lux.h"           // control de sensor de luminosidad LDR
#include "pir.h"           // control de sensor de movimiento PIR
#include "puertos.h"       // definiciones e inicialización de puertos GPIO
#include "sapi.h"          // librería sAPI

/* * * *   DEFINICIONES DE PUERTOS DE ADC/DAC   * * * */

int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   puertos_init();         // inicializa puertos de la EDU-CIAA
   
   relay_off();            // apaga la luz
   led_bright(0);          // apaga la luz LED (intensidad en 0%)
   
   adcConfig(ADC_ENABLE);  // habilitar ADC
   dacConfig(DAC_ENABLE);  // habilitar DAC
   
   pir_off();              // deshabilita PIR
   lux_off();              // deshabilita LUX

   /* bucle principal */
   while(1) {      
      /*
         Encender la luz si se da alguna o varias de las siguientes condiciones:
            A. Se prende manualmente a través de la entrada TOGGLE_IN
            B. Se recibe un '1' del sensor PIR
            C. Se recibe un valor < 200 del sensor LDR
      */
      
      if (toggle_read()) {    // si se pulsó la tecla, conmutar estado
         relay_toggle();
      }
      
      if ((pir_read()) || (lux_read()<200)) {  // si se recibe algo de los sensores, prender si o si
         relay_on();
      } else {
         if ((pir_enabled()) || (lux_enabled()))
            relay_off();
      }
      
      /*
         Leer potenciómetro y ajustar el brillo del LED
      */
      led_bright(pot_read());
      
      /*
         Comprobar entradas de control de los sensores, para ver si debo activar o desactivar alguno
      */
      if (pir_toggle()) {                                // comprobación entrada PIR_ENABLE
         if (pir_enabled()) pir_off(); else pir_on();
      }
      
      if (lux_toggle()) {                                // comprobación entrada LUX_ENABLE
         if (lux_enabled()) lux_off(); else lux_on();
      }
   }

   return 0 ;
}