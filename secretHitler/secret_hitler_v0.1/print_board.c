#include "lib.h"

void	print_board(const Cards final_card, Cards *all_cards_on_board)
{
    int i;
	
	all_cards_on_board->fascist += final_card.fascist;
	all_cards_on_board->liberal += final_card.liberal;



    printf("	BOARD	\n");
    printf("LIBERAL LAWS: ");
    for (i = 0; i < all_cards_on_board->liberal; ++i)
    {
        printf("|L| ");
    }
    printf("\n");

    printf("FASCIST LAWS: ");
    for (i = 0; i < all_cards_on_board->fascist; ++i)
    {
        printf("|F| ");
    }
    printf("\n");
}

