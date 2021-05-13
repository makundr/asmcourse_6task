section .data
	const1 dq 3.0
	const2 dq 2.0

section .text

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

 	pop ebp
 	ret



f2:
	push ebp
 	mov ebp, esp
 	fld qword [ebp + 8]
 	fld qword [const2]
 	fmulp
 	fld qword [const2]
 	fsubp

 	pop ebp
 	ret


f3:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp

 	pop ebp
 	ret

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

 	pop ebp
 	ret


df2:
	push ebp
 	mov ebp, esp

 	fld [const2]

 	pop ebp
 	ret

df3:
	push ebp
 	mov ebp, esp
 	fld1
 	fld qword [ebp + 8]
 	fdivp
 	fld qword [ebp + 8]
 	fdivp

 	fchs
 	pop ebp
 	ret


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

 	pop ebp
 	ret

ddf2:
	push ebp
 	mov ebp, esp

 	fldz

 	pop ebp
 	ret


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
 	fld [const2]
 	fmulp
 	fchs
 	pop ebp
 	ret
