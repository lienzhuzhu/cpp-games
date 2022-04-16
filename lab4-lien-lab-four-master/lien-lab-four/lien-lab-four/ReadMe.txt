
Author: Lien Zhu, Vincent Chow

CSE 332 Lab 4 - TicTacToe and Gomoku Games

This program extends Lab 3 to allow users to play TicTacToe or Gomoku by:
1. allowing users to input coordinates for pieces
2. printing the board with valid moves
3. keeping track of moves made by each player
4. ending the game when necessary

5. If the user plays Gomoku, they also can specify board size and/or number of pieces in a row needed to win


Parameters:
The user can input:
1. Game they want to play
2. Dimensions for Gomoku
3. Pieces in a row needed to win for Gomoku
4. The user can also change piece representation in TicTacToe's base member initialization list, and in GomokuGame source file
   constant strings at top of file, pieceRepB and pieceRepW.




Possible program return values:
Enums for these can be found in enums.h
0 - successful program execution
    Game was played all the way through

7 - quit
    Player indicated that they quit the game

10 - TIE
     Tie game

1 - file_could_not_be_opened   
    Something went wrong trying to open the file 
    Please check to ensure the file specified exists in the correct path and is spelled correctly in command line
    

    !!!!!!!!!!!!!!!!!!!!!!!!!
2 - wrong_number_of_arguments
    Please check to ensure a file name was provided and only one file is specified

    !!!!NOTE!!!!: wrong_number_arguments is returned for BOTH if a bad game name is entered AND if bad arguments are entered because how_to_use() handles both situations
    and we decided these situations are equivalent and remediated by usage instruction printed to user.

4 - dimension_not_read
    A line from the file was read but dimensions could not be successfully extracted

5 - no_well_formed_pieces
    No pieces could be read 

6 - vector_dimension_do_not_fit
    The vector containing game_pieces has a size that does not match the dimensions of the board




In addition to returning an enumerated value, file_line_could_not_be_read, no_well_formed_pieces will print
an error message to console.



In the overloaded << operator for both derived classes, the spacing is set so that a width of 3 more than the longest string length is allotted.
setLongest() updates the longest string length. Left justification is used.



!!!!!!!!!!!!!!!!!
BUGS AND LEARNING:

No major bugs encountered



--------------------------------------------------------------------------------------------------  
Because the Testing section is so long, our description of the EXTRA CREDIT implementation is here:

EXTRA CREDIT:

We created three constructors for Gomoku, one default, one taking in a dimension, one taking in both a dimension and number of pieces
needed in a row to win. The methods done() and draw() both adjust to account for the number of pieces needed to win and dimension. Draw() checks for 
instances of toWin - 1 space sequences. If none exist and the game hasn't been won, a tie has occurred.

If the board dimension is less than 5, the number of pieces needed to win is set to one less than the dimension. 




Testing:

echo %errorlevel% returns correct values for each scenario


DEMONSTRATING SPACING AND PIECE REPRESENTATION
----------------------------------------------

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku 5
5
4
3
2
1
X       1       2       3       4       5
Player black, please enter coordinates separated by comma or "quit":
4,3

5
4
3                               black
2
1
X       1       2       3       4       5
Player black: 4,3

Player white, please enter coordinates separated by comma or "quit":



TICTACTOE
---------

// Complete game, tie game
//
C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe TicTacToe
4
3
2
1
0
    0   1   2   3   4

Player X, please enter coordinates separated by comma or "quit":
3,3

4
3               X
2
1
0
    0   1   2   3   4

Player X: 3,3

Player O, please enter coordinates separated by comma or "quit":
2,2

4
3               X
2           O
1
0
    0   1   2   3   4

Player O: 2,2

Player X, please enter coordinates separated by comma or "quit":
1,1

4
3               X
2           O
1       X
0
    0   1   2   3   4

Player X: 3,3; 1,1

Player O, please enter coordinates separated by comma or "quit":
2,1

