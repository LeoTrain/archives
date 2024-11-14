/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:54:10 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 12:13:19 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	index;

	if (nb == 1)
		return (1);
	else if (nb < (2 * 2))
		return (0);
	index = 1;
	while ((index * index) <= nb)
	{
		if ((index * index) == nb)
			return (index);
		index++;
	}
	return (0);
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int main()
{
	ft_putstr("The sqrt of 16 shoulde be 4. And it is --> ");
	ft_putnbr(ft_sqrt(16));
	ft_putchar('\n');
	
	ft_putstr("The sqrt of 1296 shoulde be 36. And it is --> ");
	ft_putnbr(ft_sqrt(1296));
	ft_putchar('\n');
	
	ft_putstr("The sqrt of 0 shoulde be 0. And it is --> ");
	ft_putnbr(ft_sqrt(0));
	ft_putchar('\n');

	ft_putstr("The sqrt of 1 shoulde be 1. And it is --> ");
	ft_putnbr(ft_sqrt(1));
	ft_putchar('\n');

	ft_putstr("The sqrt of 873 shoulde be 0. And it is --> ");
	ft_putnbr(ft_sqrt(873));
}
*/