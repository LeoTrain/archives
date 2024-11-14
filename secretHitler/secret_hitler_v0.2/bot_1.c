#include "lib.h"

void	bot_1(Players *player, Cards *card)
{
	// INITIALIZING VARIABLES
	int chancelor;
	int player_answer_for_chancelor;
	int vote_total;

	vote_total = 0;

/*---------------------------------------------------------------------------------------------------*/
//CHANCELOR

	// CHOOSING A CHANCELOR
	printf("PRESIDENT %s is choosing a CHANCELOR...\n", player[1].name);
	
		// IF BOT IS FASCIST OR HITLER
	if (player[1].role == FASCIST || player[1].role == HITLER)
	{
		do
		{
			chancelor = rand() % PLAYER_AMOUNT;
		} while (chancelor == player[1].position);
	}
		// IF BOT IS LIBERAL
	else if (player[1].role == LIBERAL)
	{
		do
		{
			chancelor = rand() % PLAYER_AMOUNT;
		} while (chancelor == player[1].position);
	}

	// ANNOUNCING ELECTED CHANCELOR
	printf("PRESIDENT %s elected %s as CHANCELOR.\n", player[1].name, player[chancelor].name);

/*---------------------------------------------------------------------------------------------------*/
//VOTES

	// PLAYER VOTES
	printf("Please choose if %s should be chancelor.\n", player[chancelor].name);
	printf("1 = yes / 2 = no\n");
	scanf ("%d", &player_answer_for_chancelor);
	if (player_answer_for_chancelor == 1)
	{
		vote_total += 1;
		player->vote = 1;
	}
	else if (player_answer_for_chancelor == 2)
	{
		vote_total += 0;
		player->vote = 0;
	}

	// BOT VOTE
	player[1].vote = 1;

	// OTHER BOTS VOTE
	for (int i = 2; i < PLAYER_AMOUNT; i++)
    {
        player[i].vote = rand() % 2;
        vote_total += (player[i].vote == 0) ? 0 : 1;
    }

	// CHECKS IF VOTES ARE HIGHER THAN 3
	if (vote_total >= 3)
	{
		// ANOUNCE CHANCELOR HAS BEEN ELECTED
		printf("CHANCELOR %s has been elected.\n", player[chancelor].name);
		for (int i = 0; i < PLAYER_AMOUNT; i++)
		{
			printf("%s choosed ", player[i].name);
			if (player[i].vote == 1)
			{
				printf("yes.\n");
			}
			else
			{
				printf("no.\n");
			}
		}

/*-------------------------------------------------------------------------------------*/
// CARDS

		// GIVE 3 RANDOM CARDS FROM 17 TO BOT_1
		Cards bot_card_president;

		if (card->fascist >= 3)
		{
			bot_card_president.fascist = rand() % 4;
		}
		else
		{
			if (card->fascist == 2)
			{
				bot_card_president.fascist = rand() % 3;
			}
			else if (card->fascist == 1)
			{
				bot_card_president.fascist = rand() % 2;
			}
			else
			{
				bot_card_president.fascist = 0;
			}
		}

		if (card->liberal >= 3)
		{
			bot_card_president.liberal = 3 - bot_card_president.fascist;
		}
		else
		{
			if (bot_card_president.fascist == 2)
			{
				bot_card_president.liberal = 1;
			}
			else if (bot_card_president.fascist == 1)
			{
				bot_card_president.liberal = 2;
			}
			else
			{
				bot_card_president.liberal = 3;
			}
		}

		// CHOOSES THE CARD TO DISCARD
			// BOT IS FASCIST OR HITLER
		if (player[1].role == FASCIST || player[1].role == HITLER)
		{
			if (bot_card_president.liberal > 0)
			{
				bot_card_president.liberal -= 1;
			}
			else
			{
				bot_card_president.fascist -= 1;
			}
		}
			// BOT IS LIBERAL
		else if (player[1].role == LIBERAL)
		{

		}

		// GIVES THE REMAINING CARDS TO CHANCELOR

		// ANOUNCING WHAT THE CHANCELOR HAS CHOOSEN

		// SAYING WHAT I RECIEVED ORIGINALY (LIE IF HITLER OR FASCIST)

		// OTHER PLAYER ANSWER

		// TURN FINISHED

	}
	else
	{
		printf("CHANCELOR %s has not been elected.\n", player[chancelor].name);
	}
}