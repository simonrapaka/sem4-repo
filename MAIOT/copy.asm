%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	msg1 db "Copy Successfull!",10
	msg1len equ $-msg1
	msg2 db "Error",10
	msg2len equ $-msg2

section .bss
	fname1 resb 15
	fd1 resq 1
	fname2 resb 15
	fd2 resq 1
	buff resb 512
	bufflen resq 1

section .text
	global _start
	
	_start:	pop r8
			cmp r8,3
			jne err
			pop r8
			pop r8
			mov rsi,fname1

	loop:	mov al,[r8]
			cmp al,00
			je next
			mov [rsi],al
			inc r8
			inc rsi
			jmp loop

	next:	pop r8
			mov rsi,fname2

	loop2:	mov al,[r8]
			cmp al,00
			je next2
			mov [rsi],al
			inc r8
			inc rsi
			jmp loop2

	next2:	disp 2,fname1,000000q,0777q
			mov [fd1],rax
			disp 0,[fd1],buff,512
			mov [bufflen],rax

			disp 85,fname2,0777q,0
			disp 2,fname2,2,0777q
			mov [fd2],rax

			disp 1,[fd2],buff,[bufflen]

			disp 3,[fd2],0,0
			disp 3,[fd1],0,0
			disp 1,1,msg1,msg1len
			jmp exit

	err:	disp 1,1,msg2,msg2len
	exit:	disp 60,0,0,0