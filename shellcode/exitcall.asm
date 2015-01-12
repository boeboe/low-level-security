;exitcall.asm

[SECTION .text]

global _start

_start:
	xor ebx,ebx 	; zero out ebx, same function as mov ebx,0
	mov al, 1 		; exit command to kernel
	int 0x80
