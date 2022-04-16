// this file includes definitions related to game board
//

#include "board-declarations.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "enums.h"


using namespace std;


// this function reads the dimensions of a game board from the first line of an input file
//
int readDimensions(ifstream& ifs, unsigned int& w, unsigned int& h) {

	string first_line;
	if (!getline(ifs, first_line)) {
		return file_line_could_not_be_read; // enum from enums.h
	}
	istringstream iss(first_line);
	if (!(iss >> w) || !(iss >> h)) {
		return dimension_not_read;			// enum from enums.h
	}

	return success;
}


// this function reads the game pieces from an input file
//
int readPieces(ifstream& ifs, vector<game_piece>& v, unsigned int w, unsigned int h) {

	string line;

	string color;
	string name_of_piece;
	string displayed_piece;
	unsigned int xPos;
	unsigned int yPos;

	bool unsuccessful = true;

	while (getline(ifs, line)) {				
		
		istringstream iss(line);
		
		if (iss >> color >> name_of_piece >> displayed_piece >> xPos >> yPos) {
			
			piece_color pc = pieceColorToEnum(color);

			if (pc != piece_color::INVALID_COLOR && xPos <= w && yPos <= h) {
				unsuccessful = false;
				int index = w * yPos + xPos;

				game_piece g = v[index];

				g.colorEnumeration = pc;				
				g.pieceName = name_of_piece;
				g.pieceDisplay = displayed_piece;

				v[index] = g;
			}
		}
	}

	if (unsuccessful) {
		return no_well_formed_pieces;					// in enums.h, echo 5
	}
	return success;										// in enums.h
}


// this function prints game pieces on a game board
//
int printBoard(const vector<game_piece>& v, unsigned int w, unsigned int h) {

	size_t v_size = v.size();

	int last_index = w * (h - 1) + (w - 1);					// h-1 and w-1 are the max y and x coordinates

	if (v_size - 1 != last_index) {
		return vector_dimensions_do_not_fit;				// echo 6
	}

	int height = h;
	int width = w;

	for (int h_inc = height - 1; h_inc >= 0; --h_inc) {
		
		cout << " | ";

		for (int w_inc = 0; w_inc < width; ++w_inc) {
			int index = w * h_inc + w_inc;
			game_piece g = v[index];
			cout << g.pieceDisplay << " | ";
		}

		cout << endl;
	}

	return success;
}