%macro disp 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
	arr times 10 db 0
	result times 15 db 0
	out1 times 15 db 0
	msg db "Sorted array is ",10
	msglen equ $-msg
	msg2 db "Enter element of array: "
	msg2len equ $-msg2
	msg3 db "Sorted Array: "
	msg3len equ $-msg3
	msg4 db "Entered Array: "
	msg4len equ $-msg4
	newline db 10
    count db 5
    cnt db 2
    cut db 5
section .bss
	temp1 resb 1
	num resb 3
	
section .text
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
			dec byte[cut]
			jnz nextnum
			
			mov rsi,out1
            mov dx,0
			mov rbp,arr
            mov byte[count],5
	print1:	mov dl,byte[rbp]
            mov byte[cnt],2
	up3:	rol dl,4
			mov bl,dl
			and dl,0Fh
			cmp dl,09h
			jbe down3
			add dl,07h
	down3:	add dl,30h
			mov [rsi],dl
			inc rsi
			mov dl,bl
			dec byte[cnt]
			jnz up3
			mov byte[rsi],32
			inc rsi
			inc rbp
			dec byte[count]
			jnz print1
			
			disp 1,1,newline,1
			disp 1,1,msg4,msg4len
			disp 1,1,out1,15
			disp 1,1,newline,1

        	mov bl,5      
	sort:	mov rsi,arr
			mov cl,4
	swap:	mov al,[rsi]
			cmp al,[rsi+1]
			jbe skip
			xchg al,[rsi+1]
			mov [rsi],al
	skip:	inc rsi
			dec cl
			jnz swap
			dec bl
			jnz sort

			mov rsi,result
            mov dx,0
			mov rbp,arr
            mov byte[count],5
	print:	mov dl,byte[rbp]
            mov byte[cnt],2
	up1:	rol dl,4
			mov bl,dl
			and dl,0Fh
			cmp dl,09h
			jbe down2
			add dl,07h
	down2:	add dl,30h
			mov [rsi],dl
			inc rsi
			mov dl,bl
			dec byte[cnt]
			jnz up1
			mov byte[rsi],32
			inc rsi
			inc rbp
			dec byte[count]
			jnz print

			disp 1,1,newline,1
			disp 1,1,msg3,msg3len
            disp 1,1,result,15
            disp 1,1,newline,1
			disp 60,0,0,0
