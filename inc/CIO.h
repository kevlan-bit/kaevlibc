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
#ifndef CIO_H
#define CIO_H
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define EOF 0
#include "Cdef.h"

int print(const char *s);
int printf(const char *s, ...);
char *utoa(unsigned int value, char *buf, int base);
char *itoa(int value, char *buf, int base);
int input(char *s, size_t size);

#endif
