/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/08/17 12:41:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	clean_buffer(char buff[50])
{
	int i;

	i = 0;
	while (i < 50)
		buff[i++] = 0;
}

int		test_ft_write(void)
{
	char	buff[50];
	int		count;
	char	c;
	int		n_bytes[2];

	clean_buffer(buff);
	count = 0;
	c = 50;
	while (count < 7)
	{
		TEST(count, 7);
		write(1, "\n", 1);
		buff[count++] = c++;
		write(1, "ft_write: ", 11);
		n_bytes[0] = ft_write(1, buff, count);
		write(1, "\n", 1);
		write(1, "write:    ", 11);
		n_bytes[1] = write(1, buff, count);
		if (n_bytes[0] == n_bytes[1])
		{
			OK;
		}
		else
		{
			FAIL;
			assert(1);
		}
	}
	printf("\n\n");
	return (1);
}

int			test_ft_read(void)
{
	int		fd[2];
	char	buff[50];
	int		count;
	int		n_bytes[2];

	clean_buffer(buff);
	fd[0] = open("Makefile", O_RDONLY);
	fd[1] = open("Makefile", O_RDONLY);
	count = 0;
	while (count < 7)
	{
		n_bytes[0] = ft_read(fd[0], buff, count);
		printf("ft_read: %s (%i)", buff, n_bytes[0]);
		TEST(count, 7);
		printf("\n");
		n_bytes[1] = read(fd[1], buff, count);
		printf("read:    %s\t (%i)", buff, n_bytes[1]);
		if (n_bytes[0] == n_bytes[1])
		{
			OK;
		}
		else
		{
			FAIL;
			assert(n_bytes[0] == n_bytes[1]);
		}
		count++;
		printf("\n");
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int			test_ft_strlen(void)
{
	int		i;
	char	c;
	int		a;
	int		b;
	char	buff[50];

	clean_buffer(buff);
	i = 0;
	while (i < 30)
	{
		a = ft_strlen(buff);
		b = strlen(buff);
		c = rand() % 80 + 30;
		buff[i] = c;
		printf("ft_strlen: \033[0;33m%i\033[0;0m", a);
		printf(" ------ strlen: \033[0;33m%i\033[0;0m", b);
		if (a == b)
		{
			TEST(i, 30);
			OK;
		}
		else
		{
			printf("\t \033[1;31m[FAIL]\t\033[0;0m\n");
			assert(1);
		}
		i++;
	}
	return (1);
}

int			test_ft_strcpy(void)
{
	char	buff[50];
	char	*s1;
	char	*s2;
	int		i;
	int		equal;

	s2 = calloc(31, sizeof(char));
	s1 = calloc(31, sizeof(char));
	i = 0;
	clean_buffer(buff);
	while (i < 20)
	{
		s1 = strcpy(s1, buff);
		equal = strcmp(ft_strcpy(s2, buff), s1);
		printf("ft_strcpy: %s\n", s2);
		printf("strcpy:    %s", s1);
		buff[i] = rand() % 81 + 30;
		if (!equal)
		{
			TEST(i, 20);
			OK;
			printf("\n");
		}
		else
		{
			FAIL;
			assert(1);
		}
		i++;
	}
	free(s2);
	free(s1);
	return (1);
}

int			test_ft_strcmp(void)
{
	char	s1[50];
	char	s2[50];
	int		i;
	int		j;
	int		equal1;
	int		equal2;

	i = 0;
	clean_buffer(s1);
	clean_buffer(s2);
	equal1 = ft_strcmp(s1, s2);
	equal2 = strcmp(s1, s2);
	printf("EQUAL STRINGS:\n");
	while (i < 20)
	{
		s1[i] = rand() % 81 + 30;
		s2[i] = s1[i]++;
		printf("ft_strcmp: %s%i%s", YELLOW, equal1, NOCOLOR);
		printf(" ----- strcmp: %s%i%s\t", YELLOW, equal2, NOCOLOR);
		if (equal1 == equal2)
		{
			TEST(i, 20);
			OK;
		}
		else
		{
			FAIL;
			assert(equal1 == equal2);
		}
		i++;
	}
	i = 0;
	clean_buffer(s1);
	clean_buffer(s2);
	printf("DIFFERENTS STRINGS:\n");
	while (i < 20)
	{
		j = 0;
		while (j < 10)
		{
			s1[j] = rand() % 81 + 35;
			s2[j] = rand() % 81 + 35;
			j++;
		}
		equal1 = ft_strcmp(s1, s2);
		equal2 = strcmp(s1, s2);
		printf("ft_strcmp: %s%3i%s", YELLOW, equal1, NOCOLOR);
		printf(" ----- strcmp: %s%3i%s", YELLOW, equal2, NOCOLOR);
		if (equal1 == equal2)
		{
			TEST(i, 20);
			OK;
		}
		else
		{
			FAIL;
		}
		i++;
	}
	return (1);
}

int			test_ft_strdup(void)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = calloc(30, sizeof(char));
	s2 = ft_strdup(s1);
	while (i < 20)
	{
		s1[i] = rand() % 81 + 30;
		s2 = ft_strdup(s1);
		printf("\nft_strdup: %s", s2);
		TEST(i, 20);
		printf("\nstrdup:    %s\t", s1);
		if (!strcmp(s1, s2))
		{
			OK;
		}
		else
		{
			FAIL;
			assert(1);
		}
		i++;
		free(s2);
	}
	free(s1);
	return (1);
}

int			main(void)
{
	test_ft_strlen();
	printf("\n\n");
	test_ft_strcpy();
	printf("\n\n");
	test_ft_strcmp();
	printf("\n\n");
	test_ft_strdup();
	printf("\n\n");
	test_ft_write();
	printf("\n\n");
	test_ft_read();
	printf("\n\n%sRESULTS%s", BLUE, NOCOLOR);
	printf("\n%s--------------------------------%s\n", BLUE, NOCOLOR);
	printf("\033[1;32mFT_STRLEN [OK]\033[0;0m\n");
	printf("\033[1;32mFT_STRCPY [OK]\033[0;0m\n");
	printf("\033[1;32mFT_STRCMP [OK]\033[0;0m\n");
	printf("\033[1;32mFT_STRDUP [OK]\033[0;0m\n");
	printf("\033[1;32mFT_WRITE [OK]\033[0;0m\n");
	printf("\033[1;32mFT_READ [OK]\033[0;0m\n");
	printf("%s----------------------------------%s\n", BLUE, NOCOLOR);
}
