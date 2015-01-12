;loop.asm

[SECTION .text]

global _start

_start:

    int 0x80	; system call to the operating system (SW interrupt)
    L: jmp L	; a very short, direct infinite loop
