section .text
	global _ft_strcpy

_ft_strcpy :
	xor		rcx, rcx
	jmp		loop

loop :
	mov		dl, byte[rsi + rcx]
	mov		byte[rdi + rcx], dl
	and		dl, dl
	je		exit
	inc		rcx
	jmp		loop

exit :
	mov		rax, rdi
	ret
