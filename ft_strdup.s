section .text

global ft_strdup
extern	ft_strlen
extern 	malloc

	ft_strdup:
				xor rdx, rdx
				xor rax, rax
				cmp rdi, 0
				je	return
				mov rcx, 0
				call ft_strlen
				push	rdi
				mov	rdi, rax
				add rdi, 1
				call malloc
				pop rdi
	fill:
				mov dl, BYTE [rdi + rcx]
				mov BYTE [rax + rcx], dl
				cmp dl, 0
				je	return
				inc	rcx
				jmp fill

	return:		ret