/*
SPDX-License-Identifier: GPL-3.0-or-later
Copyright (C) 2026 kevlan-bit
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdarg.h>
#include "../inc/CIO.h"
#include "../inc/sys.h"
#include "../inc/Cchar.h"
#include "../inc/Cmemory.h"

memory_block_t fopen(const char *filename, int flags) {
	memory_block_t b;
	allocmem(sizeof(file_t), &b);
	((file_t*)b.ptr)->fd = sys_open(filename, flags, 0644);
	return b;
}

void fwrite(memory_block_t *b, const char* buf, size_t count) {
	sys_write(((file_t*)b->ptr)->fd, buf, count);
}

void fread(memory_block_t *b, const char* s, size_t count) {
	sys_read(((file_t*)b->ptr)->fd, (char*)s, count);
}

void fclose(memory_block_t *b) {
	if (b == NULL) return;
	sys_close(((file_t*)b->ptr)->fd);
	freemem(b);
}

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

int input(char* s, size_t size) {
	memset(s, 0, size);
	ssize_t b = sys_read(STDIN, s, size);
	if (b < 0) return 0;
	if (s[b-1] == '\n') s[b-1] = '\0';
	return 1;
}
