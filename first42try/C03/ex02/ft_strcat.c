/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:05:22 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 20:07:59 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	destlength;

	index = 0;
	destlength = ft_strlen(dest);
	while (src[index])
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

void	test_ft_strcat(void)
{
	char test1[50] = "Hello ";
	ft_strcat(test1, "World !");
	ft_putstr(test1); // Expected: "Hello World !"
	ft_putchar('\n');

	char test2[50] = "";
	ft_strcat(test2, "Only source string.");
	ft_putstr(test2); // Expected: "Only source string."
	ft_putchar('\n');

	char test3[50] = "Only dest string";
	ft_strcat(test3, "");
	ft_putstr(test3); // Expected: "Only dest string"
	ft_putchar('\n');

	char test4[50] = "";
	ft_strcat(test4, "");
	ft_putstr(test4); // Expected: "" (an empty string)
	ft_putchar('\n');
}

int	main(void)
{
	test_ft_strcat();
	return (0);
}
*/