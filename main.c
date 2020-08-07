/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/08/07 18:55:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


void clean_buffer(char buff[100])
{
	int i;

	i = 0;
	while (i <  100)
	{
		buff[i++] = 0;
	}
}

int test_ft_write()
{
	int fd;
	char buff[100];
	int count;
	char c;
	int n_bytes[2];

	clean_buffer(buff);
	fd = 1;
	count = 0;
	c = 50;
	while (count < 20)
	{
		TEST(count, 20);
		buff[count++] = c++;
		write(fd, "ft_write: ", 11);
		n_bytes[0] = ft_write(fd, buff, count);
		printf("\n");
		write(fd, "write:    ", 11);
		n_bytes[1] = write(fd, buff, count);
		printf("\n\n");
		assert(n_bytes[0] == n_bytes[1]);
	}
	return (1);
}

int test_ft_read()
{
	int fd[2];
	char buff[100];
	int count;
	char c;
	int n_bytes[2];

	clean_buffer(buff);
	fd[0] = open("Makefile", O_RDONLY);
	fd[1] = open("Makefile", O_RDONLY);

	count = 0;
	while (count < 20)
	{
		TEST(count, 20);
		n_bytes[0] = ft_read(fd[0], buff, count);
		printf("ft_read: %s\n", buff);
		n_bytes[1] = read(fd[1], buff, count);
		printf("read:    %s", buff);
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
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	test_ft_strlen(char buff[100])
{
	int i;
	char c;
	int a;
	int b;

	i = 0;
	c = 32;
	while (i < 50)
	{
		a = ft_strlen(buff);
		b = strlen(buff);
		buff[i] = c++;
		printf("ft_strlen: \033[0;33m%i\033[0;0m", a);
		printf(" ------ strlen: \033[0;33m%i\033[0;0m", b);
		if (a == b)
		{
			printf("\t \033[1;32m[OK]\t(%i / 50)\033[0;0m\n", (i + 1));
		}
		else
		{
			printf("\t \033[1;31m[FAIL]\t (%i / 50)\033[0;0m\n", (i + 1));
		}
		assert(a == b);
		if (c > 126)
			c = 32;
		i++;
	}
	return (1);
}

int test_ft_strcpy()
{
	char buff[100];
	char *s1;
	char *s2;
	int i;
	char c;
	int equal;

	c = 32;
	s2 = calloc(51, sizeof(char));
	s1 = calloc(51, sizeof(char));
	i = 0;
	clean_buffer(buff);
	while (i < 50)
	{
		buff[i] = c;
		s1 = strcpy(s1, buff);
		equal = strcmp(ft_strcpy(s2, buff), s1);
		if (!equal)
		{
			printf("\033[1;32mTest (%i / 50)\t[OK]\033[0;0m\n", i + 1);
			printf("SRC:       %s\n", buff);
			printf("ft_strcpy: %s\n", s2);
			printf("strcpy:    %s\n", s1);
		}
		else
		{
			printf("%sTest (%i / 50)\tft_strcpy	[FAIL]\n%s", RED, i + 1, NOCOLOR);
			printf("SRC:       %s\n", buff);
			printf("ft_strcpy: %s\n", s2);
			printf("strcpy:    %s\n", s1);
		}
		i++;
		c++;
		assert(!equal);
	}
	free(s2);
	free(s1);
	return (1);
}

int test_ft_strcmp()
{
	char s1[100];
	char s2[100];
	char c1;
	char c2;
	int i;
	int equal1;
	int equal2;

	c1 = 50;
	i = 0;
	clean_buffer(s1);
	clean_buffer(s2);
	equal1 = ft_strcmp(s1, s2);
	equal2 = strcmp(s1, s2);
	printf("EQUAL STRINGS:\n");
	while (i < 20)
	{
		s1[i] = c1;
		s2[i] = c1++;
		if (equal1 == equal2)
		{
			printf("ft_strcmp: %s%i%s", YELLOW, equal1, NOCOLOR);
			printf(" ----- strcmp: %s%i%s\t", YELLOW, equal2, NOCOLOR);
			printf("\033[1;32mTest (%i / 20)\t[OK]\033[0;0m\n", i + 1);
		}
		else
		{
			printf("ft_strcmp: %s%i%s", YELLOW, equal1, NOCOLOR);
			printf(" ----- strcmp: %s%i%s\t", YELLOW, equal1, NOCOLOR);
			printf("\033[1;31mTest (%i / 20)\t[FAIL]\033[0;0m\n", i + 1);
		}
		assert(equal1 == equal2);
		i++;
	}
	i = 0;
	clean_buffer(s1);
	clean_buffer(s2);
	printf("DIFFERENTS STRINGS:\n");
	while (i < 20)
	{
		int j = 0;
		while (j < 20)
		{
			c1 = rand() % 81 + 30;
			c2 = rand() % 81 + 30;
			s1[j] = c1;
			s2[j] = c2;
			j++;
		}
		if ((equal1 = ft_strcmp(s1, s2)) == (equal2 = strcmp(s1, s2)))
		{
			printf("ft_strcmp:%s%3i%s", YELLOW, equal1, NOCOLOR);
			printf(" ----- strcmp:%s%3i%s\t", YELLOW, equal2, NOCOLOR);
			printf("\033[1;32mTest (%i / 20)\t[OK]\033[0;0m\n", i + 1);

		}
		else
		{
			printf("ft_strcmp:|%s| %s%3i%s", s1,YELLOW, equal1, NOCOLOR);
			printf(" ----- strcmp:|%s| %s%3i%s\t",s2, YELLOW, equal2, NOCOLOR);
			printf("\033[1;31mTest (%i / 20)\t[FAIL]\033[0;0m\n", i + 1);
		}
		assert(equal1 == equal2);
		i++;
	}
	return (1);
}

int test_ft_strdup()
{
	int i;
	int j;
	char *s1;
	char *s2;
	char c;

	i = 0;
	j = 0;
	s1 = calloc(30, sizeof(char));
	while (i < 20)
	{
		TEST(i, 20);
		c = rand() % 81 + 30;
		s1[i] = c;
		s2 = ft_strdup(s1);
		printf("ft_strdup: %s\n", s2);
		printf("strdup:    %s\t", s1);
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
	}


}

int main(void)
{
	char buff[100];

	clean_buffer(buff);
	if (test_ft_strlen(buff))
		printf("\033[1;32mFT_STRLEN [OK]\033[0;0m\n\n");
	if (test_ft_strcpy())
	{
		printf("\033[1;32mFT_STRCPY [OK]\033[0;0m\n\n");
	}
 	if (test_ft_strcmp())
	{
		printf("\033[1;32mFT_STRCMP [OK]\033[0;0m\n\n");
	}
	if (test_ft_strdup())
	{
		printf("\033[1;32mFT_STRDUP [OK]\033[0;0m\n\n");
	}
	test_ft_write();
	test_ft_read();

	char *s1 = "HOLA";
	char *s2;

	s2 = ft_strdup(s1);
	printf("%s", s2);

}
