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
#include "../inc/CIO.h"
#include "../inc/Cchar.h"

int main(int argc, char** argv) {
	memory_block_t b1;
	allocmem(1024, &b1);
	memory_block_t b = fopen("teste.txt", O_RDWR | O_CREAT);
	fread(&b, b1.ptr, sizeof(b1.ptr));
	fclose(&b);
	print(b1.ptr);
	freemem(&b1);
	return 0;
}
