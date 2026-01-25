#ifndef SYS_H
#define SYS_H
#define MMAP_FAIL ((void *)-1)
#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20
#define MAP_FIXED 0x10
#define MAP_SHARED 0x01
#define PROT_READ  0x01
#define PROT_WRITE 0x02
#define PROT_EXEC  0x04
#include "Cdef.h"

__attribute__((noreturn))
void sys_exit(int status);
long sys_write(int fd, const void *buf, size_t count);
void *sys_mmap(void* addr, size_t length, int prot, int flags, int fd, long long offset);
void sys_munmap(void *addr, size_t size);

#endif
