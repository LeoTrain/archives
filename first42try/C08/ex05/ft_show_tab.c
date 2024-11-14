/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:00:40 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/15 12:06:42 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

void ft_putnbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb > 9) {
        ft_putnbr(nb / 10);
    }
    char digit = nb % 10 + '0';
    write(1, &digit, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while (par[i].str != NULL)
	{
        ft_putstr(par[i].str);
        write(1, "\n", 1);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        ft_putstr(par[i].copy);
        write(1, "\n", 1);
        i++;
    }
}
