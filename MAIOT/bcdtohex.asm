%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	msg1 db "Enter decimal number: ",10
	msg1len equ $-msg1
	msg2 db "The hexadecimal equvalent is:",10
	msg2len equ $-msg2
	newline db 10
	
	result dw 0

section .bss
	num resb 6
	hex resb 5
	temp1 resb 1
	
section .text
	global _start
		_start:
			
			disp 1,1,msg1,msg1len
			disp 0,0,num,6
			
			mov rsi,num
			mov cx,0Ah
			
			up:
			mov bx,0h
			mov ax,word[result]
			mov bl,byte[rsi]
			cmp bl,0Ah
			jz print
			sub bl,30h
			mul cx
			add ax,bx
			mov word[result],ax
			inc rsi 
			jmp up
			
			print:
			mov bp,4
			mov bx,0h
			mov ax,word[result]
			up1:
			rol ax,4
			mov bx,ax
			and ax,0Fh
			cmp ax,09h
			jbe down2
			add ax,07h

			down2:
			add ax,30h
			mov byte[temp1],al
			disp 1,1,temp1,1
			mov ax,bx
			dec bp
			jnz up1

			disp 1,1,newline,1
			disp 60,0,0,0
