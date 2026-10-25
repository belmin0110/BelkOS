#include "string.h"

int str_comp(char *s1, char *s2) {
  while(*s1 != '\0' && *s2 != '\0') {
    if(*s1 > *s2) {
      return 1;
    }
    else if(*s1 < *s2) {
      return -1;
    }

    s1++;
    s2++;
  }

  if(*s1 != '\0' && *s2 == '\0') {
    return 1;
  }
  else if(*s1 == '\0' && *s2 != '\0') {
    return -1;
  }

  return 0;
}

void normalize_whitespace(char *s) {
  char *r = s;
  char *w = s;
  int space = 0;

  while(*r != '\0' && *r == ' ') {
    r++;
  }

  while(*r != '\0') {
    if(*r == ' ') {
      if(!space) {
        *w = ' ';
        w++;
        space = 1;
      } 
    }
    else {
      *w = *r;
      w++;
      space = 0;
    }

    r++;
  }

  if(w > s && *(w-1) == ' ') {
    w--;
  }

  *w = '\0';
}

char *str_split(char *s) {
  while(*s != ' ' && *s != '\0') {
    s++;
  }

  if(*s == ' ') {
    *s = '\0';
    return s + 1;
  }

  return (char *) 0;
}

void to_hex(unsigned int num, char *b) {
  b[8] = '\0';

  for(int i = 7; i >= 0; i--) {
    int rem = num & 0x000F;

    if(rem >= 0 && rem <= 9) {
      b[i] = rem + '0';
    }
    else if(rem >= 10 && rem <= 15){
      b[i] = rem + '7';
    }

    num >>= 4;
  }
}

void byte_to_hex(unsigned char num, char *b) {
  const char chars[] = "0123456789ABCDEF";
  b[0] = chars[(num >> 4) & 0x0F];
  b[1] = chars[num & 0x0F];
  b[2] = '\0';
}

unsigned int str_to_hex(char *s) {
  unsigned int sum = 0;
  
  if(*s == '0' && *(s+1) == 'x') {
    s += 2;
  }

  while(*s != '\0') {
    char c = *s;

    if(c >= '0' && c <= '9') {
      sum = (sum << 4) | (c - '0');
    }
    else if(c >= 'A' && c <= 'F') {
      sum = (sum << 4) | (c - '7');
    }
    else if(c >= 'a' && c <= 'f') {
      sum = (sum << 4) | (c - 'W');
    }

    s++;
  }

  return sum;
}
