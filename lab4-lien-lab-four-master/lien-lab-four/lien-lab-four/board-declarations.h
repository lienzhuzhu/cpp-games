// this file contains declarations for functions associated with game board
//

#pragma once

#include <fstream>
#include <vector>
#include "pieces-declarations.h"



int readPieces(std::ifstream& ifs, std::vector<game_piece>& v, unsigned int w, unsigned int h);

int readDimensions(std::ifstream& ifs, unsigned int& w, unsigned int& h);

int printBoard(const std::vector<game_piece>& v, unsigned int w, unsigned int h);

