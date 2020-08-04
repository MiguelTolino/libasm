/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/08/04 12:28:21 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *s);
char *ft_strcpy(char *s2, char *s1);
int	ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *s);

int main(void)
{
	int len;
	char *str1;
	char *str2;

	str1 = "HOLA2";
	str2 = "HOLA2";

	len = ft_strlen(str1);
	printf("%i\n", len);
	printf("STRCOMPARE: %i\n", ft_strcmp(str1, str2));
	printf("STRDUP : %s", ft_strdup("HOLA"));
//	printf("%s\n", ft_strcpy(str2, str1));
}
