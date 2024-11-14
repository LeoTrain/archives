/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:31:56 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/02 11:34:47 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	newa;

	newa = *a / *b;
	*b = *a % *b;
	*a = newa;
}

/*
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 3;
	
	printf("a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}
*/