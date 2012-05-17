#ifndef _COMMON_UART_H_
#define _COMMON_UART_H_
#include <avr/pgmspace.h>
#include "config.h"
#ifndef UART_BAUDRATE
#define UART_BAUDRATE 9600
#endif
void uart_init(void);
void uart_putc(char c);
void uart_puts(const char *s);
void uart_puts_P(PGM_P s);
#endif /* _COMMON_UART_H_ */
