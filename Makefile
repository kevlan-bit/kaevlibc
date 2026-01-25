# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 kevlan-bit
#
# This Makefile is part of the [Project Name].
# This Makefile is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This Makefile is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
ASM=as
LD=ld
CC=gcc
CCFLAGS=-ffreestanding -fno-pie -nostdlib
TARGET=test
OBJS=build/crt0.o build/sys.o build/start.o build/test.o build/Cchar.o build/CIO.o build/Clib.o build/Cmemory.o build/Cerror.o

all: build/$(TARGET)

build/$(TARGET): $(OBJS)
	ld -o $@ -e _start $(OBJS)

build/%.o: src/asm/%.s
	$(ASM) -o $@ $<

build/%.o: src/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

build/%.o: tests/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf build/*
