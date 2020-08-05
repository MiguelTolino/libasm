section .text

global ft_strcmp

	ft_strcmp:	xor rcx, rcx				;Clean RCX (i)
				xor rax, rax				;Clean RAX
				xor rdx, rdx				;Clean RDX (aux)
				cmp rdi, 0					;If s1 == NULL
				jz exit						;Exit
				cmp rsi, 0					;If s2 == NULL
				jz exit						;Exit

	compare:
				mov al, BYTE[rdi + rcx]		;Move s1[i] to dl
				mov dl, BYTE[rsi + rcx]		;Move s2[i] to dh
				cmp al, 0
				jz	greater
				cmp	dl, 0
				jz	greater
				cmp al, dl					;If s1[i] == NULL
				jg	greater
				jl	less				;Jump to calculate
				inc rcx						;i++
				jmp compare					;Loop

	less:		neg rax
				neg al

	greater:	sub al, dl
	exit:		ret
