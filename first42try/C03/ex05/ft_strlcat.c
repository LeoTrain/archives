/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:57:59 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 20:06:27 by lbertona         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;

	index = 0;
	dest_length = ft_strlen(dest);
	while (index < size && src[index])
	{
		dest[dest_length] = src[index];
		dest_length++;
		index++;
	}
	dest[dest_length] = '\0';
	return (dest_length);
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

void	ft_putnbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	test_ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int result;

	ft_putstr("Before: ");
	ft_putstr(dest);
	ft_putchar('\n');

	result = ft_strlcat(dest, src, size);

	ft_putstr("After: ");
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putstr("Returned value: ");
	ft_putnbr(result);
	ft_putchar('\n');
	ft_putchar('\n');
}

int	main(void)
{
	char dest1[100] = "Hello, ";
	char src1[] = "world!";
	test_ft_strlcat(dest1, src1, 6);

	char dest2[100] = "OpenAI ";
	char src2[] = "rocks!";
	test_ft_strlcat(dest2, src2, 15);

	char dest3[100] = "ChatGPT ";
	char src3[] = "is fun!";
	test_ft_strlcat(dest3, src3, 20);

	char dest4[100] = "Coding ";
	char src4[] = "is love!";
	test_ft_strlcat(dest4, src4, 5);

	return (0);
}
*/