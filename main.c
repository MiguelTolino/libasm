/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/08/05 14:03:12 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

ssize_t	ft_strlen(char *s);
char	*ft_strcpy(char *s2, char *s1);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);

/* void	test_strlen()
{
	char *str;
	int i;

	str = "";
	i = 0;

	while (i < 1000)
	{
		ft_strlen(str);
		strlen(str)
		str
		*str++;
	}

	ft_strlen("")




}
 */




int main(void)
{
	int len;
	char *str1;
	char *str2;

	str1 = "HOLA2";
	str2 = "HOLA1";


	len = ft_strlen(str1);
	printf("%i\n", len);
	printf("STRCOMPARE: %i\n", ft_strcmp(str1, str2));
	printf("STRDUP : %s", ft_strdup("HOLA"));
	printf("%s\n", ft_strcpy(str2, str1));
}
