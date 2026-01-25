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
	mov %rcx, %r10
	mov $9, %rax
    syscall
    ret

.global sys_munmap
sys_munmap:
	mov $11, %rax
	syscall
	ret

.section .note.GNU-stack,"",@progbits
