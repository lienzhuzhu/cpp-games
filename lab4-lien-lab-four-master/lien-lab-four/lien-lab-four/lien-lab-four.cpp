// lien-lab-four.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <memory>

#include "TicTacToeGame.h"
#include "Game.h"


using namespace std;


int how_to_use(char* program_name) {
    cout << "usage: " << program_name << " GameName" << endl;
    cout << "optionally for Gomoku: " << program_name << " Gomoku <dimension> <pieces to win>" << endl;
    return wrong_number_of_arguments;       // echo 2
}

int main(int argc, char* argv[])
{
    shared_ptr<GameBase> gamePtr ( GameBase::inputHandler(argc, argv) );

    // bad_alloc is caught in inputHandler()
    //
    if (gamePtr == nullptr) {
        return how_to_use(argv[0]);
    }
    else {
        return gamePtr->play();
    }
}

void toLower(string& s) {
    int i = 0;
    string str = "";
    while (s[i]) {
        str += tolower(s[i]);
        ++i;
    }
    s = str;
}

