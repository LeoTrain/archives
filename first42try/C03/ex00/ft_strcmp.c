/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:13:35 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 08:13:48 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
		if (s1[index] < s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	//test 1
	char s1[] = "Hello";
	char s2[] = "World";
	printf("%d\n", strcmp(s1, s2));

	char ft_s1[] = "Hello";
	char ft_s2[] = "World";
	printf("%d\n", ft_strcmp(ft_s1, ft_s2));

	//test 3
	char s3[] = "Hello";
	char s4[] = "Hellm";
	printf("%d\n", strcmp(s3, s4));

	char ft_s3[] = "Hello";
	char ft_s4[] = "Hellm";
	printf("%d\n", ft_strcmp(ft_s3, ft_s4));

	//test 3
	char s5[] = " ";
	char s6[] = "Hellm";
	printf("%d\n", strcmp(s5, s6));

	char ft_s5[] = " ";
	char ft_s6[] = "Hellm";
	printf("%d\n", ft_strcmp(ft_s5, ft_s6));
}
*/