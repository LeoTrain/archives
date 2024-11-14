/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:27:49 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 19:01:54 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!((str[index] >= 'a' && str[index] <= 'z') || 
				(str[index] >= 'A' && str[index] <= 'Z')))
			return (0);
		index++;
	}
	return (1);
}

/*
#include <stdio.h>
#include <ctype.h>

int main()
{
	//Test 1
	printf("%d\n", ft_str_is_alpha("abcdhfdbferDBBEHEBCBFYA"));
	
	//test2
	printf("%d\n", ft_str_is_alpha("123456789"));
	
	//test3
	printf("%d\n", ft_str_is_alpha("dsjf dfns"));
	
	//test 4
	int index = 0;

    while (index <= 127) {
        char strindex = (char)index;
        int alpha_output = ft_str_is_alpha(&strindex);
		if (alpha_output == 1)
        	printf("%d = %d\n", index, alpha_output);
        index++;
    }
}
*/