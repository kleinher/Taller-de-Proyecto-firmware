#ifndef PUERTOS_H_
#define PUERTOS_H_

/* * * *   DEFINICIONES DE PUERTOS DEL PONCHO   * * * */

// LUCES
#define	RELAY_OUT	GPIO0       // salida CIAA -> RELAY
#define	TOGGLE_IN	TEC4	      // interruptor de encendido de lámpara
#define  LED_TOGGLE  GPIO6       // interruptor de encendido de LED

// SENSOR PIR
#define  PIR_IN		GPIO4	      // entrada de sensor de movimiento (salida PIR -> entrada CIAA)
#define  PIR_ENABLE  TEC3       // entrada de control del PIR
#define  PIR_ST_OUT  LED3       // salida a LED de estado del PIR
#define  PIR_DETECT  LED1

// SENSOR DE LUZ
#define  LUX_ENABLE  GPIO7       // entrada de control del LUX
#define  LUX_ST_OUT  GPIO5       // salida a LED de estado del LUX

void puertos_init();

#endif