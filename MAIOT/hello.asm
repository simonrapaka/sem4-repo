%macro disp 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .data
    newline db 10

section .bss
    temp resb 1

section .text
    global _start

_start:
    mov ax,1234h
    mov bp,4
    up:
        rol ax,4
        mov bx,ax
        and ax,0Fh
        cmp ax,09
        jbe down
        add ax,07h
        down:
            add ax,30h
        mov byte[temp],al
        disp 1,1,temp,1
        mov ax,bx
        dec bp
        jnz up
    disp 1,1,newline,1
    disp 60,0,0,0