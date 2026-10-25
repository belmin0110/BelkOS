#include "memory.h"
#include "string.h"
#include "../kernel/tty.h"

unsigned int peek(unsigned int addr) {
  return *(volatile unsigned int *) addr;
}

void poke(unsigned int addr, unsigned int val) {
  *(volatile unsigned int *) addr = val;
}

void hexdump(unsigned int addr, int size) {
  unsigned char *ptr = (unsigned char *) addr;
  char hex[9];

  for(int i = 0; i < size; i++) {
    byte_to_hex(ptr[i], hex);
    print_string(hex);
    print_string(" ");
  }
}