4
3               X
2           O
1       X   O
0
    0   1   2   3   4

Player O: 2,2; 2,1

Player X, please enter coordinates separated by comma or "quit":
2,3

4
3           X   X
2           O
1       X   O
0
    0   1   2   3   4

Player X: 3,3; 1,1; 2,3

Player O, please enter coordinates separated by comma or "quit":
1,3

4
3       O   X   X
2           O
1       X   O
0
    0   1   2   3   4

Player O: 2,2; 2,1; 1,3

Player X, please enter coordinates separated by comma or "quit":
3,1

4
3       O   X   X
2           O
1       X   O   X
0
    0   1   2   3   4

Player X: 3,3; 1,1; 2,3; 3,1

Player O, please enter coordinates separated by comma or "quit":
3,2

4
3       O   X   X
2           O   O
1       X   O   X
0
    0   1   2   3   4

Player O: 2,2; 2,1; 1,3; 3,2

Player X, please enter coordinates separated by comma or "quit":
1,2

4
3       O   X   X
2       X   O   O
1       X   O   X
0
    0   1   2   3   4

Player X: 3,3; 1,1; 2,3; 3,1; 1,2

The game is a tie, 9 moves were made

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>






GOMOKU TESTING
--------------


// Complete Game, player wins
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B, please enter coordinates separated by comma or "quit":
10,14

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6
5
4
3
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14

Player W, please enter coordinates separated by comma or "quit":
4,3

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6
5
4
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3

Player B, please enter coordinates separated by comma or "quit":
5,5

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6
5                   B
4
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5

Player W, please enter coordinates separated by comma or "quit":
4,3
Player W, please enter coordinates separated by comma or "quit":
4,4

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6
5                   B
4               W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3; 4,4

Player B, please enter coordinates separated by comma or "quit":
5,6

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6                   B
5                   B
4               W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5; 5,6

Player W, please enter coordinates separated by comma or "quit":
5,4

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7
6                   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3; 4,4; 5,4

Player B, please enter coordinates separated by comma or "quit":
6,7

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7                       B
6                   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5; 5,6; 6,7

Player W, please enter coordinates separated by comma or "quit":
4,6

19
18
17
16
15
14                                      B
13
12
11
10
9
8
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3; 4,4; 5,4; 4,6

Player B, please enter coordinates separated by comma or "quit":
7,8

19
18
17
16
15
14                                      B
13
12
11
10
9
8                           B
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5; 5,6; 6,7; 7,8

Player W, please enter coordinates separated by comma or "quit":
19,19

19                                                                          W
18
17
16
15
14                                      B
13
12
11
10
9
8                           B
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3; 4,4; 5,4; 4,6; 19,19

Player B, please enter coordinates separated by comma or "quit":
20,20
Player B, please enter coordinates separated by comma or "quit":
9,10

19                                                                          W
18
17
16
15
14                                      B
13
12
11
10                                  B
9
8                           B
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5; 5,6; 6,7; 7,8; 9,10

Player W, please enter coordinates separated by comma or "quit":
15,15

19                                                                          W
18
17
16
15                                                          W
14                                      B
13
12
11
10                                  B
9
8                           B
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 4,3; 4,4; 5,4; 4,6; 19,19; 15,15

Player B, please enter coordinates separated by comma or "quit":
8,9

19                                                                          W
18
17
16
15                                                          W
14                                      B
13
12
11
10                                  B
9                               B
8                           B
7                       B
6               W   B
5                   B
4               W   W
3               W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 10,14; 5,5; 5,6; 6,7; 7,8; 9,10; 8,9

B won the game

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>



// Quit game
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B, please enter coordinates separated by comma or "quit":
5,4

19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4                   B
3
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player B: 5,4

Player W, please enter coordinates separated by comma or "quit":
18,3

19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4                   B
3                                                                       W
2
1
X   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
Player W: 18,3

