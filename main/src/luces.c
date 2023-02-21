/*
   CONTROL DE LUCES
   
   CONSTANTINO PALACIO, OCT-22.
*/

#include "luces.h"
#include "puertos.h"
#include "sapi.h"

int   relay_status=ON,        // estado del relay
      relay_previous=ON,      // estado previo del relay
      
      toggle_status=OFF,
      led_status=OFF;
      
uint8_t  valor_pwm=0;

int relay_change() {
   return (relay_previous==relay_status);
}

void relay_off() {
   relay_status=ON;        // apagar relay
   //gpioWrite(RELAY_ST_OUT,ON);
}

void relay_on() {
   relay_status=OFF;       // encender relay
   //gpioWrite(RELAY_ST_OUT,OFF);
}

void relay_toggle() {
   relay_previous=relay_status;           // actualizar estado
   gpioWrite(RELAY_OUT,!relay_status);    // conmutar relay
   //printf("*********************************************************** RELAY : %d *\n",relay_status);    // debug
}

int toggle_read() {
   if (!gpioRead(TOGGLE_IN)){
      //delay(10);
      //if (!gpioRead(TOGGLE_IN)){
      toggle_status=!toggle_status; 
      //}
   } // leer la entrada de control
      
   //DEBUG
   /*if(toggle_status)
      gpioWrite(RELAY_ST_OUT,ON);
   else
      gpioWrite(RELAY_ST_OUT, OFF);*/
   
   //printf("* TOGGLE %d *\n",toggle_status);  // debug
   return toggle_status;                                    // y devolver el resultado
}

void led_bright(int b) {                     // dar brillo al LED   
   gpioWrite(LED_ST_OUT, led_status);     // debug
   if (led_status) {
      pwmWrite(LED_OUT, (int) (255 * (b / 1023.0)));
      //printf("* POT    %d *\n",b);     // debug
   } //else printf("* POT    OFF *\n");  // debug
}
void led_on()
{
   led_status=ON;
}
void led_off()
{
   led_status=OFF;
   pwmWrite(LED_OUT,0);
}
void led_toggle() {
   if (!gpioRead(LED_TOGGLE))
   { 
      delay(10);
      if (!gpioRead(LED_TOGGLE))
      {
         led_status=!led_status;
      }       // leer entrada de control y actualizar el estado del led
   }
   
   //DEBUG
   if(led_status){
      led_on();
      gpioWrite(LED_ST_OUT,ON);}
   else{
      led_off();
      gpioWrite(LED_ST_OUT, OFF);}
}

int pot_read() {                             // leer potenciometro y devolver el valor
   return adcRead(POT_IN);
}