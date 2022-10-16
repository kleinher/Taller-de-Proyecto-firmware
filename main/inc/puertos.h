#ifndef PUERTOS_H_
#define PUERTOS_H_

/* * * *   DEFINICIONES DE PUERTOS DEL PONCHO   * * * */

// LUCES
#define	RELAY_OUT	GPIO0       // salida CIAA -> RELAY
#define  LED_OUT     GPIO8       // salida CIAA -> LED (versión DAC)

// SENSORES
#define  PIR_IN		GPIO4	      // entrada de sensor de movimiento (salida PIR -> entrada CIAA)
#define  LUX_IN      CH1         // entrada analógica del LDR
#define  POT_IN      CH2         // entrada analógica del potenciómetro (control intensidad LED)

// ENTRADAS DE CONTROL
#define  PIR_ENABLE  GPIO1       // entrada de control del PIR
#define  LUX_ENABLE  GPIO7       // entrada de control del LDR
#define  TOGGLE_IN   GPIO2       // interruptor de encendido de lámpara
#define  LED_TOGGLE  GPIO6       // interruptor de encendido de LED
#define  MODE_TOGGLE LCD2        // entrada de control de modo

// SALIDAS DE ESTADO
#define  PIR_ST_OUT  GPIO3       // salida a LED de estado del PIR
#define  LUX_ST_OUT  GPIO5       // salida a LED de estado del LDR
#define  MODE_ST_OUT LCD1        // salida a LED de estado de modo

// UART
#define  UART_RX     RS232_RX    // conexión RX UART
#define  UART_TX     RS232_TX    // conexión TX UART

void puertos_init();

#endif