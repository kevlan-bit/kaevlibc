#ifndef CCHAR_H
#define CCHAR_H
#include "Cdef.h"

size_t charlen(const char *s);
int charncmp(const char *s1, const char *s2, unsigned int n);
int charcmp(const char *s1, const char *s2);
char *charcpy(char *dest, const char *src);

#endif
