#include "lib.h"

int main(void)
{
	srand(time(0));
	system("clear");
	printf("Starting Secret Hitler...\n");
	progress_bar(2);
	system("clear");
	

	// CARDS FOR THE BOARD
	Cards all_cards_on_board;
	all_cards_on_board.fascist = 0;
	all_cards_on_board.liberal = 0;
	// CARDS FOR PRESIDENT
	Cards card;
	card.fascist = 11;
	card.liberal = 6;
	// CARDS FOR CHANCELOR
	Cards final_card;
	final_card.fascist = 0;
	final_card.liberal = 0;
	// GET PLAYER NAME
	char player_name[NAME_LENGTH];
	// PLAYERS
	Players player[PLAYER_AMOUNT];
	int chancelor = 0;
	int player_vote = 0;
	int president = 0;
	// ROUNDS
	int round = 0;
	// CHANCELOR
	int elected = 0;

	// PLAYER CREATION
	printf("Hello, please enter your name: ");
	scanf("%s", player_name);
	strcpy(player[0].name, player_name);
	printf("You are Player n. 0.\n");

	// COMPUTER NAME CREATION
	for (int i = 1; i < PLAYER_AMOUNT; i++)
	{
		printf("Choose the name of player n. %d: ", i);
		scanf("%s", player[i].name);
	}
	progress_bar(2);
	system("clear");
	
	// ROLE ATTRIBUTION
	role_attribution(player);

	// GAME STARTS
	round = 0;
	while (1)
	{
		printf("Starting next round...\n");
		progress_bar(5);
		system("clear");
		printf("	ROUND %d - Choosing Chancelor	\n\n", round);
		
		printf("It's your turn as president\n");
		printf("1 - %s\n2 - %s\n3 - %s\n4 - %s\n", player[1].name, player[2].name, player[3].name, player[4].name);
		printf("Please choose a chancelor: ");
		scanf("%d", &chancelor);
		sleep (1);

		// VOTE
		printf("Starting voting phase...\n");
		progress_bar(2);
		system("clear");

		printf("	ROUND %d - Voting phase	\n\n", round);
		printf("President %s elected %s as Chancelor.\n", player[0].name, player[chancelor].name);
		printf("Vote 1 for yes and 0 for no: ");
		scanf("%d", &player_vote);
		elected = vote(player_vote, player, chancelor);
		if (elected == 1)
		{
			// PRESIDENT CHOOSES CARD TO DISCARD
			progress_bar(3);
			system("clear");
			printf("	ROUND %d - President discards	\n\n", round);
			president = 0;
			final_card = president_turn(president, player, card);
			
			// CHANCELOR TURN
			printf("Cards are given to the Chancelor...\n");
			sleep(2);
			chancelor_turn(chancelor, president, &final_card, player);
			printf("Chancelor chose one card.\n");
			sleep(1);

			//REMOVING CARD FROM DECK
			if (final_card.liberal == 0 && final_card.fascist == 1)
			{
				card.fascist -= 1;
			}
			else if (final_card.liberal == 1 && final_card.fascist == 0)
			{
				card.liberal -= 1;
			}
			else
			{
				printf("ERROR REMOVING CARD\n");
			}
		}
		else if (elected == 0)
		{
			printf("Next Round... Chancelor not elected\n");
			sleep(1);
			system("clear");

		}
		
		// SCORE IS SHOWN
		printf("Loading Board...\n");
		progress_bar(3);
		system("clear");
		print_board(final_card, &all_cards_on_board);
		sleep(4);

		// CHECKS IF SOMOENE WINS
		if (all_cards_on_board.fascist == FASCIST_WIN)
		{
			printf("FASCIST WIN\n");
			return (0);
		}
		else if (all_cards_on_board.liberal == LIBERAL_WIN)
		{
			printf("LIBERAL WIN\n");
			return (0);
		}

		// COMPUTERS TURN
		for (int i = 1; i < PLAYER_AMOUNT; i++)
		{
			printf("Loading next round...\n");
			progress_bar(2);
			system("clear");

			round += 1;
			printf("	ROUND %d - Computer	\n\n", round);
			printf("President is %s.\n", player[i].name);
			chancelor = computer_turn(player, i);
			printf("President %s elected %s as Chancelor.\n", player[i].name, player[chancelor].name);
			printf("Vote 1 for yes and 0 for no: ");
			scanf("%d", &player_vote);
			
			// VOTE
			president = i;
			elected = vote(player_vote, player, chancelor);
			sleep(2);
			if (elected == 1)
			{
				final_card = president_turn(president, player, card);
				printf("Cards are given to the Chancelor...\n");
				sleep(2);
				chancelor_turn(chancelor, president, &final_card, player);					
				printf("Chancelor chose one card.\n");
				sleep(1);

				//REMOVING CARD FROM DECK
				if (final_card.liberal == 0 && final_card.fascist == 1)
				{
					card.fascist -= 1;
				}
				else if (final_card.liberal == 1 && final_card.fascist == 0)
				{
					card.liberal -= 1;
				}
				else
				{
					printf("ERROR REMOVING CARD\n");
				}
			}
			else if (elected == 0)
			{
				printf("Next player... Chancelor not elected\n");
				sleep(1);
				system("clear");
				final_card.fascist = 0;
				final_card.liberal = 0;
			}

			printf("Loading Board...\n");
			progress_bar(3);
			system("clear");
			print_board(final_card, &all_cards_on_board);
			sleep(4);
			
			// CHECKS IF SOMOENE WINS
			if (all_cards_on_board.fascist == FASCIST_WIN)
			{
				printf("FASCIST WIN\n");
				return (0);
			}
			else if (all_cards_on_board.liberal == LIBERAL_WIN)
			{
				printf("LIBERAL WIN\n");
				return (0);
			}
		}
		// CHECKS IF SOMOENE WINS
		if (all_cards_on_board.fascist == FASCIST_WIN)
		{
			printf("FASCIST WIN\n");
			break;
		}
		else if (all_cards_on_board.liberal == LIBERAL_WIN)
		{
			printf("LIBERAL WIN\n");
			break;
		}
		round += 1;
	}
	return (0);
}