#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main() {
    char src[] = "Texte de test";
    char dest[50];

    // Test 1: Copie normale
    size_t ret = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 1 - Copie normale: %s, Longueur copiée: %zu\n", dest, ret);

    // Test 2: Copie avec limitation de la taille du tampon
    char smallDest[5];
    ret = ft_strlcpy(smallDest, src, sizeof(smallDest));
    printf("Test 2 - Copie avec tampon limité: %s, Longueur copiée: %zu\n", smallDest, ret);

    // Test 3: Copie avec tampon de taille 0
    ret = ft_strlcpy(smallDest, src, 0);
    printf("Test 3 - Copie avec tampon de taille 0, Longueur copiée: %zu\n", ret);

    return 0;
}