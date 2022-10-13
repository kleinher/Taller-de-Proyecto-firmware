#ifndef PUERTOS_H_
#define PUERTOS_H_

/* * * *   DEFINICIONES DE PUERTOS DEL PONCHO   * * * */

// LUCES
#define	RELAY_OUT	LED1       // salida CIAA -> RELAY
#define  LED_OUT     DAC         // salida CIAA -> LED

// SENSORES
#define  PIR_IN		GPIO4	      // entrada de sensor de movimiento (salida PIR -> entrada CIAA)
#define  LUX_IN      CH1         // entrada analógica del LDR
#define  POT_IN      CH2         // entrada analógica del potenciómetro (control intensidad LED)

// ENTRADAS DE CONTROL
#define  PIR_ENABLE  TEC1       // entrada de control del PIR
#define  LUX_ENABLE  TEC2       // entrada de control del LDR
#define  TOGGLE_IN   TEC3       // interruptor de encendido de lámpara
#define  LED_TOGGLE  TEC4       // interruptor de encendido de LED

// SALIDAS DE ESTADO
#define  PIR_ST_OUT  GPIO3       // salida a LED de estado del PIR
#define  LUX_ST_OUT  GPIO5       // salida a LED de estado del LDR

void puertos_init();

#endif