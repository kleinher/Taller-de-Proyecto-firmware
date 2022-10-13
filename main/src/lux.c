#include "lux.h"
#include "puertos.h"
#include "sapi.h"

int lux_status=OFF;

void lux_on(){
   lux_status=ON;    // habilitar LDR
}

void lux_off() {
   lux_status=OFF;   // deshabilitar LDR
}

int lux_toggle() {
   /*if (!gpioRead(LUX_ENABLE)) {        // ver si se presionó la entrada de control
         delay(50);
         return gpioRead(LUX_ENABLE);
   }*/
   /*int valor = !gpioRead(LUX_ENABLE);
   printf("LUX : %d \n",valor);
   return valor;*/
   if (!gpioRead(LUX_ENABLE)) {
      lux_status=!lux_status;
   }
   printf("* LUX    %d *\n",lux_status);
}

int lux_enabled() {
   return lux_status;
}

int lux_read() {
   /*if (lux_status) {
      return adcRead(LUX_IN);
   } else return 5000; */          // si el sensor está desactivado, devolver "5000" (dato inválido)
   return 5000;
}