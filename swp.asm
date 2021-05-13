%include "io.inc"

section .data
	const1 dq 3.0
	const2 dq 2.0

extern printf
section .rodata
    line db "%lf", 0x0
section .data
    num dq 0.3    ; input number
section .text
global CMAIN
val_f3:
f1:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp


 	pop ebp
 	ret


CMAIN:
    push dword[num+4]
    push dword[num]
    call val_f3  ;your func
    add esp, 8
    
    sub esp, 12
    mov dword[esp], line
    fstp qword[esp+4]
    call printf
    add esp, 12
    
    xor eax, eax
    ret
