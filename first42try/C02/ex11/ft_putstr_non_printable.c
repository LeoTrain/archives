/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:48:30 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/04 23:58:26 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_hex_digit(int n)
{
	if (n >= 0 && n <= 9)
		return ('0' + n);
	else if (n >= 10 && n <= 15)
		return ('a' + n - 10);
	return ('0');
}

void	ft_nonprint_to_hex(unsigned int n)
{
	if (n < 16)
		ft_putchar('0');
	if (n >= 16)
		ft_nonprint_to_hex(n / 16);
	ft_putchar(ft_hex_digit(n % 16));
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((str[index] >= 0 && str[index] <= 31) || str[index] == 127)
		{
			ft_putchar('\\');
			ft_nonprint_to_hex(str[index]);
		}
		else
			ft_putchar(str[index]);
		index++;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char test_str[67];
    int i = 0;
    
    while (i < 64)
    {
        test_str[i] = i / 2;
        test_str[i + 1] = 'a';
        i += 2;
    }

    test_str[64] = 127;  // DEL character
    test_str[65] = 'a';  // Following the pattern
    test_str[66] = '\0';  // Null-terminating the string

    // Known strings for diagnosis:
    printf("Starting the test:\n");
    ft_putstr_non_printable(test_str);
    printf("\nEnd of test.\n");

    return 0;
}
*/