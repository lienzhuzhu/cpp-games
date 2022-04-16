// Gomoku Game definitions
//


#include "GomokuGame.h"
#include <iomanip>


using namespace std;


const string pieceRepB = "B";
const string pieceRepW = "W";


// default constructor
//
GomokuGame::GomokuGame()
	: GameBase(DEFAULT_GAME_SIZE, DEFAULT_GAME_SIZE), pieceB(pieceRepB), pieceW(pieceRepW), toWin(TOWIN_DEFAULT) {

	setLongest((int)pieceB.length());     // update longest string
	setLongest((int)pieceW.length());     // update longest string

	for (int i = 0; i < width * height; ++i) {
		allPieces.push_back(game_piece());
	}
}

// constructor taking in dimension
//
GomokuGame::GomokuGame(int dimension)
    : GameBase(dimension + 1, dimension + 1), pieceB(pieceRepB), pieceW(pieceRepW), toWin(dimension - 1) {
    // toWin is set to be one less than dimension 
    // to ensure the number needed in a row to win 
    // is less than board width
    //
    if (dimension > TOWIN_DEFAULT) {
        toWin = TOWIN_DEFAULT;
    }

    setLongest((int)pieceB.length());     // update longest string
    setLongest((int)pieceW.length());     // update longest string

    for (int i = 0; i < width * height; ++i) {
        allPieces.push_back(game_piece());
    }
}

// constructor taking in dimension and number needed to win
//
GomokuGame::GomokuGame(int dimension, int toWinParam)
    : GameBase(dimension + 1, dimension + 1), pieceB(pieceRepB), pieceW(pieceRepW), toWin(toWinParam) {
    // the number of pieces in a row to win is specified 
    // by the user and toWin takes on that value
    //
    setLongest((int)pieceB.length());     // update longest string
    setLongest((int)pieceW.length());     // update longest string

    for (int i = 0; i < width * height; ++i) {
        allPieces.push_back(game_piece());
    }
}




ostream& operator<< (ostream& o, const GomokuGame& g) {
    // send game to output
    //

    streamsize spacing = (streamsize)(3 + g.longest);

    for (int row = g.height - 1; row > 0; --row) {

        // print y axis
        //
        o << left << setw(spacing);
        o << row;

        for (int col = 1; col < g.width; ++col) {

            int index = col + g.width * row;
            o << left << setw(spacing);
            o << g.allPieces[index].pieceDisplay; 
        }

        o << endl;
    }

    o << left << setw(spacing) << "X";
    
    for (int c = 1; c < g.width; ++c) {
        o << left << setw(spacing);
        o << c;
    }
    
    return o;
}



void GomokuGame::print() {
    cout << *this << endl;
}



bool GomokuGame::done() {
    bool win = false;

    // traverse all the pieces, check for matches
    for (int row = height - 1; row > 0; --row) {
        for (int col = 1; col < width; ++col) {

            int index = col + width * row;
            string currPieceDisplay = allPieces[index].pieceDisplay;

            if (currPieceDisplay != " ") {
                // check row 
                //
                int horizontalMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (col + i < width && allPieces[ (size_t)((col + i) + width * row) ].pieceDisplay == currPieceDisplay) {
                        horizontalMatches++;
                    }
                }
                if (horizontalMatches == toWin - 1) {
                    win = true;
                }

                // vertical
                //
                int verticalMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row + i < height && allPieces[ (size_t)(col + width * (row + i)) ].pieceDisplay == currPieceDisplay) {
                        verticalMatches++;
                    }
                }
                if (verticalMatches == toWin - 1) {
                    win = true;
                }

                // y = +x diagonal
                //
                int posXMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row + i < height && col + i < width &&
                        allPieces[ (size_t)((col + i) + width * (row + i)) ].pieceDisplay == currPieceDisplay) {
                        posXMatches++;
                    }
                }
                if (posXMatches == toWin - 1) {
                    win = true;
                }

                // y = -x diagonal
                //
                int negXMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row - i > 0 && col + i < width &&
                        allPieces[ (size_t)((col + i) + width * (row - i)) ].pieceDisplay == currPieceDisplay) {
                        negXMatches++;
                    }
                }
                if (negXMatches == toWin - 1) {
                    win = true;
                }
            }
        }
    }
    if (win) {
        winner = pieceB;
        if (numMoves % 2 == 0) {    // may need to switch B and W bc of +1 adjustment
            winner = pieceW;
        }
    }
    return win;
}



bool GomokuGame::draw() {
    // check for toWin - 1 spaces in a sequence
    //
    // traverse all the pieces, check for matches
    for (int row = height - 1; row > 0; --row) {
        for (int col = 1; col < width; ++col) {

            int index = col + width * row;
            string currPieceDisplay = allPieces[index].pieceDisplay;

            if (currPieceDisplay == " ") {

                // horizontal 
                //
                int horizontalMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (col + i < width && allPieces[ (size_t)((col + i) + width * row) ].pieceDisplay == currPieceDisplay) {
                        horizontalMatches++;
                    }
                }
                if (horizontalMatches == toWin - 1) {
                    return false;
                }

                // vertical
                //
                int verticalMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row + i < height && allPieces[ (size_t)(col + width * (row + i)) ].pieceDisplay == currPieceDisplay) {
                        verticalMatches++;
                    }
                }
                if (verticalMatches == toWin - 1) {
                    return false;
                }

                // y = +x diagonal
                //
                int posXMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row + i < height && col + i < width &&
                        allPieces[ (size_t)((col + i) + width * (row + i)) ].pieceDisplay == currPieceDisplay) {
                        posXMatches++;
                    }
                }
                if (posXMatches == toWin - 1) {
                    return false;
                }

                // y = -x diagonal
                //
                int negXMatches = 0;
                for (int i = 1; i < toWin; ++i) {
                    if (row - 1 > 0 && col + i < width &&
                        allPieces[ (size_t)((col + i) + width * (row - i)) ].pieceDisplay == currPieceDisplay) {
                        negXMatches++;
                    }
                }
                if (negXMatches == toWin - 1) {
                    return false;
                }
            }
        }
    }
    return true;
}



int GomokuGame::turn() {

    bool playerB = false;
    string piece = "";
    bool moved = false;

    if (numMoves % 2 == 0) {        
        playerB = true;
        piece = pieceB;
    }
    else {
        playerB = false;
        piece = pieceW;
    }


    unsigned int x;
    unsigned int y;

    while (!moved) {

        cout << "Player " << piece << ", ";

        int prompt_result = prompt(x, y);

        if (prompt_result == quit) {
            return quit;                // echo 7
        }

        // make sure x and y are within board and make sure that spot is empty
        //
        int index = x + width * y;

        unsigned int w = width;
        unsigned int h = height;

        if (0 < x && x < w && 0 < y && y < h && allPieces[index].pieceDisplay == " ") {
            allPieces[index].pieceDisplay = piece;

            ostringstream oss;
            oss << x << "," << y;
            string move = oss.str();

            if (playerB) {
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

            if (playerB) {
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



