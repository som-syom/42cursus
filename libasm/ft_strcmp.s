section .text
    global _ft_strcmp

_ft_strcmp :
    xor     rcx, rcx
    jmp     loop

loop :
    mov     dl, byte[rdi + rcx]
    cmp     dl, byte[rsi + rcx]
    ja      pos
    jb      neg
    test    dl, dl
    je      equal
    inc     rcx
    jmp     loop

pos :
    sub     dl, byte[rsi + rcx]
    mov     al, dl
    ret

neg:
		jns		extend_ascii			; if sign flag = 0, extended ascii
		sub		dl, byte [rsi + rcx]	
		mov		al, dl
		movsx	rax, al
		ret

extend_ascii:
		mov		rax, 0ffffffffh
		ret

equal :
    mov rax, 0
    ret
