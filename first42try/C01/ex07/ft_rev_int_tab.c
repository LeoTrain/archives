/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:40:50 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/02 15:30:13 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	swap;

	index = 0;
	while (index <= size / 2)
	{
		swap = tab[index];
		tab[index] = tab[size - 1];
		tab[size - 1] = swap;
		index++;
		size--;
	}
}

/*
#include <stdio.h>

int main()
{
	int tab[5] = {0, 1, 2, 3, 4};
	
	printf("%d, %d, %d, %d, %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
	ft_rev_int_tab(tab, 5);
	printf("%d, %d, %d, %d, %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
}
*/