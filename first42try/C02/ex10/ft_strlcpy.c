/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:12:48 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 00:00:30 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	destlength;
	unsigned int	index;

	index = 0;
	if (!size)
		return (0);
	while (src[index] && index < size - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	destlength = ft_strlen(dest);
	return (destlength);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	//test 1
	char src[] = "Hello";
	char dest[10];
	unsigned int ret;
	
	char ft_src[] = "Hello";
	char ft_dest[10];
	unsigned int ft_ret;

	ret = strlcpy(dest, src, 10);
	printf("dest = %s || ret = %u\n", dest, ret);
	ft_ret = ft_strlcpy(ft_dest, ft_src, 10);
	printf("ft_dest = %s || ft_ret = %u\n\n", ft_dest, ft_ret);
	
	//test 2
	char src2[] = "World";
	char dest2[4];
	unsigned int ret2;
	
	char ft_src2[] = "World";
	char ft_dest2[4];
	unsigned int ft_ret2;

	ret2 = strlcpy(dest2, src2, 4);
	printf("dest2 = %s || ret2 = %u\n", dest2, ret2);
	ft_ret2 = ft_strlcpy(ft_dest2, ft_src2, 4);
	printf("ft_dest2 = %s || ft_ret2 = %u\n\n", ft_dest2, ft_ret2);
	
	//test 3
	char src3[] = "HelloW";
	char dest3[10];
	unsigned int ret3;
	char ft_src3[] = "HelloW";
	char ft_dest3[10];
	unsigned int ft_ret3;

	ret3 = strlcpy(dest3, src3, 0);
	printf("dest3 = %s || ret3 = %u\n", dest3, ret3);
	ft_ret3 = ft_strlcpy(ft_dest3, ft_src3, 0);
	printf("ft_dest3 = %s || ft_ret3 = %u\n\n", ft_dest3, ft_ret3);
	
	//test 4
	char src4[] = "Chat";
	char dest4[5];
	unsigned int ret4;
	char ft_src4[] = "Chat";
	char ft_dest4[5];
	unsigned int ft_ret4;

	ret4 = strlcpy(dest4, src4, 5);
	printf("dest4 = %s || ret4 = %u\n", dest4, ret4);
	ft_ret4 = ft_strlcpy(ft_dest4, ft_src4, 5);
	printf("ft_dest4 = %s || ft_ret4 = %u\n\n", ft_dest4, ft_ret4);
}
*/