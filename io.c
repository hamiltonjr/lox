#include "utils.h"

/*
 * This function create a tic tac toe game. It is a representation of 
 * the game board. It is part of Command-line Interface Tic Tac Toe 
 * Project (CLI_TTT).
 */

void create_game(void)
{

    FILE *fpout;

    // try to open
    printf("Trying to create new game...\n");
    if ((fpout = fopen(FILENAME, "w")) == NULL)
    {
        fprintf(stderr, "Error trying to create new game!\n");
        exit(EXIT_FAILURE);
    }

    // initialize
    fputc('O', fpout);
    fclose(fpout);

}

/*
 * This function delete  game  file  (representation of game board), exiting 
 * game. It is part of Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */

void exit_game(void)
{

    char command[100];

    printf("Trying to delete game...\n");
    
    // build command
    strcpy(command, "rm ");
    strcat(command, FILENAME);

    // apply command and catch possible error
    int error = system(command);
    if (error == -1)
    {
        fprintf(stderr, "Error trying to delete game!\n");
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

