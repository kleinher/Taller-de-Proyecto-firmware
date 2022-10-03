/* * * *   LIBRERIAS   * * * */

#include "sapi.h"

/* * * *   DEFINICIONES DE PUERTOS GPIO   * * * */

#define	RELAY_OUT	GPIO0	// salida CIAA -> RELAY
#define	TOGGLE_IN	GPIO2	// entrada de encendido de lámpara
#define TOGGLE_IN_T	TEC4	// entrada de encendido de lámpara (para prueba de concepto)
#define	PIR_IN		GPIO4	// entrada de sensor de movimiento
#define MODE_IN		GPIO6	// entrada de selector de modo
#define MODE_IN_T	TEC3	// entrada de selector de modo (para prueba de concepto)

int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   uint8_t	valor_tecla = OFF,	// inicialmente no se pulsó nada
   		valor_relay = ON;	// inicialmente la luz está apagada (es "activo en bajo")
   		sensor_enabled = OFF;	// por defecto, el sensor inicia apagado
   
   gpioInit(RELAY_OUT,GPIO_OUTPUT);	// establecer modalidad de los pines
   gpioInit(TOGGLE_IN,GPIO_INPUT);	// GPIO de la EDU-CIAA que se
   gpioInit(PIR_IN,GPIO_INPUT);		// van a usar.
   gpioInit(MODE_IN,GPIO_INPUT);

   /* Establecer el estado inicial del relay -> podría verse un destello en la luz al
      iniciar el sistema */
   gpioWrite(RELAY_OUT,valor_relay);

   /* bucle principal */
   while(1) {
      /* Leer estado de la tecla de encendido -> si cambió desde la última lectura, alternar
         el estado de la luz.

         Si no se pulsó la tecla pero si:
             1. El sensor está habilitado
             2. El sensor envía '1'
         Entonces encender la luz, sin importar si está encendida. 

         Recordar que, para el relay, ON es 'apagado' y OFF es 'encendido' */

      if (!gpioRead(TOGGLE_IN_T)) {
          valor_relay=!valor_relay;
          gpioWrite(RELAY_OUT,valor_relay);
      } else if (sensor_enabled && gpioRead(PIR_IN)) gpioWrite(RELAY_OUT,OFF);

      /* Leer el selector de modo */
      if (!gpioRead(MODE_IN_T) sensor_enabled=!sensor_enabled; // toggle del modo de operación
      //sensor_enabled=gpioRead(MODE_IN_T);
      gpioWrite(LED1,sensor_enabled);     // visualizar modo en LED1
      gpioWrite(LED2,gpioRead(PIR_IN);    // encender LED2 si se detecta movimiento
   }

   return 0 ;
}