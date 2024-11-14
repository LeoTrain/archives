#include <string.h>
#include <stdio.h>

int main()
{
	char dest[50] = "Hello ";
	printf("%lu - %s\n", strlcat(dest, "World!", 2), dest);
	return (0);
}