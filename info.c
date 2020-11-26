#include "utils.h"

/*
 * This function presents a help for Tic Tac Toe game. It is part of
 * Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */
void help(void)
{

    printf(
            " Usage: ./box [option] [pos].            \n"
            " Options:                                \n"
            " Use -h to see this help                 \n"
            " Use -c to create a new game.            \n"
            " Use -x to exit game.                    \n"
            " Use -p [n] to put your X in a position  \n"
            " from 1 to 9 (the positions of a tic tac \n"
            " toe).                                   \n"
            "                                         \n"
            " Version: 1.0.0  by Hamilton G. Jr.      \n"
            " Thank you to play this game. It is free \n"
            " for everybody to have fun!              \n"
            "                                         \n"
    );

}

/*
 * This function presents version and author info for Tic Tac Toe 
 * game. It is part of Command-line Interface Tic Tac Toe Project 
 * (CLI_TTT).
 */
void version(void)
{

    printf(
            " Version: 1.0.0  by Hamilton G. Jr.      \n"
            " Thank you to play this game. It is free \n"
            " for everybody to have fun!              \n"
            "                                         \n"
    );

}

/*
 * test
 *
int main()
{

    help();
    version();
    return EXIT_SUCCESS;

}
*/

