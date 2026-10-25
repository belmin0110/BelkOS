#include "interrupts.h"
#include "../kernel/tty.h"
#include "../drivers/uart.h"

extern void clear_stack(void);

volatile Buffer buffer;

void uart_init(void) {
  UART_IER |= 0x01;
}

void interrupt_handler(unsigned int cause, unsigned int *address) {
  unsigned int exc = (cause >> 2) & 0x001F;

  switch(exc) {
    case 0:
      init_buffer(&buffer);


      break;
    case 4:
    case 5:
      print_string("Fatal Error: Invalid or Unaligned Address\n\n");
      clear_stack();
      break;
    default:
      print_string("Fatal Error: Caught Misc Exception!\n\n");
      clear_stack();
      break;
  }
}
