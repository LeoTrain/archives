#include "lib.h"

void	role_attribution(Players *player)
{
	int hitler_rand = rand() % PLAYER_AMOUNT;
	
	int fascist_rand;
	do
	{
		fascist_rand = rand() % PLAYER_AMOUNT;
	} while (fascist_rand == hitler_rand);

	player[hitler_rand].role = HITLER;
	player[fascist_rand].role = FASCIST;

	for (int i = 0; i < PLAYER_AMOUNT; i++)
	{
		if (!(i == hitler_rand || i == fascist_rand))
		{
			player[i].role = LIBERAL;
		}
	}

	// SAY THE PLAYERS ROLE
	if (player[0].role == LIBERAL)
	{
		printf("You have recieved the role of LIBERAL.\n");
	}
	else if (player[0].role == FASCIST)
	{
		printf("You have recieved the role of FASCIST.\n");
		for (int i = 0; i < PLAYER_AMOUNT; i++)
		{
			if (player[i].role == HITLER)
			{
				printf("HITLER is %s.\n", player[i].name);
			}
		}
	}
	else if (player[0].role == HITLER)
	{
		printf("You have recieved the role of HITLER.\n");
	}
}