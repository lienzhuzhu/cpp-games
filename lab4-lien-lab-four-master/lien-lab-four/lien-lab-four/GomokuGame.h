// GomokuGame Class declarations
//

#pragma once

#include "Game.h"


class GomokuGame : public GameBase {
private:
	std::string pieceB;
	std::string pieceW;
	int toWin; // toWin sets the number of loops to go over when checking for wins, draws
	
public:
	GomokuGame();
	GomokuGame(int);
	GomokuGame(int, int);
	friend std::ostream& operator<< (std::ostream&, const GomokuGame&);
	bool done() override;
	bool draw() override;
	int turn() override;
	void print() override;
};

std::ostream& operator<< (std::ostream&, const GomokuGame&);