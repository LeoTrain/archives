#include "lib.h"

int	vote(int player_vote, Players *player, int chancelor)
{
	printf("Voting...\n");
	sleep(3);

    int vote_total = player_vote;

    // GET EACH VOTE
    for (int i = 1; i < PLAYER_AMOUNT; i++)
    {
        player[i].vote = rand() % 2;
        vote_total += (player[i].vote == 0) ? -1 : 1;
    }

    // VOTE RESULTS
    if (vote_total > 0)
    {
        printf("Chancelor %s has been elected.\n", player[chancelor].name);
		return (1);
	}
    else
    {
		return (0);
	}
}