Player B, please enter coordinates separated by comma or "quit":
quit
The game was quit, 2 moves were made

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>




EXTRA CREDIT
------------

// Dimension Given, Complete Game, player won
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku 10
10
9
8
7
6
5
4
3
2
1
X   1   2   3   4   5   6   7   8   9   10
Player B, please enter coordinates separated by comma or "quit":
4,3

10
9
8
7
6
5
4
3               B
2
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3

Player W, please enter coordinates separated by comma or "quit":
6,7

10
9
8
7                       W
6
5
4
3               B
2
1
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7

Player B, please enter coordinates separated by comma or "quit":
8,2

10
9
8
7                       W
6
5
4
3               B
2                               B
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2

Player W, please enter coordinates separated by comma or "quit":
9,2

10
9
8
7                       W
6
5
4
3               B
2                               B   W
1
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2

Player B, please enter coordinates separated by comma or "quit":
1,1

10
9
8
7                       W
6
5
4
3               B
2                               B   W
1   B
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1

Player W, please enter coordinates separated by comma or "quit":
6,8

10
9
8                       W
7                       W
6
5
4
3               B
2                               B   W
1   B
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8

Player B, please enter coordinates separated by comma or "quit":
5,2

10
9
8                       W
7                       W
6
5
4
3               B
2                   B           B   W
1   B
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2

Player W, please enter coordinates separated by comma or "quit":
7,5

10
9
8                       W
7                       W
6
5                           W
4
3               B
2                   B           B   W
1   B
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5

Player B, please enter coordinates separated by comma or "quit":
6,1

10
9
8                       W
7                       W
6
5                           W
4
3               B
2                   B           B   W
1   B                   B
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1

Player W, please enter coordinates separated by comma or "quit":
7,1

10
9
8                       W
7                       W
6
5                           W
4
3               B
2                   B           B   W
1   B                   B   W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1

Player B, please enter coordinates separated by comma or "quit":
2,2

10
9
8                       W
7                       W
6
5                           W
4
3               B
2       B           B           B   W
1   B                   B   W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2

Player W, please enter coordinates separated by comma or "quit":
8,3

10
9
8                       W
7                       W
6
5                           W
4
3               B               W
2       B           B           B   W
1   B                   B   W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3

Player B, please enter coordinates separated by comma or "quit":
6,5

10
9
8                       W
7                       W
6
5                       B   W
4
3               B               W
2       B           B           B   W
1   B                   B   W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5

Player W, please enter coordinates separated by comma or "quit":
10,1

10
9
8                       W
7                       W
6
5                       B   W
4
3               B               W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1

Player B, please enter coordinates separated by comma or "quit":
7,3

10
9
8                       W
7                       W
6
5                       B   W
4
3               B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3

Player W, please enter coordinates separated by comma or "quit":
7,4

10
9
8                       W
7                       W
6
5                       B   W
4                           W
3               B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4

Player B, please enter coordinates separated by comma or "quit":
4,7

10
9
8                       W
7               B       W
6
5                       B   W
4                           W
3               B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3; 4,7

Player W, please enter coordinates separated by comma or "quit":
11,11
Player W, please enter coordinates separated by comma or "quit":
10,10

10                                      W
9
8                       W
7               B       W
6
5                       B   W
4                           W
3               B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4; 10,10

Player B, please enter coordinates separated by comma or "quit":
3,3

10                                      W
9
8                       W
7               B       W
6
5                       B   W
4                           W
3           B   B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3; 4,7; 3,3

Player W, please enter coordinates separated by comma or "quit":
6,6

10                                      W
9
8                       W
7               B       W
6                       W
5                       B   W
4                           W
3           B   B           B   W
2       B           B           B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4; 10,10; 6,6

Player B, please enter coordinates separated by comma or "quit":
6,2

10                                      W
9
8                       W
7               B       W
6                       W
5                       B   W
4                           W
3           B   B           B   W
2       B           B   B       B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3; 4,7; 3,3; 6,2

