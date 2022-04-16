// This file contains declarations for relevant enumerations and common functions
//

#pragma once

#include <string>


enum indices { prog_name, input_file_name };

enum params { NUM_INPUTS = 2, DIMENSION_GIVEN = 3, TOWIN_GIVEN = 4 };

enum return_values { 
	success, file_could_not_be_opened, wrong_number_of_arguments, file_line_could_not_be_read, dimension_not_read, 
	no_well_formed_pieces, vector_dimensions_do_not_fit, quit
};

enum corners { bottomL = 6, bottomR = 8, middle = 12, topL = 16, topR = 18 };

enum tictactoe { TIC_TOTAL_MOVES = 9, TIE = 10 };

enum gomoku { NEIGHBOR = 1, TWO_OVER = 2, DEFAULT_GAME_SIZE = 20, TOWIN_DEFAULT = 5 };

void toLower(std::string& s);

