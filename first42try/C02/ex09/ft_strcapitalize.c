/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:40:06 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 20:09:58 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isstart(char *str, int index)
{
	if (index == 0)
		return (1);
	if ((str[index - 1] >= 'a' && str[index - 1] <= 'z') || 
		(str[index - 1] >= 'A' && str[index - 1] <= 'Z') || 
		(str[index - 1] >= '0' && str[index - 1] <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isstart(str, index) == 1 && 
			(str[index] >= 'a' && str[index] <= 'z'))
			str[index] -= 32;
		else if (ft_isstart(str, index) == 0 && 
			(str[index] >= 'A' && str[index] <= 'Z'))
			str[index] += 32;
		index++;
	}
	return (str);
}

/*
#include <stdio.h>

int main()
{
	//test 1
	char test1[] = "je suis ftl maskey";
	printf("%s\n", ft_strcapitalize(test1));
	
	//test 2
	char test2[] = "jE sUIS fTL mASKEY";
	printf("%s\n", ft_strcapitalize(test2));
	
	//test 3
	char test3[] = "Je Suis 56Alpha 73credit";
	printf("%s\n", ft_strcapitalize(test3));
	
	//test final
	char testfinal[] = "salut, comment tu vas ? 
	42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(testfinal));
}
*/