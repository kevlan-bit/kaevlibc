#include <stdarg.h>
#include "../inc/CIO.h"
#include "../inc/sys.h"
#include "../inc/Cchar.h"

int print(const char *s) {
	size_t len = charlen(s);
	sys_write(1, s, len);
	sys_write(1, "\n", 1);
	return 0;
}

int printf(const char *s, ...) {
	va_list ap;
	va_start(ap, s);
	char buf[64];
	for (const char *p = s;*p;p++) {
		if (*p != '%') {
			sys_write(1, p, 1);
			continue;
		}
		p++;
		if (!*p) break;
		if (*p == 's') {
			char *f = va_arg(ap, char*);
			sys_write(1, f, charlen(f));
		}
		else if (*p == 'd') {
			int v = va_arg(ap, int);
			itoa(v, buf, 10);
			sys_write(1, buf, charlen(buf));
		}
		else if (*p == 'x') {
			int v = va_arg(ap, int);
			itoa(v, buf, 16);
			sys_write(1, buf, charlen(buf));
		}
		else if (*s == '%') {
			sys_write(1, "%s", 1);
		}
	}
	va_end(ap);
	return 0;
}

char *utoa(unsigned int value, char *buf, int base) {
    char *p = buf;
    char *first = buf;
    do {
        unsigned digit = value % base;
        *p++ = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        value /= base;
    } while (value);
    *p-- = 0;
    while (first < p) {
        char tmp = *first;
        *first++ = *p;
        *p-- = tmp;
    }
    return buf;
}

char *itoa(int value, char *buf, int base) {
    if (value < 0 && base == 10) {
        *buf = '-';
        utoa(-value, buf + 1, base);
        return buf;
    }
    return utoa(value, buf, base);
}
