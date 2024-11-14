/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:37:47 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/02 11:40:16 by lbertona         ###   ########.fr       */
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

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *str = "FT_Leo";

	printf("%lu\n", strlen(str));
	printf("%d\n", ft_strlen(str));
}
*/