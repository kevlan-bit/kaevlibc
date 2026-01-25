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
ssize_t sys_write(int fd, const void *buf, size_t count);
void *sys_mmap(void* addr, size_t length, int prot, int flags, int fd, long long offset);
__attribute__((noreturn))
void sys_munmap(void *addr, size_t size);
ssize_t sys_read(int fd, void *buf, size_t count);
int sys_open(const char *filename, int flags, int mode);
__attribute__((noreturn))
void sys_close(unsigned int fd);

#endif
