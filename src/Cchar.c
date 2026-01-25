#include "../inc/Cchar.h"
#include "../inc/Cdef.h"

size_t charlen(const char *s) {
	size_t l = 0;
	while (s[l]) l++;
	return l;
}

int charncmp(const char *s1, const char *s2, unsigned int n) {
	for (size_t i = 0;i < n;i++) {
		unsigned char c1 = s1[i];
		unsigned char c2 = s2[i];
		if (c1 != c2) return c1 - c2;
		if (c1 == '\0') return 0;
	}
	return 0;
}

int charcmp(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

char *charcpy(char *dest, const char *src) {
	char *d = dest;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return d;
}
