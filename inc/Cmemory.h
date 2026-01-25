#ifndef CMEMORY_H
#define CMEMORY_H
#define PAGE_SIZE 4096
#include "Cdef.h"

typedef struct {
	void *ptr;
	size_t size;
} memory_block_t;

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int allocmem(size_t size, memory_block_t* block);
void freemem(memory_block_t* block);

#endif
