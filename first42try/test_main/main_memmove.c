#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
    char src[] = "Helloworld";
    char dest[50];

    // Test 1: Copie simple sans chevauchement
    ft_memmove(dest, src, strlen(src) + 1);
    printf("Test 1 - Copie simple: %s\n", dest);

    strcpy(src, "Helloworld");

	// Test 2: Copie avec chevauchement, source est devant la destination
    ft_memmove(src + 2, src, 3);
    printf("Test 2 - Chevauchement (source devant): %s\n", src);

    strcpy(src, "Helloworld");

    // Test 3: Copie avec chevauchement, destination est devant la source
    ft_memmove(src, src + 2, 3);
    printf("Test 3 - Chevauchement (destination devant): %s\n", src);

    return 0;
}