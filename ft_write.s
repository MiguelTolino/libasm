section .text
extern __errno_location

global ft_write

ft_write:	mov rax, 1	;Depends on OS, raw would have one value or another, in this case we are using Ubuntu 64bits
			syscall		;We call to the system for I/O signal
			cmp rax, 0
			jl  error   ; error sets carry flag, rax = errno
			ret
error:
			mov rdi, rax                        ; save errno
			call    __errno_location            ; retrieve address to errno
			mov rax, -1
			ret