# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 19:39:26 by mmateo-t          #+#    #+#              #
#    Updated: 2020/08/04 14:01:53 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libasm.a
SRCS:= $(wildcard *.s)
OBJS = ${SRCS:.s=.o}
CC:= gcc
ASM:= nasm -felf64

all: $(NAME)

assembly:
		$(ASM) ft_strlen.s
		$(ASM) ft_strcpy.s
		$(ASM) ft_read.s
		$(ASM) ft_write.s
		$(ASM) ft_strcmp.s
		$(ASM) ft_strdup.s

${NAME}:    assembly
			ar rc ${NAME} ${OBJS}

test:
		$(CC) main.c $(NAME) -o test

clean:
		rm -i $(OBJS)

fclean: clean
		rm $(NAME) test

re:	fclean all


.PHONY: all clean fclean re
