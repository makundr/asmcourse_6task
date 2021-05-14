section .data
	const1 dq 3.0
	const2 dq 2.0

section .text

global f1
f1:
	push ebp
 	mov ebp, esp
 	fld qword [ebp + 8]
	fchs
	fldl2e
 	fmulp
 	fld1
 	fscale
	fxch
	fld1
	fxch
	fprem
	f2xm1
	faddp
	fmulp

	fld qword[const1]
	faddp

	mov esp, ebp
 	pop ebp
 	ret


global f2
f2:
	push ebp
 	mov ebp, esp
 	fld qword [ebp + 8]
 	fld qword [const2]
 	fmulp
 	fld qword [const2]
 	fsubp

 	mov esp, ebp
 	pop ebp
 	ret


global f3
f3:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp

 	mov esp, ebp
 	pop ebp
 	ret


global df1
df1:
	push ebp
 	mov ebp, esp
 	fld qword [ebp + 8]
	fchs
	fldl2e
 	fmulp
 	fld1
 	fscale
	fxch
	fld1
	fxch
	fprem
	f2xm1
	faddp
	fmulp

	fchs

	mov esp, ebp
 	pop ebp
 	ret


global df2
df2:
	push ebp
 	mov ebp, esp

 	fld qword [const2]

 	mov esp, ebp
 	pop ebp
 	ret


global df3
df3:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp
 	fld qword [ebp + 8]
 	fdivp

 	fchs

 	mov esp, ebp
 	pop ebp
 	ret


global ddf1
ddf1:
	push ebp
 	mov ebp, esp
 	fld qword [ebp + 8]
	fchs
	fldl2e
 	fmulp
 	fld1
 	fscale
	fxch
	fld1
	fxch
	fprem
	f2xm1
	faddp
	fmulp

	fchs

 	mov esp, ebp
 	pop ebp
 	ret


global ddf2
ddf2:
	push ebp
 	mov ebp, esp

 	fldz

 	mov esp, ebp
 	pop ebp
 	ret


global ddf3
ddf3:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp
 	fld qword [ebp + 8]
 	fdivp
 	fld qword [ebp + 8]
 	fdivp
 	fld qword [const2]
 	fmulp
 	fchs

 	mov esp, ebp
 	pop ebp
 	ret
