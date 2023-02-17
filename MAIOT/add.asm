%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	Num_Array db 11h,12h,13h,14h,15h
	msg db "Result of array addition is "
	msglen equ $-msg
	newline db 10
	
section .bss
	result resw 1
	temp resw 2
	temp1 resb 1
	
section .text
	global _start
	_start:
		mov rsi,Num_Array
		mov ax,00h
		mov bx,0h
		mov cx,5
		up:
			mov bl,byte[rsi]
			add ax,bx
			jnc skip
			inc ah
		skip:
			inc rsi
			dec cx
			jnz up
		mov word[result],ax
		
		disp 1,1,msg,msglen
		
		mov dx,word[result]
		mov bp,4
		up1:
			rol dx,4
			mov bx,dx
			and dx,0Fh
			cmp dx,09h
			jbe down
			add dx,07h
		down:
			add dx,30h
			mov byte[temp1],dl
			disp 1,1,temp1,1
			mov dx,bx
			dec bp
			jnz up1
		
		disp 1,1,newline,1
		disp 60,0,0,0
