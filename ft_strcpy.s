section .text

global ft_strcpy

	ft_strcpy:	cmp rsi, 0
				jz	return
				xor rcx, rcx
				xor rdx, rdx

		copy:	mov dl, BYTE [rsi + rcx]
				mov BYTE [rdi + rcx], dl
				cmp al, 0
				jz	return
				inc	rcx
				jmp	copy

		return:	mov rax, rdi
				ret