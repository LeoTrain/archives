#include "lib.h"

int	computer_turn(Players *player, int president)
{
	(void)player;
	
	int chancelor = president;
	do
	{
		chancelor = rand() % PLAYER_AMOUNT;
	} while (chancelor == president );

	return (chancelor);
	
}