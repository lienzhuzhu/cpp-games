// Game Base class definitions
//


#include "Game.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"

#include <memory>



using namespace std;


GameBase::GameBase() 
    : width(DEFAULT_GAME_SIZE), height(DEFAULT_GAME_SIZE), numMoves(0), longest(1) {}


GameBase::GameBase(int w, int h)
    : width(w), height(h), numMoves(0), longest(1) {}

void GameBase::setLongest(int stringLength) {
	if (longest < stringLength) {
		longest = stringLength;
	}
}

// prompt user to input comma separated pair of ints, or "quit"
// if "quit" is entered return value to indicate quit
//
int GameBase::prompt(unsigned int& x, unsigned int& y) {

    bool keep_going = true;

    while (keep_going) {
        cout << "please enter coordinates separated by comma or \"quit\":" << endl;

        // fill string input with whatever user enters until space is hit
        //
        string input;
        cin >> input;

        string test;
        getline(cin, test);


        // as long as no spaces were entered, the rest of logic is executed
        //
        if (test.empty()) {                                             // string.empty() found on cplusplus.com                               

            if (input == "quit") {
                keep_going = false;
                return quit;        // echo 7
            }
            else {
                replace(input.begin(), input.end(), ',', ' ');

                istringstream iss(input);
                string dummy;                                            // dummy holds a third entry if the user gave a bad input
                if (iss >> x && iss >> y && !(iss >> dummy)) {           // check for successful extraction into x and y
                    keep_going = false;
                    return success;
                }
                else {
                    keep_going = true;
                }
            }
        }
    }
    return success;
}

int GameBase::play() {

	print();

    bool won = false;
    bool tie = false;
    int turnCall = success;

    while (!won && !tie && turnCall != quit) {
        turnCall = turn();
        tie = draw();
        won = done();

        if (won) {
            cout << winner << " won the game" << endl;
            return success;
        }

        if (tie) {
            cout << "The game is a tie, " << numMoves << " moves were made" << endl;
            return TIE;
        }

        if (turnCall == quit) {
            cout << "The game was quit, " << numMoves << " moves were made" << endl;
            return quit;
        }
    }
    return success;
}

GameBase* GameBase::inputHandler(int numArgs, char** argsArr) {
    if (numArgs == NUM_INPUTS) {
        if ((string)argsArr[1] == "TicTacToe") {
            try {
                return new TicTacToeGame;
            }
            catch (std::bad_alloc& ba) {
                std::cerr << "Caught bad alloc: " << ba.what() << "\n";
                return nullptr;
            }
        }
        if ((string)argsArr[1] == "Gomoku") {
            return new GomokuGame;
        }
    }

    if (numArgs == DIMENSION_GIVEN && (string)argsArr[1] == "Gomoku") {
        int dim = DEFAULT_GAME_SIZE;

        istringstream iss(argsArr[2]);
        if (iss >> dim) {
            try {
                if (dim > 2) {
                    return new GomokuGame(dim);
                }
            }
            catch (std::bad_alloc& ba) {
                std::cerr << "Caught bad alloc: " << ba.what() << "\n";
                return nullptr;
            }
        }
    }

    if (numArgs == TOWIN_GIVEN && (string)argsArr[1] == "Gomoku") {
        int dim = DEFAULT_GAME_SIZE;
        int toWin = TOWIN_DEFAULT;
        istringstream issDim(argsArr[2]);
        istringstream issWin(argsArr[3]);
        if (issDim >> dim && issWin >> toWin) {
            try {
                if (dim > 2 && toWin < dim) {
                    return new GomokuGame(dim, toWin);
                }
            }
            catch (std::bad_alloc& ba) {
                std::cerr << "Caught bad alloc: " << ba.what() << "\n";
                return nullptr;
            }
        }
    }
    
    return nullptr;
}

