#ifndef PUERTOS_H_
#define PUERTOS_H_

/* * * *   DEFINICIONES DE PUERTOS DEL PONCHO   * * * */

// LUCES
#define	RELAY_OUT	LCD1        // salida CIAA -> RELAY
#define  LED_OUT     PWM2        // salida CIAA -> LED (PWM2 es el TCOL0 según sapi_pwm.c, línea 96)

// SENSORES
#define  PIR_IN		LCD2	      // entrada de sensor de movimiento (salida PIR -> entrada CIAA)
#define  LUX_IN      CH1         // entrada analógica del LDR
#define  POT_IN      CH2         // entrada analógica del potenciómetro (control intensidad LED)

// ENTRADAS DE CONTROL
#define  TOGGLE_IN   GPIO1       // interruptor de encendido de lámpara
#define  LED_TOGGLE  GPIO3       // interruptor de encendido de LED
#define  PIR_ENABLE  GPIO7      // entrada de control del PIR
#define  LUX_ENABLE  GPIO8      // entrada de control del LDR

#define  MODE_TOGGLE GPIO5       // entrada de control de modo.


// SALIDAS DE ESTADO
#define  RELAY_ST_OUT  LEDR     // salida control rele
#define  LED_ST_OUT  LEDB       // salida control tira led
#define  PIR_ST_OUT  LED1        // salida a LED de estado del PIR
#define  LUX_ST_OUT  LED2        // salida a LED de estado del LDR
#define  MODE_ST_OUT LED3      // salida a LED de estado de modo




// UART
#define  UART_RX     RS232_RX    // conexión RX UART (pin 23 conector J1 EDU-CIAA)
#define  UART_TX     RS232_TX    // conexión TX UART (pin 25 conector J1 EDU-CIAA)

void puertos_init();

#endif