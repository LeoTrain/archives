/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:23:36 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/12 21:03:37 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	ft_result_size(char **strs, int size, char *sep)
{
	int	index;
	int	result_size;
	int	sep_size;

	index = 0;
	result_size = 0;
	sep_size = ft_strlen(sep);
	while (strs[index] != NULL && index < size)
	{
		result_size += ft_strlen(strs[index]);
		if (index < size - 1)
			result_size += sep_size;
		index++;
	}
	return (result_size);
}

char	*ft_real_str_join(int size, char **strs, char *sep, char *result)
{
	int	index;
	int	pos;
	int	temp;

	pos = 0;
	index = 0;
	while (index < size && strs[index] != NULL)
	{
		temp = 0;
		while (strs[index][temp] != '\0')
			result[pos++] = strs[index][temp++];
		if (index < size - 1)
		{
			temp = 0;
			while (sep[temp] != '\0')
				result[pos++] = sep[temp++];
		}
		index++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		result_size;

	result_size = ft_result_size(strs, size, sep);
	result = malloc(result_size + 1);
	if (!result)
		return (NULL);
	ft_real_str_join(size, strs, sep, result);
	result[result_size + 1] = '\0';
	return (result);
}

/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

int main()
{
	char	sep[] = " ";
	char	*string[9];
	int 	size = 9	;
	
	string[0] = "Hello";
	string[1] = "World";
	string[2] = "I'm";
	string[3] = "Leo";
	string[4] = "Heiter";
	string[5] = "Gesund";
	string[6] = "Liebevoll";
	string[7] = "Retzeln";
	string[8] = "Kochen";
	
	ft_putstr("all strings at the start = ");
	int index = 0;
	while (index < 9)
	{
		ft_putstr(string[index]);
		index++;
	}
	write(1, "\n", 1);

	ft_putstr("all strings at the end = ");
	char *result = ft_strjoin(size, string, sep);
	ft_putstr(result);
	write(1, "\n", 1);
}
*/