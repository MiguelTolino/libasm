section .text
extern __errno_location

global ft_read

ft_read:	mov rax, 0	;Depends on OS, raw would have one value or another, in this case we are using Ubuntu 64bits
			syscall		;We call to the system for I/O signal
			cmp rax, 0
            jc	error   ; error sets carry flag, rax = errno
            ret
error:
            mov         rdi, rax            ; save errno
            call        __errno_location    ; retrieve address to errno
            mov         rax, -1
            ret