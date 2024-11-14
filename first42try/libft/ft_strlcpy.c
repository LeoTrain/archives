/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:11:41 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/23 13:20:42 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	while (src[i])
		i++;
	src_length = i;
	if (dstsize == 0 || dstsize < src_length)
		return (src_length);
	i = 0;
	while (src[i] && i < dstsize)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	((unsigned char *)dst)[i] = '\0';
	return (src_length);
}
