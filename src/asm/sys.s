# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2026 kevlan-bit
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

.section .text
.global sys_write
sys_write:
	mov $1, %rax
	syscall
	ret

.global sys_exit
sys_exit:
	mov $60, %rax
	syscall
	hlt

.global sys_mmap
sys_mmap:
	mov $9, %rax
	mov %rcx, %r10
    syscall
    ret

.global sys_munmap
sys_munmap:
	mov $11, %rax
	syscall
	ret

.global sys_read
sys_read:
	mov $0, %rax
	syscall
	ret

.section .note.GNU-stack,"",@progbits
