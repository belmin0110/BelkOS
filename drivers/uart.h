#ifndef UART_H
#define UART_H

#define UART_TDR (*(volatile char *) 0xB80003F8)
#define UART_LSR (*(volatile char *) 0XB80003FD)

typedef struct {
  unsigned char buffer[256];
  unsigned char head;
  unsigned char tail;
} Buffer;

void init_buffer(volatile Buffer *);
void write_to_buffer(volatile Buffer *, unsigned char);
unsigned char read_from_buffer(volatile Buffer *);

void print_char(char);
char read_char(void);

#endif
