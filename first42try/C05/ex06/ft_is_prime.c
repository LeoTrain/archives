/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:56:07 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 13:16:36 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	index;

	if (nb <= 1)
		return (0);
	index = 2;
	while (index * index <= nb)
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
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

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int main()
{
	int	answer_1 = ft_is_prime(2);
	ft_putstr("Is it right ?\n");
	ft_putnbr(answer_1);
	ft_putstr("	It should be 1\n\n");
	
	ft_putnbr(ft_is_prime(5));
	ft_putstr("	It should be 1\n\n");
	
	ft_putnbr(ft_is_prime(7));
	ft_putstr("	It should be 1\n\n");

	ft_putnbr(ft_is_prime(11));
	ft_putstr("	It should be 1\n\n");
}
*/