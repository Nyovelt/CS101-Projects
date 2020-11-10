
main:
.LFB23:
	.cfi_startproc
	endbr64
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	sub	rsp, 16
	.cfi_def_cfa_offset 32
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 8[rsp], rax
	xor	eax, eax
	mov	DWORD PTR [rsp], 1
	mov	DWORD PTR 4[rsp], 2
	mov	ebx, 0
	jmp	.L2
.L3:
	movsx	rax, ebx
	movsx	edx, BYTE PTR [rsp+rax]
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	add	ebx, 1
.L2:
	cmp	ebx, 7
	jle	.L3
	mov	rax, QWORD PTR 8[rsp]
	sub	rax, QWORD PTR fs:40
	jne	.L6
	mov	eax, 0
	add	rsp, 16
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc


