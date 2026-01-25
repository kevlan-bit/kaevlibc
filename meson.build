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
project('kaevc', 'c')
c_src = files(
	'src/Cchar.c',
	'src/CIO.c',
	'src/start.c',
	'src/Cmemory.c',
	'src/Cerror.c',
	'src/Clib.c'
)
asm_src = files(
	'src/asm/crt0.s',
	'src/asm/sys.s'
)
ccflags = ['-m64', '-ffreestanding', '-nostdlib']

slib = static_library('kaevc', c_src, asm_src, c_args : ccflags)
subdir('tests')
