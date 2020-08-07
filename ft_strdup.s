global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
    ft_strdup:  xor rax, rax    ;Clean rax
                cmp rdi, 0      ;Check if s == NULL
                jz return       ;Return Null
                call ft_strlen  ;ft_strlen(s)
                push rdi        ;Save s on stack
                mov rdi, rax    ;Move len for using in malloc
                inc rdi         ;i++
                call malloc     ;Allocate memory on the heap
                pop rdi         ;Restore 's'
                mov rsi, rdi    ;Move dst to the second parameter
                mov rdi, rax    ;Move src to the first parameter
                call ft_strcpy  ;copy the string
    return:     ret             ;return