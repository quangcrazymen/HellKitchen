.DATA

msgCaption  DB "Message box text",0

.CODE
ALIGN 16

EXTERN GetMsgBoxType : PROC
; EXTERN MessageBoxA : PROC
EXTERN __imp_MessageBoxA : qword


asm_func PROC
	; RCX = address for the string for the message box
	sub		rsp, 28h		; shadow stack
	mov		[rsp], rcx

	call	GetMsgBoxType

	mov		r9, rax
	mov		r8, [rsp]
	lea		rdx, [msgCaption]
	xor		ecx, ecx

	call	[__imp_MessageBoxA]

	add		rsp, 28h		; restoring shadow stack
	add		r8, 10
	add		r8, r9
	ret
asm_func ENDP

END