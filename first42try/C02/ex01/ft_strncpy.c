/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:59:47 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 20:14:05 by lbertona         ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (dest[index])
	{
		if (dest[index] == '\0')
			dest[index] = '\0';
		index++;
	}
	if (n > ft_strlen(dest))
		return (src);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	//#Test 1
	char dest[100];
	printf("Test1 = %s\n", ft_strncpy(dest, "Bertonasco", 4));

	char dest1[] = "Leonardo";
	printf("Test1 = %s\n", strncpy(dest1, "Bertonasco", 4));
	
	//#Test 2
	char dest2[100];
	printf("Test2 = %s\n", ft_strncpy(dest2, "Bertonasco", 4));
	
	char dest3[] = "Leonardo";
	printf("Test2 = %s\n", strncpy(dest3, "Bertonasco", 4));
}
*/