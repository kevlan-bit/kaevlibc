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
#include <Cmemory.h>
#include <Cdef.h>
#include <sys.h>
#include <Cerror.h>

void *memcpy(void *dest, const void *src, size_t n) {
	unsigned char *d = dest;
	const unsigned char *s = src;
	for (size_t i = 0;i < n;i++) d[i] = s[i];
	return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
	unsigned char *d = dest;
	const unsigned char *s = src;
	if (d < s) {
		for (size_t i = 0;i < n;i++) d[i] = s[i];
	} else {
		for (size_t i = 0;i > 0;i--) d[i-1] = s[i-1];
	}
	return dest;
}

void *memset(void *dest, int value, size_t n) {
	unsigned char *p = dest;
	unsigned char val = (unsigned char)value;
	for (size_t i = 0;i < n;i++) {
		p[i] = val;
	}
	return dest;
}

MPointer allocmem(size_t size) {
	MPointer mp;
	mp.ptr = sys_mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (mp.ptr == MMAP_FAIL) {
		mp.ptr = NULL;
		mp.size = 0;
	}
	else {
		mp.size = size;
	}
	mp.free = 1;
	return mp;
}

void freemem(MPointer *mptr) {
	if (mptr->free != 0) return;
	sys_munmap(mptr->ptr, mptr->size);
}
