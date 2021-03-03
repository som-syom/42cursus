section .text
	global _ft_write
	extern __error

_ft_write:
	mov	rax, 1 ;0x2000004
	syscall
	jc	err
	ret

err:
	mov rcx, rax
	call	__error
	mov	[rax], ecx
	or	rax, -1
	ret
