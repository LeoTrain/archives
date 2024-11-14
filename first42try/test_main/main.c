/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertona <lbertona@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:07:43 by lbertona          #+#    #+#             */
/*   Updated: 2023/11/22 11:58:19 by lbertona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
 
#define  BUF_SIZE  20
 
int main(void)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char d[27];
	
	ft_memcpy(d, s, 27);
	printf("%s\n", d);
	return (0);
}

	//ISALPHA
	//printf("%d\n", ft_isalpha('a'));
	//printf("%d\n", ft_isalpha('7'));
	//printf("%d\n", ft_isalpha('Y'));
	//ISDIGIT
	//printf("%d\n", ft_isdigit('a'));
	//printf("%d\n", ft_isdigit('7'));
	//printf("%d\n", ft_isdigit('Y'));
	//ISALNUM
	//printf("%d\n", ft_isalnum('a'));
	//printf("%d\n", ft_isalnum('7'));
	//printf("%d\n", ft_isalnum('G'));
	//printf("%d\n", ft_isalnum('\n'));
	//printf("%d\n", ft_isalnum('@'));
	//MEMSET
	//char buffer[BUF_SIZE + 1];
	//memset(buffer, 0, 21);
    //memset(buffer,'A', 10);
    //printf("\nBuffer contents: %s\n", buffer);
    //memset(buffer+10, 'B', 10);
    //printf("\nBuffer contents: %s\n", buffer);
    //char buffer_test[BUF_SIZE + 1];
    //ft_memset(buffer_test, 0, 21);
    //ft_memset(buffer_test, 'A', 10);
    //printf("\nBuffer contents: %s\n", buffer_test);
    //memset(buffer_test+10, 'B', 10);
    //printf("\nBuffer contents: %s\n", buffer_test);
	
	//BZERO
	//char mem[5];
	//ft_memset(mem, 'e', 5);
	//ft_bzero(mem, 5);
	//printf("%s\n", mem);