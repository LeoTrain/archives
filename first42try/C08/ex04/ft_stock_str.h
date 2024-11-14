/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:10 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/15 11:57:06 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
#define FT_STOCK_STR_H

#include <stdlib.h>

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
}	t_stock_str;

#endif