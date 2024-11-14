/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:18 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 13:28:21 by lbertona         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
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
	ft_putstr("The answer should be '47' and it is '");
	ft_putnbr(ft_find_next_prime(44));
	ft_putstr("'.\n");
	
	ft_putstr("The answer should be '197' and it is '");
	ft_putnbr(ft_find_next_prime(197));
	ft_putstr("'.\n");
	
	ft_putstr("The answer should be '199' and it is '");
	ft_putnbr(ft_find_next_prime(198));
	ft_putstr("'.\n");
}
*/