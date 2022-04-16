// this file contains definitions related to game pieces
//

#include "pieces-declarations.h"


using namespace std;


// game piece constructor definition
//
game_piece::game_piece()
	: colorEnumeration(piece_color::NO_COLOR), pieceName(""), pieceDisplay(" ") {}		


// converts piece enum to name of the piece in string form
//
string enumToPieceColor(piece_color p) {

	if (p == piece_color::BLACK) {
		return "black";
	}
	if (p == piece_color::WHITE) {
		return "white";
	}
	if (p == piece_color::RED) {
		return "red";
	}
	if (p == piece_color::INVALID_COLOR) {
		return "invalid_color";
	}
	if (p == piece_color::NO_COLOR) {
		return "no_color";
	}
	else {
		return "";
	}
}


// converts the color of a piece to the corresponding enum
//
piece_color pieceColorToEnum(string s) {
	if (s == "black") {
		return piece_color::BLACK;
	}
	else if (s == "white") {
		return piece_color::WHITE;
	}
	else if (s == "red") {
		return piece_color::RED;
	}
	else if (s == "") { 
		return piece_color::NO_COLOR;
	}
	else {
		return piece_color::INVALID_COLOR;
	}
}
