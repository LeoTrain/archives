/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:10 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/15 12:06:45 by lbertona         ###   ########.fr       */
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

int					ft_strlen(char *str);
void 				ft_putstr(char *str);
void 				ft_putnbr(int nb);
char				*ft_strdup(char *src);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void 				ft_show_tab(struct s_stock_str *par);


void ft_show_tab(struct s_stock_str *par);

#endif