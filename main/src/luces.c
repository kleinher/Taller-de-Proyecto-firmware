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
   relay_status=ON;
   //relay_previous=ON;
   //gpioWrite(RELAY_OUT,ON);               // apaga relay
   //delay(450);                            // con delay
}

void relay_on() {
   relay_status=OFF;
   //relay_previous=OFF;
   //gpioWrite(RELAY_OUT,OFF);              // enciende relay
   //delay(450);                            // con delay
}

void relay_toggle() {
   relay_previous=relay_status; // actualizar estado
   gpioWrite(RELAY_OUT,!relay_status);    // conmutar relay
   printf("*********************************************************** RELAY : %d *\n",relay_status);
   //delay(450);                            // con delay
}

int toggle_read() {
   if (!gpioRead(TOGGLE_IN)) {
      toggle_status=!toggle_status;
   }
   printf("* TOGGLE %d *\n",toggle_status);
   return toggle_status;                  // y devolver el resultado
   //if (!toggle_status) {                        // ver si se presionó la entrada de control
         //delay(50);
         //toggle_status = gpioRead(TOGGLE_IN);
         
   //}
}

void led_bright(int b) {      // dar brillo al LED
   if (led_status) {
      dacWrite(LED_OUT, b);
      printf("* POT    %d *\n",b);
   } else printf("* POT    OFF *\n");
}

void led_toggle() {
   if (!gpioRead(LED_TOGGLE)) {
      led_status=!led_status;
   }
}

int pot_read() {              // leer potenciometro y devolver el valor
   return adcRead(POT_IN);
}