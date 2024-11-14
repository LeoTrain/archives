/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:26:31 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 11:52:58 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int main()
{
	int result;

	result = ft_fibonacci(8);
	ft_putstr("The result should be --> 21 The resultis --> ");
	ft_putnbr(result);
	ft_putchar('\n');

	int result1;

	result1 = ft_fibonacci(4);
	ft_putstr("The result should be --> 3 The resultis --> ");
	ft_putnbr(result1);
	ft_putchar('\n');
}
*/