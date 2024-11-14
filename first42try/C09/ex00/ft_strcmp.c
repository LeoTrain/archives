/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:53:27 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/15 14:02:27 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;
	
	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
		else if (s1[index] < s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}