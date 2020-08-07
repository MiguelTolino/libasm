
global	ft_strcmp

section .text

	ft_strcmp:
				mov	rax, 0				; initialize rax (return variable)
				mov	rcx, 0				; initialize rcx (counter)
				mov rdx, 0				;initialize	rdx (aux)

				cmp rdi, 0				;s1 == NULL?
				jz exit					;return
				cmp rsi, 0				;s2 == NULL?
				jz exit					;return
	compare:
				mov al, BYTE[rdi + rcx]	;al = s1[i]
				mov dl, BYTE[rsi + rcx]	;dl = s2[i]
				cmp al, dl				;s1[i] == s2[i] ??
				jne calculate			;If not, jump to calculate difference
				cmp al, 0				;s1[i] == '\0
				jz	equal				;If so, end of strings
				inc rcx					;i++
				jmp compare				;loop

	calculate:	sub rax, rdx			;s1[i] - s2[i]. Calculate the difference
				jmp exit				;return


	equal:		cmp dl, 0				;Is s2[i] == '\0'
				jnz	calculate			;If not, go on
				mov rax, 0				;If so, rax = 0

	exit:		ret						;return to the program