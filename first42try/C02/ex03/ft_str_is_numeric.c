/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:59:24 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 19:03:12 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			return (0);
		index++;
	}
	return (1);
}

/*
#include <stdio.h>

int main()
{
	int index = 0;

    while (index <= 127)
	{
        char strindex = (char)index;
        int output = ft_str_is_numeric(&strindex);
		if (output == 1)
        	printf("%d = %d\n", index, output);
        index++;
    }
}
*/