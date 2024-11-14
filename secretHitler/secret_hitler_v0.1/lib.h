#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NAME_LENGTH 50
#define PLAYER_AMOUNT 5
#define FASCIST_WIN 7
#define LIBERAL_WIN 5

typedef enum {LIBERAL, FASCIST, HITLER} Role;

typedef struct
{
	char name[NAME_LENGTH];
	Role role;
	int	vote;
	int position;

}Players;

typedef struct
{
	int fascist;
	int liberal;
}Cards;


void	role_attribution(Players *player);
int		vote(int player_vote, Players *player, int chancelor);
Cards	president_turn(int president, Players *player, Cards card);
void	chancelor_turn(int chancelor, int president, Cards *final_card, Players *player);
void	print_board(const Cards final_card, Cards *all_cards_on_board);
int		computer_turn(Players *player, int president);
void	progress_bar(int duration);

#endif