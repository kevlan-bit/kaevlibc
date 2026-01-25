#ifndef CIO_H
#define CIO_H

int print(const char *s);
int printf(const char *s, ...);
char *utoa(unsigned int value, char *buf, int base);
char *itoa(int value, char *buf, int base);

#endif
