#ifndef UTILS_H
#define UTILS_H

/*
 * This is the header that organizes the Command-line Interface Tic Tac Toe
 * Project (CLI_TTT).
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define FILENAME "game.dat"
#define BASE     10

struct game_
{
    char turn;
    char board[4][4];
};
typedef struct game_ game;

// prototype(s)
#undef atoi
#define atoi ATOI
int ATOI(char*);

void create_game(void);
void exit_game(void);
void help(void);
void version(void);
void load_game(game*);
void play_game(game*, int);
void save_game(game*);
void show_board(game*);
char verify_status(game*);

#endif // UTILS_H

