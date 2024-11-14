/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:16:10 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/29 12:24:30 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	new_c;

	new_c = c;
	while (*s)
	{
		if (*s == new_c)
			return ((char *)s);
		s++;
	}
	if (new_c == '\0')
		return ((char *)s);
	return (NULL);
}
