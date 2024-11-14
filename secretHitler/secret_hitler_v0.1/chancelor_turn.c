#include "lib.h"

void	chancelor_turn(int chancelor, int president, Cards *final_card, Players *player)
{
	// TO TEST
	/*for (int i = 0; i < PLAYER_AMOUNT; i++)
	{
		printf("player name: %s, player role: ", player[i].name);
		if (player[i].role == 0)
			printf("LIBERAL\n");
		else if (player[i].role == 1)
			printf("FASCIST\n");
		else if (player[i].role == 2)
			printf("HITLER\n");
	}*/
	



	(void)president;


	// FOR PLAYER
	if (chancelor == 0)
	{
		int player_answer;
		printf("You recieved %d of fascist and %d on liberal cards.\n", final_card->fascist, final_card->liberal);
		printf("Choose 1 to remove the FASCIST card and 0 for the LIBERAL: ");
		scanf("%d", &player_answer);
		if (player_answer == 1)
		{
			final_card->fascist -= 1;
		}
		else if (player_answer == 0)
		{
			final_card->liberal -= 1;
		}
		else
		{
			printf("ERROR FOR PLAYER - CHANCELOR TURN\n");
		}
	}

	// FOR COMPUTER
    if (chancelor != 0 && (player[chancelor].role == FASCIST || player[chancelor].role == HITLER))
    {
		if (final_card->liberal > 0)
		{
			final_card->liberal -= 1;
		}
		else if (final_card->fascist == 2)
		{
			final_card->fascist -= 1;
		}
    }
	else if (chancelor != 0 && player[chancelor].role == LIBERAL)
	{
		if (final_card->fascist > 0)
		{
			final_card->fascist -= 1;
		}
		else if (final_card->liberal == 2)
		{
			final_card->liberal -= 1;
		}
	}
}
