// GameBase Class declarations
//

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include "pieces-declarations.h"
#include "board-declarations.h"
#include "enums.h"
#include <iomanip>



class GameBase {

protected:
	int width;
	int height;
	int numMoves;

	std::vector<game_piece> allPieces;

	std::vector<std::string> p1Moves;
	std::vector<std::string> p2Moves;
	std::string winner;

	int longest;						// longest remembers longest display string length

public:
	GameBase();
	GameBase(int, int);
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	virtual void print() = 0;
	
	virtual void setLongest(int);		// helper method to update longest
	
	int prompt(unsigned int& x, unsigned int& y);
	int play();

	static GameBase* inputHandler(int numArgs, char** argsArr);
};

