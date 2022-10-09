#include "luces.h"
#include "puertos.h"
#include "sapi.h"

int relay_status = ON;

void relay_off() {
   relay_status = ON;
   gpioWrite(RELAY_OUT,ON);               // apaga relay
   delay(450);                            // con delay
}

void relay_on() {
   relay_status = OFF;
   gpioWrite(RELAY_OUT,OFF);              // enciende relay
   delay(450);                            // con delay
}

void relay_toggle() {
   relay_status=!relay_status;
   gpioWrite(RELAY_OUT,!relay_status);    // conmutar relay
   delay(450);                            // con delay
}

int toggle_read() {
   int toggle_status = gpioRead(TOGGLE_IN);
   if (!toggle_status) {                        // ver si se presionó la entrada de control
         delay(50);
         toggle_status = gpioRead(TOGGLE_IN);
         return toggle_status;                  // y devolver el resultado
   }
}

void led_bright(int b) {      // dar brillo al LED
   dacWrite(LED_OUT, b);
}

int pot_read() {              // leer potenciometro y devolver el valor
   return adcRead(POT_IN);
}