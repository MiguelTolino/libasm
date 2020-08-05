section .text

global ft_strcmp

	ft_strcmp:	xor rcx, rcx				;Clean RCX (i)
				xor rax, rax				;Clean RAX
				xor rdx, rdx				;Clean RDX (aux)
				cmp rdi, 0					;If s1 == NULL
				jz exit						;Exit
				cmp rsi, 0					;If s2 == NULL
				jz exit						;Exit

	compare:	mov dl, BYTE[rdi + rcx]		;Move s1[i] to dl
				mov dh, BYTE[rsi + rcx]		;Move s2[i] to dh
				cmp dl, 0					;If s1[i] == NULL
				je	calculate				;Jump to calculate
				cmp dh, 0					;If s2[i] == NULL
				je	calculate				;Jump to calculate
				inc rcx						;i++
				jmp compare					;Loop

	calculate:	sub dl, dh					;If exist different value, s1[i] - s2[i]

	exit:		movsx rax, dl				;Move to raw with sign
				ret							;Return control to main function
