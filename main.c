#include "utils.h"

/*
 * This function is the core of Tic Tac Toe game of Command-line Interface
 * Tic Tac Toe Project (lox).
 */

int main(int argc, char **argv)
{

    // allocate memory for game structure (turn and board)
    game *g = (game*)malloc(sizeof(game));    
    int pos, c;

    // initializes board with spaces
    for (register size_t i = 0; i < 4; ++i)
    {
        for (register size_t j = 0; j < 4; ++j)
        {
            g->board[i][j] = ' ';
        }
    }

    // dealing with arguments using getopt function (a GNU extension 
    // for glibc).
    opterr = 0;
    while ((c = getopt(argc, argv, "chxvp:")) != -1)
    {

        switch (c)
        {

        case 'c': create_game();
        printf("New game created!\nHave fun!\n");
        load_game(g);
        show_board(g);
        exit(EXIT_SUCCESS);

        case 'h': help();
            exit(EXIT_SUCCESS);
        
        case 'x': exit_game();
            printf("Game deleted\n");
            exit(EXIT_SUCCESS);

       case 'v': version();
            exit(EXIT_SUCCESS);

       case 'p': 
            pos = atoi(optarg);
            if (pos < 1 || pos > 9)
            {
                printf("Position out of range (1-9)\n");
                exit(EXIT_FAILURE);
            }
            break;
        
        case '?':
            fprintf(stderr, "Usage: ./lox [option] [pos].\n");
            exit(EXIT_SUCCESS);

        default: exit(EXIT_FAILURE);
        
        }

    }

    // extra options
    for (register size_t index = optind; index < argc; ++index)
    {
        fprintf(stderr, "Usage: ./lox [option] [pos].\n");
    }

    // load stored game and define turn.
    load_game(g);

    // execute user move
    play_game(g, pos);

    // show board with new move
    show_board(g);

    // after move, verify if some player won or if has a tie
    char status = verify_status(g);

    // save game (always)
    save_game(g);

    // winner
    if (status == 'X' || status == 'O')
    {
        printf("\n\tThe player '%c' won!\n\n", g->turn);
        exit_game();
        exit(EXIT_SUCCESS);
    }

    // tie
    if (status == 'T')
    {
        printf("\n\tIt is a tie!\n\n");
        exit_game();
        exit(EXIT_SUCCESS);
    }

    // if is none result
    return EXIT_SUCCESS;

}

