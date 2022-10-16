#include "luces.h"
#include "puertos.h"
#include "sapi.h"

int   relay_status=ON,        // estado del relay
      relay_previous=ON,      // estado previo del relay
      
      toggle_status=OFF,
      led_status=OFF;

int relay_change() {
   return (relay_previous==relay_status);
}

void relay_off() {
   relay_status=ON;        // apagar relay
}

void relay_on() {
   relay_status=OFF;       // encender relay
}

void relay_toggle() {
   relay_previous=relay_status;           // actualizar estado
   gpioWrite(RELAY_OUT,!relay_status);    // conmutar relay
   printf("*********************************************************** RELAY : %d *\n",relay_status);    // debug
}

int toggle_read() {
   if (!gpioRead(TOGGLE_IN)) toggle_status=!toggle_status;  // leer la entrada de control
   printf("* TOGGLE %d *\n",toggle_status);  // debug
   return toggle_status;                                    // y devolver el resultado
}

void led_bright(int b) {                     // dar brillo al LED (versión DAC)
   if (led_status) {
      dacWrite(LED_OUT, b);
      printf("* POT    %d *\n",b);     // debug
   } else printf("* POT    OFF *\n");  // debug
}

void led_toggle() {
   if (!gpioRead(LED_TOGGLE)) led_status=!led_status;       // leer entrada de control y actualizar el estado del led
}

int pot_read() {                             // leer potenciometro y devolver el valor
   return adcRead(POT_IN);
}