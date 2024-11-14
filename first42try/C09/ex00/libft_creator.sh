#!/bin/bash

gcc -Wall -Wextra -Werror -c ft_putchar.c
gcc -Wall -Wextra -Werror -c ft_putstr.c
gcc -Wall -Wextra -Werror -c ft_strcmp.c
gcc -Wall -Wextra -Werror -c ft_strlen.c
gcc -Wall -Wextra -Werror -c ft_swap.c

ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

