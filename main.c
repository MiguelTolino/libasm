/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/08/07 20:37:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void clean_buffer(char buff[50])
{
	int i;

	i = 0;
	while (i <  50)
	{
		buff[i++] = 0;
	}
}

int test_ft_write()
{
	int fd;
	char buff[50];
	int count;
	char c;
	int n_bytes[2];

	clean_buffer(buff);
	fd = 1;
	count = 0;
	c = 50;
	while (count < 7)
	{
		TEST(count, 7);
		write(1, "\n", 1);
		buff[count++] = c++;
		ft_write(fd, "ft_write: ", 11);
		n_bytes[0] = ft_write(fd, buff, count);
		printf("\n");
		write(fd, "write:    ", 11);
		n_bytes[1] = write(fd, buff, count);
		if (n_bytes[0] == n_bytes[1])
		{
			OK;
		}
		else
		{
			FAIL;
		}
	}
	return (1);
}

int test_ft_read()
{
	int fd[2];
	char buff[50];
	int count;
	char c;
	int n_bytes[2];

	clean_buffer(buff);
	fd[0] = open("Makefile", O_RDONLY);
	fd[1] = open("Makefile", O_RDONLY);

	count = 0;
	while (count < 7)
	{
		n_bytes[0] = ft_read(fd[0], buff, count);
		printf("ft_read: %s", buff);
		TEST(count, 7);
		printf("\n");
		n_bytes[1] = read(fd[1], buff, count);
		printf("read:    %s\t", buff);
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

int	test_ft_strlen()
{
	int i;
	char c;
	int a;
	int b;
	char buff[50];

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
		}
		i++;
	}
	return (1);
}

int test_ft_strcpy()
{
	char buff[50];
	char *s1;
	char *s2;
	int i;
	int equal;

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
		buff[i] = rand() % 81 + 30;;

		if (!equal)
		{
			TEST(i, 20);
			OK;
			printf("\n");
		}
		else
		{
			FAIL;
		}
		i++;
	}
	free(s2);
	free(s1);
	return (1);
}

int test_ft_strcmp()
{
	char s1[50];
	char s2[50];
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
		printf("ft_strcmp: %s%3i%s", YELLOW, equal1, NOCOLOR);
		printf(" ----- strcmp: %s%3i%s", YELLOW, equal2, NOCOLOR);
		if ((equal1 = ft_strcmp(s1, s2)) == (equal2 = strcmp(s1, s2)))
		{
			TEST(i, 20);
			OK;
		}
		else
		{
			FAIL;
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
	}
	return (1);
}

int main(void)
{
	if (test_ft_strlen())
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

}
