#include "utils.h"

/*
 * This function loads the Tic Tac Toe game (the board representation in
 * a file). It  is  part  of  Command-line Interface Tic Tac Toe Project
 * (CLI_TTT).
 */

void load_game(game *g)
{
    
    // prototype of encapsulated function
    static bool convert(int, int*, int*);

    int line, column, c;
    int counter = 0;
    FILE *fpin;

    // try to open game file
    if ((fpin = fopen(FILENAME, "r")) == NULL)
    {
        fprintf(stderr, "Impossible to load game!\n");
        exit(EXIT_FAILURE);
    }

    // turn (effectively at first move)
    g->turn = fgetc(fpin);

    // read board
    while ((c = fgetc(fpin)) != EOF && counter < 9)
    {
        counter++;
        if (!convert(counter, &line, &column))
        {
            fprintf(stderr, "Internal error trying convert position to coordinates!\n");
            exit(EXIT_FAILURE);
        }
        g->board[line][column] = c;
    }

    fclose(fpin);

}

/*
 * test
 *
int main()
{

    game *g = (game*)malloc(sizeof(game));

    g->turn = 'O';
    for (register size_t i = 0; i < 4; ++i)
    {
        for (register size_t j = 0; j < 4; ++j)
        {
            g->board[i][j] = ' ';
        }
    }
    
    load_game(g);
    show_board(g);

    free(g);
    return EXIT_SUCCESS;

}
*/
