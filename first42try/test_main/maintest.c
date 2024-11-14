#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "Exemple de test";
    char dest[50];

    // Test 1: Copie simple sans chevauchement
    memmove(dest, src, strlen(src) + 1);
    printf("Test 1 - Copie simple: %s\n", dest);

    strcpy(src, "Exemple de test");

	// Test 2: Copie avec chevauchement, source est devant la destination
    memmove(src + 5, src, 10);
    printf("Test 2 - Chevauchement (source devant): %s\n", src);

    strcpy(src, "Exemple de test");

    // Test 3: Copie avec chevauchement, destination est devant la source
    memmove(src, src + 5, 10);
    printf("Test 3 - Chevauchement (destination devant): %s\n", src);

    return 0;
}