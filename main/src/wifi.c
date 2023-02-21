#include "wifi.h"
#include "sapi.h"     // <= sAPI header
#include "cJSON.h"
#include <stdlib.h>
#include <stdio.h>
#include "puertos.h"
#include "lux.h"
#include "luces.h"
#include "pir.h"
char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}
static cJSON *json;
static char uartBuff[10];
uint16_t i;

int luz_1(){
   cJSON *luz_1 = NULL;
   luz_1 = cJSON_GetObjectItemCaseSensitive(json, "luz_1");
   if(cJSON_IsTrue(luz_1)) 
   {
      gpioWrite(RELAY_ST_OUT,ON);
      //uartWriteString( UART_USB, "luz on \n" );
      return 1;
   } else {
      uartWriteString( UART_USB, "luz off \n" );
      gpioWrite(RELAY_ST_OUT,OFF);
      return 0;
   }
}
int led(){
   cJSON *led = NULL;
   led = cJSON_GetObjectItemCaseSensitive(json, "led");
   if(cJSON_IsTrue(led))
   {
      led_on();
      int a = intensidad();
      printf("intensidad %d",a);
      led_bright(a);
      gpioWrite(LED_ST_OUT,ON);
      //uartWriteString( UART_USB, "luz on \n" );
      return 1;
   } else {
      //uartWriteString( UART_USB, "led off \n" );
      led_off();
      gpioWrite(LED_ST_OUT, OFF);
      return 0;
   }

}
int sensor_luminosidad(){
   cJSON *sensor_luminosidad = NULL;
   sensor_luminosidad = cJSON_GetObjectItemCaseSensitive(json, "sensor_luminosidad");
   if(cJSON_IsTrue(sensor_luminosidad))
   {
      lux_on();
      uartWriteString( UART_USB, "sensor luminosidad on \n" );
      gpioWrite(LUX_ST_OUT,ON);
      return 1;
   } else {
      lux_off();
      uartWriteString( UART_USB, "sensor luminosidad off \n" );
      gpioWrite(LUX_ST_OUT, OFF);
      return 0;
   }

}
int sensor_movimiento(){
   cJSON *sensor_movimiento = NULL;
   sensor_movimiento = cJSON_GetObjectItemCaseSensitive(json, "sensor_movimiento");
   if(cJSON_IsTrue(sensor_movimiento))
   {
      uartWriteString( UART_USB, "sensor movimiento on  \n" );
      pir_on();
      return 1;
   } else {
      uartWriteString( UART_USB, "sensor movimiento off  \n" );
      pir_off();
      return 0;
   }

}
int intensidad(){
   cJSON *intensidad = NULL;
   intensidad = cJSON_GetObjectItemCaseSensitive(json, "sensor_intensidad");
   int a = cJSON_GetNumberValue(intensidad);
   return a;

}
extern int mode_status;
int leerJson(){
   
   char* palabra =  (char *) malloc(150 * sizeof(char));  

   uint16_t size_json = 150;
   uint8_t dato  = 0;
   uint8_t enter = '\n' ;
   i = 0;

   //Leo json de la uart

   while( (i < size_json) && (dato != enter)){
      if (!gpioRead(MODE_TOGGLE)){
         delay(55);
         if (!gpioRead(MODE_TOGGLE)){
            mode_status = 0;
            break;
         }
      }
      if(uartReadByte( UART_232, &dato)){
         palabra[i]=dato;
         //uartWriteByte( UART_USB, dato );
         i++;
      }
   }

   //Verificación de error
   if((i < size_json)){
      palabra[i-1]='\0';
      cJSON_Delete(json);
      json = cJSON_Parse(palabra);

      const char *error_ptr = cJSON_GetErrorPtr();
      if ((error_ptr != NULL || json == NULL)){
         uartWriteString( UART_USB, "error" );
         free(palabra); 
         return 0;
      }
   }
   free(palabra);  
   return 1;
}
int imprimirJson(){
   
   char *string = cJSON_Print(json);
   uartWriteString( UART_USB,  string);
   free(string);
   return 1;
}
int wifiSetup(){
   // ------------- INICIALIZACIONES -------------

   char test[40];
   waitForReceiveStringOrTimeoutState_t * state;
   // Inicializar UART_USB a 115200 baudios
   uartConfig( UART_USB, 9600 );
   // Inicializar UART_USB a 115200 baudios
   uartConfig( UART_232, 9600 );
   
   char* string = "\n";

   

   uartWriteString( UART_USB, "Setup wifi config...\r\n" ); 
   uartWriteString( UART_USB, "\r\n" ); // Enviar un Enter
}
