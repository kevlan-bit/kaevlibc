.section .text
.global _start

_start:
	xor %rbp, %rbp
	mov %rsp, %rdi
	call __libc_start
	hlt

.section .note.GNU-stack,"",@progbits
