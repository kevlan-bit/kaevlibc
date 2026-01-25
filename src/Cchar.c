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
