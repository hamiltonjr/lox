#include "utils.h"

/*
 * This function saves the  Tic  Tac  Toe  game (its board representation 
 * in a file). It is part of Command-line  Interface Tic Tac Toe Project 
 * (CLI_TTT).
 */

void save_game(game *g)
{
    
    // prototype of encapsulated function
    static bool convert(int, int*, int*);

    int line = 0, column = 0;
    FILE *fpout;

    // try to open game file
    if ((fpout = fopen(FILENAME, "w")) == NULL)
    {
        fprintf(stderr, "Impossible to save game!\n");
        exit(EXIT_FAILURE);
    }

    // save turn
    fputc(g->turn, fpout);

    // save board
    for (register size_t pos = 1; pos <= 9; ++pos)
    {
        if (!convert(pos, &line, &column))
        {
            fprintf(stderr, "Internal error trying to convert position to coordinates\n");
            exit(EXIT_FAILURE);
        }
        fputc(g->board[line][column], fpout);
   }

    fclose(fpout);

}

/*
 * test
 *
int main()
{

    game *g = (game*)malloc(sizeof(game));

    g->turn = 'O';
    for (register size_t i = 0; i < 4; ++i)
        for (register size_t j = 0; j < 4; ++j)
            g->board[i][j] = ' ';

    g->board[1][1] = 'O';
    g->board[2][2] = 'X';
    g->board[1][2] = 'O';
    show_board(g);

    create_game();
    printf("Saving...\nVerify file\n");
    save_game(g);
    free(g);

    game *G = (game*)malloc(sizeof(game));
    G->turn = 'O';
    printf("Loading...\nVerify file\n");
    load_game(G);
    show_board(G);
    
    free(G);
    return EXIT_SUCCESS;

}
*/

