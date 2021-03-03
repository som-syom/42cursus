section .text
    global _ft_strdup
    extern _ft_strlen
    extern _ft_strcpy
    extern _malloc

_ft_strdup : ; str
    push    r15
    mov     r15, rdi
    call    _ft_strlen
    mov     rcx, rax ; rcx = ft_strlen(str);
    inc     rcx
    mov     rdi, rcx 
    call    _malloc ;rax = malloc(0x100);
    and     rax, rax
    je      malloc_failed
    mov     rsi, r15
    mov     rdi ,rax 
    call    _ft_strcpy ; strcpy(dst, src)
    pop     r15
    ret

malloc_failed :
    mov     rax, 0
    pop     r15
    ret