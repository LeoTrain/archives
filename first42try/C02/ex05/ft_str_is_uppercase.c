/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:06:12 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 19:08:09 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(str[index] >= 'A' && str[index] <= 'Z'))
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
        int output = ft_str_is_uppercase(&strindex);
		if (output == 1)
        	printf("%d = %d\n", index, output);
        index++;
    }
}
*/