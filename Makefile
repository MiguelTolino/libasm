# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 19:39:26 by mmateo-t          #+#    #+#              #
#    Updated: 2020/08/09 17:00:02 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libasm.a
SRCS:= $(wildcard *.s)
OBJS = ${SRCS:.s=.o}
FILE:= main.c
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
ASM:= nasm -felf64
ASM_FLAGS:= -felf64
RM:= rm -f
TEST:= test

########################################
#COLORS
MSG:= @echo
REM:= \e[0m
YELLOW:= \e[33m
RED:= \e[31m
GREEN:= \e[32m
LGREEN:= \e[92m
LCYAN:= \e[96m
MSG1:= @echo "$(YELLOW)----Assembly files----$(REM)"
########################################

all: $(NAME)

${NAME}: $(OBJS)
			ar rc ${NAME} ${OBJS}
			ranlib $(NAME)
			$(MSG) "$(GREEN) $(NAME) created $(REM)"

%.o: %.s
	@echo "\033[0;32mGenerating binary..."
	$(ASM) $<
	@echo "\033[0m"

test:	all
		$(CC) $(CFLAGS) -no-pie $(FILE) -o $(TEST) -L. -lasm
		$(MSG) "$(LCYAN)Ready to test your libasm"
		$(MSG) "$(YELLOW)-------------------------"
		$(MSG) "$(LGREEN)./test $(REM)"

clean:
		$(MSG) "$(RED)REMOVING FILES..."
		$(MSG) "$(OBJS)$(REM)"
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME) $(TEST)
		$(MSG) "$(RED) $(NAME) $(TEST)$(REM)"

re:	fclean all


.PHONY: all clean fclean re test
