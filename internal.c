#include "utils.h"

/*
 * This function converts a string with numbers in an integer number.
 * It is part of Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */

int atoi(char *s)
{

    int n, sign;

    // skip spaces
    for ( ; isspace(*s); s++);

    // determine signal
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
    {
        s++;
    }

    // build number
    for (n = 0; isdigit(*s); s++)
    {
        n = BASE * n + (*s - '0');
    }

    return sign * n;

}

/*
 * This function converts positions (1-9) to coordinates ((1-3, 1-3)).
 * Returns true if the conversion was made and false otherwise. It is
 * part of Command-line Interface Tic Tac Toe Project (CLI_TTT).
 */ 

bool convert(int pos, int *line, int *column)
{

    // avoid pos out of range
    if (pos < 1 || pos > 9)
        return false;

    // converts
    *line = (pos - 1) / 3 + 1;
    *column = (pos - 1) % 3 + 1;
    return true;

}

/*
 * test
 *
int main()
{

    int line, column;

    char a[10] = "23771";
    int i = atoi(a);

    printf("Converted a = %s to i = %d\n", a, i);
    printf("i = i + 3 = %d\n", i + 3);
    if (convert(0, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
           0 , line, column);
    
    if (convert(3, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            3, line, column);
    
    if (convert(4, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            4, line, column);
    
    if (convert(5, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            5, line, column);
    
    if (convert(7, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            7, line, column);
    
    if (convert(-1, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            -1, line, column);
    
    if (convert(9, &line, &column))
        printf("Position: %d => Line: %d Column: %d\n", 
            9, line, column);

    return EXIT_SUCCESS;

}
*/

