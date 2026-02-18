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
#include <CIO.h>
#include <Cchar.h>
#include <Cdef.h>

int main(int argc, char** argv) {
	MPointer pointers[1000];
	for (size_t i = 0;i < 1000;i++) {
		pointers[i] = allocmem(64);
		if (!pointers[i].ptr) {
			printf("Fail: %d\n", i);
			return 1;
		}
	}
	for (size_t i = 0;i < 1000;i++) {
		freemem(&pointers[i]);
	}
	print("OK!");
	return 0;
}