Player W, please enter coordinates separated by comma or "quit":
8,4

10                                      W
9
8                       W
7               B       W
6                       W
5                       B   W
4                           W   W
3           B   B           B   W
2       B           B   B       B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4; 10,10; 6,6; 8,4

Player B, please enter coordinates separated by comma or "quit":
1,10

10  B                                   W
9
8                       W
7               B       W
6                       W
5                       B   W
4                           W   W
3           B   B           B   W
2       B           B   B       B   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3; 4,7; 3,3; 6,2; 1,10

Player W, please enter coordinates separated by comma or "quit":
10,2

10  B                                   W
9
8                       W
7               B       W
6                       W
5                       B   W
4                           W   W
3           B   B           B   W
2       B           B   B       B   W   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4; 10,10; 6,6; 8,4; 10,2

Player B, please enter coordinates separated by comma or "quit":
10,5

10  B                                   W
9
8                       W
7               B       W
6                       W
5                       B   W           B
4                           W   W
3           B   B           B   W
2       B           B   B       B   W   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player B: 4,3; 8,2; 1,1; 5,2; 6,1; 2,2; 6,5; 7,3; 4,7; 3,3; 6,2; 1,10; 10,5

Player W, please enter coordinates separated by comma or "quit":
9,3

10  B                                   W
9
8                       W
7               B       W
6                       W
5                       B   W           B
4                           W   W
3           B   B           B   W   W
2       B           B   B       B   W   W
1   B                   B   W           W
X   1   2   3   4   5   6   7   8   9   10
Player W: 6,7; 9,2; 6,8; 7,5; 7,1; 8,3; 10,1; 7,4; 10,10; 6,6; 8,4; 10,2; 9,3

W won the game

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>



// Dimension and bad toWin given (toWin too high)
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku 10 10
usage: lien-lab-four.exe GameName
optionally for Gomoku: lien-lab-four.exe Gomoku <dimension> <pieces to win>


// Dimension too small
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku 2
usage: lien-lab-four.exe GameName
optionally for Gomoku: lien-lab-four.exe Gomoku <dimension> <pieces to win>

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>


// Dimension and toWin given, player won
//

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>lien-lab-four.exe Gomoku 10 4
10
9
8
7
6
5
4
3
2
1
X   1   2   3   4   5   6   7   8   9   10
Player B, please enter coordinates separated by comma or "quit":
5,4

10
9
8
7
6
5
4                   B
3
2
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 5,4

Player W, please enter coordinates separated by comma or "quit":
4,2

10
9
8
7
6
5
4                   B
3
2               W
1
X   1   2   3   4   5   6   7   8   9   10
Player W: 4,2

Player B, please enter coordinates separated by comma or "quit":
6,5

10
9
8
7
6
5                       B
4                   B
3
2               W
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 5,4; 6,5

Player W, please enter coordinates separated by comma or "quit":
4,3

10
9
8
7
6
5                       B
4                   B
3               W
2               W
1
X   1   2   3   4   5   6   7   8   9   10
Player W: 4,2; 4,3

Player B, please enter coordinates separated by comma or "quit":
7,6

10
9
8
7
6                           B
5                       B
4                   B
3               W
2               W
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 5,4; 6,5; 7,6

Player W, please enter coordinates separated by comma or "quit":
3,2

10
9
8
7
6                           B
5                       B
4                   B
3               W
2           W   W
1
X   1   2   3   4   5   6   7   8   9   10
Player W: 4,2; 4,3; 3,2

Player B, please enter coordinates separated by comma or "quit":
8,7

10
9
8
7                               B
6                           B
5                       B
4                   B
3               W
2           W   W
1
X   1   2   3   4   5   6   7   8   9   10
Player B: 5,4; 6,5; 7,6; 8,7

B won the game

C:\Users\lienz\332-oop\labs\lab4-lien-lab-four\lien-lab-four\x64\Debug>