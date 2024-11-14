void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);

#include <stdio.h>

int main()
{
	ft_putchar('c');
	ft_putchar('\n');
	ft_putstr("Hello World !\n");
	int res = ft_strcmp("Hello", "Hellp");
	printf("%d\n", res);
	int length = ft_strlen("Hello World!");
	printf("%d\n", length);
	int a = 5;
	int b = 10;
	printf("Before a = %d b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After a = %d b = %d\n", a, b);
	return (0);
}