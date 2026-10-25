#ifndef STRING_H
#define STRING_H

int str_comp(char *, char *);
void normalize_whitespace(char *);
char *str_split(char *);

void to_hex(unsigned int, char *);
void byte_to_hex(unsigned char, char *);
unsigned int str_to_hex(char *);

#endif
