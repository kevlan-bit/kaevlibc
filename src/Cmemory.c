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
