// TicTacToe Game Class declarations
//

#pragma once


#include "Game.h"


class TicTacToeGame : public GameBase {
private:
	std::string pieceX;
	std::string pieceO;
public:
	TicTacToeGame();
	friend std::ostream& operator<< (std::ostream&, const TicTacToeGame&);
	bool done() override;
	bool draw() override;
	int turn() override;
	void print() override;
};

std::ostream& operator<< (std::ostream&, const TicTacToeGame&);
