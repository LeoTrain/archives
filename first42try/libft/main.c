#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char first_try[] = "Le chien est @gros.";
	char *pointer_to_first = ft_strchr(first_try, '@');
	printf("%s\n", pointer_to_first);
	
	char *pointer_to_second = ft_strchr(first_try, '#');
	printf("%s\n", pointer_to_second);


	return (0);
}	