/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:15:36 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 20:06:07 by lbertona         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	destlength;
	unsigned int	index;

	index = 0;
	destlength = ft_strlen(dest);
	while (index < nb)
	{
		dest[destlength] = src[index];
		index++;
		destlength++;
	}
	dest[destlength] = '\0';
	return (dest);
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_test_strncat(char *base, char *append, unsigned int n)
{
	ft_putstr("Before: ");
	ft_putstr(base);
	ft_putchar('\n');
	ft_strncat(base, append, n);
	ft_putstr("After: ");
	ft_putstr(base);
	ft_putchar('\n');
	ft_putchar('\n');
}

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = " World";

	ft_test_strncat(str1, str2, 3);
	
	char	str11[] = "Hello";
	char	str33[] = "C";

	ft_test_strncat(str11, str33, 1);
	
	char	str111[] = "Hello";
	char	str333[] = "C";
	
	ft_test_strncat(str111, str333, 0);
	
	return (0);
}
*/