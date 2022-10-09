/* * * *   CODIGO DEL SENSOR PIR   * * * */

#include "sapi.h"
#include "pir.h"
#include "puertos.h"

int   pir_status = OFF,       // inicialmente, el PIR está desactivado
      pir_value;              // valor leído desde el PIR

/*void pir_toggle() {   
   if (!gpioRead(PIR_ENABLE)) {
         delay(50);
         if (gpioRead(PIR_ENABLE)) {
            pir_status=!pir_status;                // conmutar estado
            gpioWrite(PIR_ST_OUT, pir_status);    // y actualizar el LED de estado
         }
   }
}*/

void pir_off() {
   pir_status=OFF;                     // apagar PIR
   gpioWrite(PIR_ST_OUT, OFF);         // y actualizar el LED de estado
}

void pir_on() {
   pir_status=ON;                      // encender PIR
   gpioWrite(PIR_ST_OUT, ON);          // y actualizar el LED de estado
}

int pir_toggle() {
   if (!gpioRead(PIR_ENABLE)) {        // ver si se presionó la entrada de control
         delay(50);
         return gpioRead(PIR_ENABLE);
   }
}

/*int pir_check() {
   if (!gpioRead(PIR_ENABLE)) {
      delay(50);
      if (gpioRead(PIR_ENABLE)) return 1; else return 0;
   }
}*/

int pir_enabled() {
   return pir_status;
}

/*
   Funcion PIR_READ
      RECIBE   NADA
      RETORNA  0: NO HAY MOVIMIENTO, 1: HAY MOVIMIENTO

   Lee el puerto del sensor PIR y devuelve si hay o no movimiento siempre y cuando esté habilitado el sensor.
*/

int pir_read() {
   /*if (gpioRead(PIR_IN)) {
      delay(50);
      if (gpioRead(PIR_IN)) {
         gpioWrite(RELAY_OUT,OFF);  // si hubo movimiento, prendo luz
         delay(450);
      }
   } else {
      delay(50);
      if (!gpioRead(PIR_IN)) {
         gpioWrite(RELAY_OUT,ON);   // si no hubo movimiento, apago luz
         delay(450);
      }
   }*/
   int estado=!gpioRead(PIR_IN);
   delay(50);
   estado=gpioRead(PIR_IN);
   if (pir_status) return estado; else return 0;
}