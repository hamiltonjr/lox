# lox
It is a Tic Tac Toe game using the Linux command-line interface.

I never saw a Tic Tac Toe like this, using the Unix/Linux CLI. Them I coded it.
For understand how to proceed and play, use:

   ./lox -h 

for help. It is for 2 user players (not to play against the computer). The idea
is use CLI. A version and author can be visualized with:

   ./lox -v

Create a new game with:

   ./lox -c

The players wil see a congrats and the empty board:

       |   |   
    ---+---+---
       |   |   
    ---+---+---
       |   |   

The position are numbered from 1 to 9:

     1 | 2 | 3 
    ---+---+---
     4 | 5 | 6 
    ---+---+---
     8 | 8 | 9 

The players then can alternate with the command:

   ./lox -p [pos]

when pos is the position from 1 to 9 in the board. The game begins with
O and goes alternating automatically. The program says when a player wins
or when it is a tie. In case of win or tie, the game is ended (and the 
game file is deleted). A player also can end a game in any time.

In November, 2020 I was coded the core and now I am doing little enhance-
ments. Depending when you are seeing it, the code can have some errors. I
am not secure to exclude all test code at the end of each .c file.

The game is available as a free software under MIT License.

