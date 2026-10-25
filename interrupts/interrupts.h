#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define UART_IER (*(volatile char *) 0xB80003F9)
#define UART_IIR (*(volatile char *) 0xB80003FA)

void uart_init(void);
void interrupt_handler(unsigned int, unsigned int *);

#endif
