#include "lib.h"

int main(void)
{
	Players player[PLAYER_AMOUNT];
	Cards card;
	card.fascist = 11;
	card.liberal = 6;

	// PLAYER CREATION
	printf("Hello, please enter your name: ");
	scanf("%s", player[0].name);
	printf("You are Player n. 0.\n");

	// COMPUTER NAME CREATION
	for (int i = 1; i < PLAYER_AMOUNT; i++)
	{
		printf("Choose the name of player n. %d: ", i);
		scanf("%s", player[i].name);
		player->position = i;
	}
	sleep(2);
	system("clear");

	bot_1(player, &card);

	return (0);
}