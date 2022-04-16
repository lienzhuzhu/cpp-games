// this file contains declarations for enums and functions associated with game pieces
//

#pragma once

#include <string>


enum class piece_color { NO_COLOR, INVALID_COLOR, BLACK, WHITE, RED };

std::string enumToPieceColor(piece_color p);

piece_color pieceColorToEnum(std::string s);

struct game_piece {
	game_piece();					// constructor
	piece_color colorEnumeration;
	std::string pieceName;
	std::string pieceDisplay;
};