section .text

global ft_strlen

	ft_strlen:	mov rcx, 0
				cmp rdi, 0
				jz	return

		length:	cmp	BYTE [rdi + rcx], 0
				jz	return
				inc	rcx
				jmp	length

		return:	mov rax, rcx
				ret
