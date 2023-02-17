%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	arr times 10 db 0
	msg2 db "Enter the elements of array",10
	msg2len equ $-msg2
	msg1 db "Sum of elements in array: "
	msg1len equ $-msg1
	newline db 10
	
	cnt db 5
	temp1 db 0
	
section .bss
	sum resb 2
	num resb 3
	temp resb 2
	
section .data
	global _start
	_start:
		mov rbp,arr
		
		nextnum:
		disp 1,1,msg2,msg2len
		disp 0,0,num,3
		mov rcx,0
		mov rax,0
		mov rsi,num
		
		up:
		mov cl,byte[rsi]
		cmp cl,0ah
		je packed
		cmp cl,39h
		jbe down
		sub cl,07h
		
		down:
		sub cl,30h
		rol al,4
		add al,cl
		inc rsi
		jmp up
		
		packed:
		mov byte[rbp],al
		inc rbp
		dec byte[cnt]
		jnz nextnum
		
		mov rsi,arr
		mov ax,00h
		mov bx,0h
		mov cx,5
		up2:
			mov bl,byte[rsi]
			add ax,bx
			jnc skip
			inc ah
		skip:
			inc rsi
			dec cx
			jnz up2
		mov word[sum],ax
		
		disp 1,1,msg1,msg1len
		
		mov dx,word[sum]
		mov bp,4
		up1:
			rol dx,4
			mov bx,dx
			and dx,0Fh
			cmp dx,09h
			jbe down2
			add dx,07h
		down2:
			add dx,30h
			mov byte[temp1],dl
			disp 1,1,temp1,1
			mov dx,bx
			dec bp
			jnz up1
		
		disp 1,1,newline,1
		disp 60,0,0,0
