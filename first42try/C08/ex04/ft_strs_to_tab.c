/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:11 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/15 11:54:52 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		index;

	index = 0;
	dest = malloc(ft_strlen(src));
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					index;

	tab = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (tab == NULL)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		tab[index].size = ft_strlen(av[index]);
		tab[index].str = av[index];
		tab[index].copy = ft_strdup(av[index]);
		if (!tab[index].copy)
		{
			while (--index > 0)
				free(tab[index].copy);
			free(tab);
			return (NULL);
		}
		index++;
	}
	tab[ac].str = NULL;
	return (tab);
}

/*
#include <stdio.h>

int main(int argc, char **argv)
{
	struct s_stock_str	*tab;
	tab = ft_strs_to_tab(argc, argv);
	
	int index;
	index = 0;
	while (index < argc)
	{
		printf("size = %d, str = %s, copy = %s\n", tab[index].size, tab[index].str, tab[index].copy);
		index++;
	}
}
*/