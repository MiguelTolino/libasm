section .text

global ft_strlen

	ft_strlen:	mov rcx, 0					;Clean RCX (i)
				cmp rdi, 0					;s == NULL ???
				jz	return					;If so, return

		length:	cmp	BYTE [rdi + rcx], 0		;s[i] == NULL??
				jz	return					;If so, return
				inc	rcx						;i++
				jmp	length					;Loop

		return:	mov rax, rcx				;Move i to rax
				ret							;Finish
