#include "uart.h"

void init_buffer(volatile Buffer *b) {
  b->head = 0;
  b->tail = 0;
}

void write_to_buffer(volatile Buffer *b, unsigned char c) {
  if((unsigned char) (b->tail - b->head) == 255) {
    return;
  }
  
  b->buffer[b->tail++] = c;
}

unsigned char read_from_buffer(volatile Buffer *b) {
  if(b->head == b->tail) {
    return '\0';
  }

  return b->buffer[b->head++];
}

void print_char(char c) {
  while(!(UART_LSR & 0x20)) {}
  UART_TDR = c;
}

char read_char(void) {
  while(!(UART_LSR & 0x01)) {}
  return UART_TDR;
}
