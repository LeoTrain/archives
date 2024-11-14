#include "includes/ft.h"
#include <stdio.h>

int main()
{
	ft_putchar('a');
	ft_putstr("\nbcdef fgh\n");
	ft_strcmp("abc", "abc");
	printf("%d\n", ft_strlen("Hello World !"));
	int a = 5;
	int b = 10;
	printf("%d - %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d - %d\n", a, b);
	return (0);
}