/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:36:33 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 19:39:35 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] += 32;
		index++;
	}
	return (str);
}

/*
#include <stdio.h>

int main()
{
	char test1[] = "hELLO WORLD !";
	printf("%s\n", ft_strlowcase(test1));
	
	char test2[] = "12345 HEFGF CD J";
	printf("%s\n", ft_strlowcase(test2));	
}
*/