/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:59 by lbertona          #+#    #+#             */
/*   Updated: 2023/10/30 13:10:54 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	write_comb(int first, int second, int finish)
{
	ft_putchar(first / 10 + 48);
	ft_putchar(first % 10 + 48);
	write (1, " ", 1);
	ft_putchar(second / 10 + 48);
	ft_putchar(second % 10 + 48);
	if (finish == 1)
		return ;
	write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;
	int	finish;

	finish = 0;
	first = 0;
	while (first < 99)
	{
		second = first + 1;
		while (second <= 99)
		{
			if (first == 98 && second == 99)
				finish = 1;
			write_comb(first, second, finish);
			second++;
		}
		first++;
	}
}
