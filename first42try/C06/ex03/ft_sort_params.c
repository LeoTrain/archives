/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:41:13 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/08 17:05:19 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **first, char **second)
{
	char	*temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	ft_recursive_sort(char **argv, int argc, int index, int *sorted)
{
	if (index < argc - 1)
	{
		if (argv[index][0] > argv[index + 1][0])
		{
			ft_swap(&argv[index], &argv[index + 1]);
			*sorted = 0;
		}
		ft_recursive_sort(argv, argc, index + 1, sorted);
	}
}

void	ft_print_params(char **argv, int index, int argc)
{
	if (index < argc)
	{
		ft_putstr(argv[index]);
		write(1, "\n", 1);
		ft_print_params(argv, index + 1, argc);
	}
}

int	main(int argc, char **argv)
{
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		ft_recursive_sort(argv, argc, 1, &sorted);
	}
	ft_print_params(argv, 1, argc);
	return (0);
}
