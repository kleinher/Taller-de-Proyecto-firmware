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
   
   delay_t delay1;
   delay_t delay2;

   /* Inicializar Retardo no bloqueante con tiempo en ms */
   delayConfig(&delay1,100);
   delayConfig(&delay2,500);

   /* bucle principal */
   while(1) {      
      /*
         Encender la luz si se da alguna o varias de las siguientes condiciones:
            A. Se prende manualmente a través de la entrada TOGGLE_IN
            B. Se recibe un '1' del sensor PIR
            C. Se recibe un valor < 200 del sensor LDR
      */
      
      // leer entradas de control cada 50ms
      if (delayRead(&delay1)) {
         
         // leer entradas de control de los sensores
         pir_toggle();
         lux_toggle();
         
         // leer entrada de control de luz LED
         led_toggle();
         
         /*if (pir_toggle()) { if (pir_enabled()) pir_off; else pir_on; }
         if (lux_toggle()) { if (lux_enabled()) lux_off; else lux_on; }*/
         
         // si los sensores están activados, cualquiera enciende la luz
         //if ((pir_enabled()) || (lux_enabled())) {
            if ((pir_read()) || (lux_read()<200) || (toggle_read())) relay_on(); else relay_off();
               
         // si los sensores están desactivados, entonces solo el toggle enciende la luz
         //} else { if (toggle_read()) relay_on(); else relay_off(); }
         
            
         /*
            Leer potenciómetro y ajustar el brillo del LED
         */
         led_bright(pot_read());
            
      }
      
      // actualizar el estado del relay cada 500ms
      if (delayRead(&delay2)) relay_toggle();
      
      /*if (toggle_read()) {    // si se pulsó la tecla, conmutar estado
         relay_toggle();
      }*/
      
      /*if ((pir_read()) || (lux_read()<200)) {  // si se recibe algo de los sensores, prender si o si
         relay_on();
      } else {
         if ((pir_enabled()) || (lux_enabled()))
            relay_off();
      }*/
      
      /*
         Comprobar entradas de control de los sensores, para ver si debo activar o desactivar alguno
      */
      /*if (pir_toggle()) {                                // comprobación entrada PIR_ENABLE
         if (pir_enabled()) pir_off(); else pir_on();
      }*/
      
      /*if (lux_toggle()) {                                // comprobación entrada LUX_ENABLE
         if (lux_enabled()) lux_off(); else lux_on();
      }*/
   }

   return 0 ;
}