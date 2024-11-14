/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:39:59 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 20:07:19 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && (s1[index] || s2[index]))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
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

void	print_test_result(char *s1, char *s2, 
				unsigned int n, int expected)
{
	ft_putstr("Comparing '");
	ft_putstr(s1);
	ft_putstr("' and '");
	ft_putstr(s2);
	ft_putstr("' for ");
	ft_putchar(n + '0');
	ft_putstr(" characters: ");
	if (ft_strncmp(s1, s2, n) == expected)
		ft_putstr("Passed\n");
	else
		ft_putstr("Failed\n");
}

int		main(void)
{
	print_test_result("apple", "apple", 5, 0);
	print_test_result("apple", "apples", 5, 0);
	print_test_result("apple", "apples", 6, (unsigned char)'\0' - 
		(unsigned char)'s');
	print_test_result("banana", "bananB", 6, (unsigned char)'a' - 
		(unsigned char)'B');
	print_test_result("cherry", "Cherry", 1, (unsigned char)'c' - 
		(unsigned char)'C');
	return (0);
}
*/