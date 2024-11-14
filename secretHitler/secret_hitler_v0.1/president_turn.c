#include "lib.h"

Cards	president_turn(int president, Players *player, Cards card)
{
	int 	number_of_fascist_cards = rand() % 4;
	int 	number_of_liberal_cards = 3 - number_of_fascist_cards;
	int 	discard_answer = 2;
	Cards	final_card;

	// DISCARD CARD FOR PLAYER
	if (president == 0)
	{
		printf("You received %d of fascist and %d of liberal cards.\n", number_of_fascist_cards, number_of_liberal_cards);
		printf("Choose one to discard (1 - Fascist / 0 - Liberal): ");
		scanf("%d", &discard_answer);
	}
	// DISCARD CARD FOR COMPUTER	
	else if (president > 0 && president < PLAYER_AMOUNT)
	{
		if (player[president].role == FASCIST || player[president].role == HITLER)
		{
			if (number_of_fascist_cards == 0)
			{
				discard_answer = 0;
			}
			else if (number_of_fascist_cards == 1)
			{
				discard_answer = 0;
			}
			else if (number_of_fascist_cards == 2)
			{
				discard_answer = 0;
			}
			else if (number_of_fascist_cards == 3)
			{
				discard_answer = 1;
			}
		}
		else if (player[president].role == LIBERAL)
		{
			if (number_of_liberal_cards == 0)
			{
				discard_answer = 1;
			}
			else if (number_of_liberal_cards == 1)
			{
				discard_answer = 1;
			}
			else if (number_of_liberal_cards == 2)
			{
				discard_answer = 1;
			}
			else if (number_of_liberal_cards == 3)
			{
				discard_answer = 0;
			}	
		}
	}
	
	// DISCARD THE CHOOSEN CARD
	if (discard_answer == 0)
	{
		number_of_liberal_cards -= 1;
	}
	else if (discard_answer == 1)
	{
		number_of_fascist_cards -= 1;
	}
	else
	{
		printf("ERROR 'DISCARD CARD'\n");
	}

	final_card.fascist = number_of_fascist_cards;
	final_card.liberal = number_of_liberal_cards;

	card.fascist -= final_card.fascist;
	card.liberal -= final_card.liberal;

	return (final_card);

}