// definitions for TicTacToeGame Class
//


#include "TicTacToeGame.h"
//#include <iomanip>

using namespace std;



// default constructor
// calls GameBase member initialization then sets member variables in body
//
TicTacToeGame::TicTacToeGame() 
    : GameBase(5, 5), pieceX("X"), pieceO("O") {

    setLongest((int)pieceX.length());     // update longest string
    setLongest((int)pieceO.length());     // update longest 

    for (int i = 0; i < width * height; ++i) {
        allPieces.push_back(game_piece());
    }
}


ostream& operator<< (ostream& o, const TicTacToeGame& g) {
    // send game to output
    //

    streamsize spacing = (streamsize)(3 + g.longest);

    for (int row = g.height - 1; row >= 0; --row) {

        // print y axis
        //
        o << left << setw(spacing);
        o << row;

        // check if we're at the end of rows, if yes give us a new line
        //
        if (row == 0) {
            //o << setw(5);
            o << endl << left << setw(spacing) << " ";
        }

        for (int col = 0; col < g.width; ++col) {

            // if we're ready to print last line, print column numbers (x axis)
            //
            if (row == 0) {
                o << left << setw(spacing);
                o << col;
            }
            // otherwise just print the pieces
            //
            else {
                int index = col + g.width * row;
                o << left << setw(spacing);
                o << g.allPieces[index].pieceDisplay;
            }
        }
        o << endl;
    }
    return o;
}


bool TicTacToeGame::done() {

    bool win = false;

    // check horizontal
    //
    for (int i = bottomL; i <= topL; i += 5) {
        if (allPieces[i].pieceDisplay != " " &&
            allPieces[i].pieceDisplay == allPieces[i + 1].pieceDisplay &&
            allPieces[i + 1].pieceDisplay == allPieces[i + 2].pieceDisplay) {
            win = true;
        }
    }

    // check vertical
    //
    for (int i = bottomL; i <= bottomR; i += 1) {
        if (allPieces[i].pieceDisplay != " " &&
            allPieces[i].pieceDisplay == allPieces[i + 5].pieceDisplay &&
            allPieces[i + 5].pieceDisplay == allPieces[i + 10].pieceDisplay) {
            win = true;
        }
    }

    // check diagonals
    //
    int i = middle;
    if (allPieces[i].pieceDisplay != " " &&
        allPieces[i].pieceDisplay == allPieces[i + 4].pieceDisplay &&
        allPieces[i + 4].pieceDisplay == allPieces[i - 4].pieceDisplay) {
        win = true;
    }

    if (allPieces[i].pieceDisplay != " " &&
        allPieces[i].pieceDisplay == allPieces[i + 6].pieceDisplay &&
        allPieces[i + 6].pieceDisplay == allPieces[i - 6].pieceDisplay) {
        win = true;
    }

 
    if (win) {
        winner = pieceX;
        if (numMoves % 2 == 0) {    // may need to switch x and o bc of +1 adjustment
            winner = pieceO;
        }
    }
    return win;
}


bool TicTacToeGame::draw() {
    if (numMoves == TIC_TOTAL_MOVES && !done()) {
        return true;
    }
    return false;
}


int TicTacToeGame::turn() {

    bool playerX = false;
    string piece = "";
    bool moved = false;

    if (numMoves % 2 == 0) {        // potential +1 adjustment if we want O to start first still
        playerX = true;
        piece = pieceX;
    }
    else {
        playerX = false;
        piece = pieceO;
    }


    unsigned int x;
    unsigned int y;

    while (!moved) {

        cout << "Player " << piece << ", ";

        int prompt_result = prompt(x, y);

        if (prompt_result == quit) {
            return quit;                // echo 7
        }

        // make sure x and y are within 9 inner squares and make sure that spot is empty
        //
        int index = x + width * y;
        if (0 < x && x < 4 && 0 < y && y < 4 && allPieces[index].pieceDisplay == " ") {
            allPieces[index].pieceDisplay = piece;

            ostringstream oss;
            oss << x << "," << y;
            string move = oss.str();

            if (playerX) {
                p1Moves.push_back(move);
            }
            else {
                p2Moves.push_back(move);
            }

            moved = true;
            numMoves++;

            // print game status
            //
            cout << "\n" << *this << endl;

            // print coordinates of player's moves
            //
            cout << "Player " << piece << ": ";

            if (playerX) {
                for (size_t s = 0; s < p1Moves.size(); ++s) {
                    if (s > 0) {
                        cout << "; " << p1Moves[s];
                    }
                    else {
                        cout << p1Moves[s];
                    }
                }
            }
            else {
                for (size_t s = 0; s < p2Moves.size(); ++s) {
                    if (s > 0) {
                        cout << "; " << p2Moves[s];
                    }
                    else {
                        cout << p2Moves[s];
                    }
                }
            }
            cout << "\n" << endl;

            return success;
        }
    }
    return success;
}

void TicTacToeGame::print() {
    cout << *this << endl;
}







