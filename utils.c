#include "utils.h"

/*
 * This function verifies  if a  player won the gamen or if was a tie.
 * It is part of Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */

char verify_status(game *g)
{

    // one of players won
    if 
        // first line
        ((g->board[1][1] == g->turn && 
          g->board[1][2] == g->turn && 
          g->board[1][3] == g->turn) ||
        // second line
         (g->board[2][1] == g->turn && 
          g->board[2][2] == g->turn && 
          g->board[2][3] == g->turn) ||
        // third line
         (g->board[3][1] == g->turn && 
          g->board[3][2] == g->turn && 
          g->board[3][3] == g->turn) ||
        // first column
         (g->board[1][1] == g->turn && 
          g->board[2][1] == g->turn && 
          g->board[3][1] == g->turn) ||
        // second column
         (g->board[1][2] == g->turn && 
          g->board[2][2] == g->turn && 
          g->board[3][2] == g->turn) ||
        // third column
         (g->board[1][3] == g->turn && 
          g->board[2][3] == g->turn && 
          g->board[3][3] == g->turn) ||
        // main diagonal
         (g->board[1][1] == g->turn && 
          g->board[2][2] == g->turn && 
          g->board[3][3] == g->turn) ||
        // secondary diagonal
         (g->board[1][3] == g->turn && 
          g->board[2][2] == g->turn && 
          g->board[3][1] == g->turn))
    {
        return g->turn;
    }

    // while board has space, the game has no end
    for (register size_t line = 1; line < 4; ++line)
    {
        for (register size_t column = 1; column < 4; ++column)
        {
            if (g->board[line][column] == ' ')
            {
                return ' ';
            }
        }
    }

    return 'T';

}

/*
 * This function shows (prints) a boardn representation for Tic Tac Toe
 * game. It  is  part  of  Command-line Interface Tic Tac Toe Project 
 * (CLI_TTT).
 */

void show_board(game *g)
{

    printf("\t %c | %c | %c\n", 
            g->board[1][1], g->board[1][2], g->board[1][3]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c\n", 
            g->board[2][1], g->board[2][2], g->board[2][3]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c\n", 
            g->board[3][1], g->board[3][2], g->board[3][3]);
    printf("\n");

}

/*
 * test
 *
int main()
{

    game *g = (game*)malloc(sizeof(game));
    g->turn = 'O';
    
    for (register size_t i = 0; i < 4; ++i)
        g->board[0][i] = ' ';
    for (register size_t j = 0; j < 4; ++j)
        g->board[j][0] = ' ';

    g->board[1][1] = 'O';
    g->board[1][2] = 'X';
    g->board[1][3] = 'O';
    g->board[2][1] = 'X';
    g->board[2][2] = 'O';
    g->board[2][3] = 'X';
    g->board[3][1] = 'O';
    g->board[3][2] = 'X';
    g->board[3][3] = 'O';

    show_board(g);

    free(g);
    return EXIT_SUCCESS;

}
*/
