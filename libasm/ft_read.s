section .text
    global _ft_read
    extern ___error

_ft_read :
    mov rax, 0x2000003
	syscall
	jc	err
	ret

err:
	mov r15, rax
	call	___error
	mov	[rax], r15
	or	rax, -1
	ret
