/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:19:29 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 19:36:06 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - 32;
		index++;
	}
	return (str);
}

/*
#include <stdio.h>

int main()
{
	char test1[] = "Hello world !";
	printf("%s\n", ft_strupcase(test1));
	
	char test2[] = "12345 hefh cd j";
	printf("%s\n", ft_strupcase(test2));
}
*/