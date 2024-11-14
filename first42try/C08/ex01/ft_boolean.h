#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H
#define TRUE 1
#define FALSE 2
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0
#define EVEN(x) ((x) % 2 == 0)

#include <unistd.h>
#include <stdbool.h>

typedef	int	t_bool;

#endif