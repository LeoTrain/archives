/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:29:48 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/05 20:07:48 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	temporary_index;
	int	temporary_str_index;

	index = 0;
	if (!*to_find)
		return (str);
	while (str[index])
	{
		temporary_index = 0;
		temporary_str_index = index;
		while (str[temporary_str_index] && to_find[temporary_index] && 
			str[temporary_str_index] == to_find[temporary_index])
		{
			temporary_index++;
			temporary_str_index++;
		}
		if (!to_find[temporary_index])
			return (&str[index]);
		index++;
	}
	return ("\0");
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_strstr("I am the best", "the"));
}
*/