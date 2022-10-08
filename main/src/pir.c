/* * * *   CODIGO DEL SENSOR PIR   * * * */

#include "sapi.h"
#include "pir.h"
#include "puertos.h"

uint8_t  pir_status = 0,       // inicialmente, el PIR está desactivado
         pir_value;              // valor leído desde el PIR

void pir_toggle() {   
   if (!gpioRead(PIR_ENABLE)) {
         delay(50);
         if (gpioRead(PIR_ENABLE)) {
            pir_status=!pir_status;                // conmutar estado
            gpioWrite(PIR_ST_OUT, pir_status);    // y actualizar el LED de estado
         }
   }
}

void pir_off() {
   pir_status=0;                     // apagar PIR
   gpioWrite(PIR_ST_OUT, OFF);         // y actualizar el LED de estado
}

uint8_t pir_check() {
   if (!gpioRead(PIR_ENABLE)) {
      delay(50);
      if (gpioRead(PIR_ENABLE)) return 1; else return 0;
   }
}

uint8_t pir_enabled() {
   return pir_status;
}

uint8_t pir_read() {
   if (gpioRead(PIR_IN)) {
      delay(50);
      if (gpioRead(PIR_IN)) {
         gpioWrite(RELAY_OUT,OFF);  // si hubo movimiento, prendo luz
         gpioWrite(PIR_DETECT,ON);
         delay(450);
      }
   } else {
      delay(50);
      if (!gpioRead(PIR_IN)) {
         gpioWrite(RELAY_OUT,ON);   // si no hubo movimiento, apago luz
         gpioWrite(PIR_DETECT,OFF);
         delay(450);
      }
   }
}