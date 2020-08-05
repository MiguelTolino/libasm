section .text

global ft_strcpy

	ft_strcpy:	cmp rsi, 0					;src == NULL??
				jz	return					;If it is, go to return
				xor rax, rax				;Clean RAX register
				xor rcx, rcx				;Clean RCX register

		copy:	mov al, BYTE [rsi + rcx]	;Move to dl, src[i]
				mov BYTE [rdi + rcx], al	;Move to dst[i], dl
				cmp al, 0					;Check if src[i] == NULL
				jz	return					;Return
				inc	rcx						;i++
				jmp	copy					;Loop

		return:	mov rax, rdi				;Point to src
				ret							;Leave function