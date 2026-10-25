#include "../drivers/uart.h"
#include "tty.h"

void print_string(char *s) {
  while(*s != '\0') {
    print_char(*s);
    s++;
  }
}

void read_string(char *b, int max_size) {
  int length = 0;
  int cursor = 0;
  int esc_count = 0;

  while(1) {
    char c = read_char();

    if(c == '\r') {
      print_char('\r');
      print_char('\n');
      b[length] = '\0';

      return;
    }
    else if(c == '\b' || c == '\x7F') {
      if(cursor > 0) {
        if(cursor < length) {
          for(int i = cursor; i < length; i++) {
            b[i-1] = b[i];
          }

          length--;
          cursor--;

          print_char('\b');

          for(int i = cursor; i < length; i++) {
            print_char(b[i]);
          }

          print_char(' ');
          print_char('\b');

          int dist = length - cursor;

          for(int i = 0; i < dist; i++) {
            print_char('\b');
          }
        }
        else {
          print_char('\b');
          print_char(' ');
          print_char('\b');

          length--;
          cursor--;
        }
      }
    }
    else {
      if(esc_count == 0) {
        if(c == '\x1b') {
          esc_count = 1;
        }
        else {
          if(length < max_size - 1) {
            if(cursor < length) {
              for(int i = length; i > cursor; i--) {
                b[i] = b[i-1];
              }

              b[cursor] = c;

              length++;
              cursor++; 

              for(int i = cursor - 1; i < length; i++) {
                print_char(b[i]);
              }
 
              int dist = length - cursor;

              for(int i = 0; i < dist; i++) {
                print_char('\b');
              }
            }
            else {
              b[cursor] = c;
              print_char(c);

              length++;
              cursor++;
            }
          }
        }
      }
      else if(esc_count == 1) {
        if(c == '[') {
          esc_count = 2;
        }
        else {
          esc_count = 0;
        }
      }
      else {
        if(c == 'A' || c == 'B') {}
        else if(c == 'C') {
          if(cursor < length) {
            print_string("\x1b[C");
            cursor++;
          }
        }
        else if(c == 'D') {
          if(cursor > 0) {
            print_char('\b');
            cursor--;
          }
        }

        esc_count = 0;
      }
    }
  }
}
