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
#include "../inc/sys.h"

char **__environ;

__attribute__((noreturn))
void __libc_start(void *stack) {
	unsigned long *sp = (unsigned long*)stack;
	int argc = *sp++;
	char **argv = (char**)sp;
	sp += argc+1;
	char **envp = (char**)sp;
	__environ = envp;
	while (*sp) sp++;
	sp++;
	while (sp[0]) {
		unsigned long type = sp[0];
		unsigned long value = sp[1];
		sp += 2;
	}
	extern int main(int, char**, char**);
	sys_exit(main(argc, argv, envp));
}
