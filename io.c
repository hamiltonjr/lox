#include "utils.h"

/*
 * This function create a tic tac toe game. It is a representation of 
 * the game board. It is part of Command-line Interface Tic Tac Toe 
 * Project (CLI_TTT).
 */

void create_game(void)
{

    // verify if game exists
    if (access(FILENAME, F_OK) == 0)
    {
        printf("%s\n", "Game already exists!");
        exit_game();
        printf("%s\n", "Game deleted and new game created");
    }

    // new game
    FILE *fp = fopen(FILENAME, "w"); 
    if (fp == NULL)
    {
        printf("%s\n%s\n", 
               "Error trying to create new game!",
               "Permission denied!"
        );
        exit(EXIT_FAILURE);
    }
    
    fputc('O', fp);
    fclose(fp);

}

/*
 * This function delete  game  file  (representation of game board), exiting 
 * game. It is part of Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */

void exit_game(void)
{

    char command[100];

    // verify if ngame exists or not
    if (access(FILENAME, F_OK) == -1)
    {
        fprintf(stderr, "Game do not exists!\n");
        exit(EXIT_FAILURE);
    }

    // build command
    strcpy(command, "rm ");
    strcat(command, FILENAME);

    // apply command and catch possible error
    int error = system(command);
    if (error == -1)
    {
        fprintf(stderr, "Error trying to delete game!");
        exit(EXIT_FAILURE);
    }

}

/*
 * test
 *
int main()
{

    system("ls");
    create_game();
    
    system("ls");
    exit_game();
    
    system("ls");
    return EXIT_SUCCESS;

}
*/

