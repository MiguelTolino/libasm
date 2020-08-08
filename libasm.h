/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:28:14 by lmartin           #+#    #+#             */
/*   Updated: 2020/08/08 14:41:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>

#define NOCOLOR "\033[0;0m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define TEST(x, y)	printf("\t\033[1;33mTest (%i / %i)\033[0;0m\t", x + 1, y);
#define OK		printf("\t%s[OK]\033[0;0m\n", GREEN);
#define FAIL	printf("\t%s[FAIL]\033[0;0m\n", RED);

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

#endif