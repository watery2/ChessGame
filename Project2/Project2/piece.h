#pragma once
#include <string>

class ChessPiece
{
	public:
		bool selected = false;

		bool dead = false;

		int x;

		int y;

		// for the king
		bool NotInDanger = true;

		// this is for the pawns
		int moves = 0;

		bool changing;

		std::string type;
		////////////////////////

		ChessPiece(int p_x, int p_y);











};

