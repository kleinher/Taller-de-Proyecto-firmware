/*
   CONTROL SENSOR LUMINOSIDAD LUX (LDR)
   
   CONSTANTINO PALACIO, OCT-22.
*/

#include "lux.h"
#include "puertos.h"
#include "sapi.h"

int lux_status=OFF;

void lux_on(){
   lux_status=ON;    // habilitar LDR
   
   //DEBUG
   gpioWrite(LUX_ST_OUT, ON);
}

void lux_off() {
   lux_status=OFF;   // deshabilitar LDR
   
   //DEBUG
   gpioWrite(LUX_ST_OUT, OFF);
}

int lux_toggle() {
   if (!gpioRead(LUX_ENABLE)) 
   {
      delay(10);
      if (!gpioRead(LUX_ENABLE)) 
      {
      lux_status=!lux_status;
      }
   }       // ver estado de la entrada de control
   
      
   //DEBUG
   if(lux_status) lux_on();
   else lux_off();
      
   //printf("* LUX    %d *\n",lux_status);
}

int lux_enabled() {
   return lux_status;
}

int lux_read() {
   if (lux_status) {
      int a = adcRead(LUX_IN);
      printf("* LUX    %d *\n",a);
      return a;
      
   } else return 5000;           // si el sensor está desactivado, devolver "5000" (dato inválido)
   //return 5000;
}