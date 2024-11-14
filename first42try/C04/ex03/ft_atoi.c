/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:49:24 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/06 19:56:55 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	inted_str;
	int	sign;

	index = 0;
	inted_str = 0;
	sign = 1;
	while (str[index])
	{
		if (!((str[index] >= '0' && str[index] <= '9') || 
				str[index] == ' ' || str[index] == '-' || str[index] == '+'))
			return (inted_str * sign);
		while (str[index] == ' ')
			index++;
		while (str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-')
				sign *= -1;
			index++;
		}
		inted_str *= 10;
		inted_str += (str[index] - '0');
		index++;
	}
	return (inted_str * sign);
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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = -nb;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int main()
{
	// test 1
	ft_putstr("The outcome should be: 1\n");
	ft_putstr("Output --> ");
	int outcome = ft_atoi("1");
	ft_putnbr(outcome);
	if (outcome == 1)
		ft_putstr(" // Passed\n\n");
	else if (outcome != 1)
		ft_putstr(" // Failed\n\n");

	// test 2
	ft_putstr("The outcome should be: 1234\n");
	ft_putstr("Output --> ");
	int outcome2 = ft_atoi("1234");
	ft_putnbr(outcome2);
	if (outcome2 == 1234)
		ft_putstr(" // Passed\n\n");
	else if (outcome2 != 1234)
		ft_putstr(" // Failed\n\n");

	// test 3
	ft_putstr("The outcome should be: 1234\n");
	ft_putstr("Output --> ");
	int outcome3 = ft_atoi("   1234");
	ft_putnbr(outcome3);
	if (outcome3 == 1234)
		ft_putstr(" // Passed\n\n");
	else if (outcome3 != 1234)
		ft_putstr(" // Failed\n\n");
		
	// test 4
	ft_putstr("The outcome should be: -1234\n");
	ft_putstr("Output --> ");
	int outcome4 = ft_atoi("++--+---+1234");
	ft_putnbr(outcome4);
	if (outcome4 == -1234)
		ft_putstr(" // Passed\n\n");
	else if (outcome4 != -1234)
		ft_putstr(" // Failed\n\n");

	// test 5
	ft_putstr("The outcome should be: -1234\n");
	ft_putstr("Output --> ");
	int outcome5 = ft_atoi("---1234abc567");
	ft_putnbr(outcome5);
	if (outcome5 == -1234)
		ft_putstr(" // Passed\n\n");
	else if (outcome5 != -1234)
		ft_putstr(" // Failed\n\n");

	// test final
	ft_putstr("The outcome should be: -1234\n");
	ft_putstr("Output --> ");
	int outcomefinal = ft_atoi("---+--+1234ab567");
	ft_putnbr(outcomefinal);
	if (outcomefinal == -1234)
		ft_putstr(" // Passed\n\n");
	else if (outcomefinal != -1234)
		ft_putstr(" // Failed\n\n");
	return (0);
}
*/