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
#include "../inc/Cmemory.h"
#include "../inc/Cdef.h"
#include "../inc/sys.h"
#include "../inc/Cerror.h"

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

int allocmem(size_t size, memory_block_t *block) {
	void *addr = sys_mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (addr == MMAP_FAIL) {
		block->size = 0;
		block->ptr = NULL;
		gerror("allocmem: memory allocation error");
		return 0;
	}

	block->ptr = addr;
	block->size = size;
	return 1;
}

void freemem(memory_block_t *block) {
	// void *base = (char*)ptr-sizeof(size_t);
	// size_t allocsize = *(size_t*)base;
	if (block->ptr != NULL) {
		sys_munmap(block->ptr, block->size);
		block->ptr = NULL;
		block->size = 0;
	}
}
