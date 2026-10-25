#include "../lib/string.h"
#include "../lib/memory.h"
#include "tty.h"

void kernel_main(void) {
  char buffer[256];
  char hex[9];
 
  while(1) {
    print_string("> ");

    read_string(buffer, 256);
    normalize_whitespace(buffer);

    char *arg0 = str_split(buffer);

    if(!str_comp(buffer, "peek")) {
      if(arg0 == 0) {
        print_string("Usage: peek <address>\n\n");
        continue;
      }

      unsigned int addr = str_to_hex(arg0);
      to_hex(peek(addr), hex);

      print_string("Value at address ");
      print_string(arg0);
      print_string(" is 0x");
      print_string(hex);
    }
    else if(!str_comp(buffer, "poke")) {
      if(arg0 == 0) {
        print_string("Usage: poke <address> <value>\n\n");
        continue;
      }

      char *arg1 = str_split(arg0);
      if(arg1 == 0) {
        print_string("Usage: poke <address> <value>\n\n");
        continue;
      }

      unsigned int addr = str_to_hex(arg0);
      unsigned int val = str_to_hex(arg1);

      poke(addr, val);

      print_string("Value 0x");
      to_hex(val, hex);
      print_string(hex);

      print_string(" written at 0x");
      to_hex(addr, hex);
      print_string(hex);
    }
    else if(!str_comp(buffer, "")) {}
    else if(!str_comp(buffer, "dump")) {
      if(arg0 == 0) {
        print_string("Usage: dump <address> [bytes]\n\n");
        continue;
      }
      
      char *arg1 = str_split(arg0);
      unsigned int addr = str_to_hex(arg0);

      if(arg1 == 0) {
        hexdump(addr, 256);
      }
      else {
        unsigned int val = str_to_hex(arg1);
        hexdump(addr, val);
      }
    }
    else {
      print_string("Unknown command: ");
      print_string(buffer);
    }

    print_string("\n\n");
  }
}
