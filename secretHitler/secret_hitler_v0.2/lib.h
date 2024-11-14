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


void	bot_1(Players *player, Cards *card);

#endif