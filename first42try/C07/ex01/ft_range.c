/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:49:33 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 21:30:22 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	index;
	int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab = (int *)malloc(4 * size);
	if (!tab)
		return (NULL);
	index = 0;
	while (min < max)
	{
		tab[index] = min;
		index++;
		min++;
	}
	return (tab);
}

/*
#include <stdio.h>
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

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_print_array_recursively(int *tab, int size, int index)
{
	if (index < size)
	{
		ft_putnbr(tab[index]);
		ft_putchar(' ');
		ft_print_array_recursively(tab, size, index + 1);
	}
}

int main()
{
	int	start = 14;
	int	end = 27;
	int	size = end - start;
	int	*tab = ft_range(start, end);

	if (tab != NULL)
	{
		ft_print_array_recursively(tab, size, 0);
		ft_putchar('\n');
	}
	else
		ft_putstr("Error: Could not create array\n");

	free(tab);
	return (0);
}
*/