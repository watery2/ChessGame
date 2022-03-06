#include "CheckKing.h"

int CheckIfItsPosibleToMovee(int x, int y, int color, ChessPiece* Black[16], ChessPiece* White[16])
{
	int j;

	if (color == 1)
	{
		for (j = 0; j < 16; j++)
		{
			if (x == White[j]->x && y == White[j]->y && !White[j]->dead)
			{
				return -1;
			}
			else if (x == Black[j]->x && y == Black[j]->y && !Black[j]->dead)
			{
				return j;
			}
		}
	}
	else if (color == 2)
	{
		for (j = 0; j < 16; j++)
		{
			if (x == Black[j]->x && y == Black[j]->y && !Black[j]->dead)
			{
				return -1;
			}
			else if (x == White[j]->x && y == White[j]->y && !White[j]->dead)
			{
				return j;
			}
		}
	}
	return -2;
}

int checkKing(ChessPiece& king, int color, ChessPiece* Black[16], ChessPiece* White[16])
{

	int z;

	int ij;

	int Moves;

	int x2, y2;

	int IsItOkToMoveReturnValue;

	if (color == 1)
	{
		//Pawn
		for (z = 0; z <= 7; z++)
		{
			if ((Black[z]->x - 80 == king.x && Black[z]->y + 80 == king.y && !Black[z]->dead) || (Black[z]->x + 80 == king.x && Black[z]->y + 80 == king.y && !Black[z]->dead))
			{
				return 1;
			}

		}

		//Bishop
		for (z = 8; z <= 9; z++)
		{
			Moves = abs(Black[z]->x / 80 - 7);

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 += 80;
				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 += 80;
				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			Moves = Black[z]->x / 80;

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 -= 80;
				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 -= 80;
				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}
		}

		//Rook
		for (z = 10; z <= 11; z++)
		{
			Moves = abs(Black[z]->x / 80 - 7);

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = Black[z]->x / 80;

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				x2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = abs(Black[z]->y / 80 - 7);

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = Black[z]->y / 80;

			x2 = Black[z]->x;

			y2 = Black[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (Black[z]->dead)
				{
					break;
				}

				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}
		}

		//Queen
		Moves = abs(Black[13]->x / 80 - 7);

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = Black[13]->x / 80;

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = abs(Black[13]->y / 80 - 7);

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = Black[13]->y / 80;

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = abs(Black[13]->x / 80 - 7);

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 += 80;
			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 += 80;
			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		Moves = Black[13]->x / 80;

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 -= 80;
			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		x2 = Black[13]->x;

		y2 = Black[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 -= 80;
			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 2, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		//Knight
		for (z = 14; z <= 15; z++)
		{
			if (!Black[z]->dead && ((Black[z]->x - 80 == king.x && Black[z]->y - 160 == king.y) || (Black[z]->x + 80 == king.x && Black[z]->y - 160 == king.y) || (Black[z]->x - 80 == king.x && Black[z]->y + 160 == king.y) || (Black[z]->x + 80 == king.x && Black[z]->y + 160 == king.y)))
			{
				return 1;
			}
			else if (!Black[z]->dead && ((Black[z]->x - 160 == king.x && Black[z]->y - 80 == king.y) || (Black[z]->x - 160 == king.x && Black[z]->y + 80 == king.y) || (Black[z]->x + 160 == king.x && Black[z]->y - 80 == king.y) || (Black[z]->x + 160 == king.x && Black[z]->y + 80 == king.y)))
			{
				return 1;
			}
		}

		//King
		if (!Black[12]->dead && ((Black[12]->x == king.x && Black[12]->y - 80 == king.y) || (Black[12]->x == king.x && Black[12]->y + 80 == king.y) || (Black[12]->x + 80 == king.x && Black[12]->y == king.y) || (Black[12]->x - 80 == king.x && Black[12]->y == king.y)))
		{
			return 1;
		}
		else if (!Black[12]->dead && ((Black[12]->x + 80 == king.x && Black[12]->y - 80 == king.y) || (Black[12]->x - 80 == king.x && Black[12]->y - 80 == king.y) || (Black[12]->x + 80 == king.x && Black[12]->y + 80 == king.y) || (Black[12]->x - 80 == king.x && Black[12]->y + 80 == king.y)))
		{
			return 1;
		}
	}
	else if (color == 2)
	{
		//Pawn
		for (z = 0; z <= 7; z++)
		{
			if ((White[z]->x - 80 == king.x && White[z]->y - 80 == king.y && !White[z]->dead) || (White[z]->x + 80 == king.x && White[z]->y - 80 == king.y && !White[z]->dead))
			{
				return 1;
			}

		}

		//Bishop
		for (z = 8; z <= 9; z++)
		{
			Moves = abs(White[z]->x / 80 - 7);

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 += 80;
				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 += 80;
				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			Moves = White[z]->x / 80;

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 -= 80;
				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 -= 80;
				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}
			}
		}

		//Rook
		for (z = 10; z <= 11; z++)
		{
			Moves = abs(White[z]->x / 80 - 7);

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = White[z]->x / 80;

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				x2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = abs(White[z]->y / 80 - 7);

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				y2 += 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}

			Moves = White[z]->y / 80;

			x2 = White[z]->x;

			y2 = White[z]->y;

			for (ij = 1; ij <= Moves; ij++)
			{
				if (White[z]->dead)
				{
					break;
				}

				y2 -= 80;

				IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

				if (IsItOkToMoveReturnValue != -2)
				{
					if (IsItOkToMoveReturnValue == -1)
					{
						break;
					}
					else
					{
						if (x2 == king.x && y2 == king.y)
						{
							return 1;
						}
						else
						{
							break;
						}
					}
				}

			}
		}

		//Queen
		Moves = abs(White[13]->x / 80 - 7);

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			x2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = White[13]->x / 80;

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			x2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = abs(White[13]->y / 80 - 7);

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = White[13]->y / 80;

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}

		}

		Moves = abs(White[13]->x / 80 - 7);

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			x2 += 80;
			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			x2 += 80;
			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		Moves = White[13]->x / 80;

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (Black[13]->dead)
			{
				break;
			}

			x2 -= 80;
			y2 += 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		x2 = White[13]->x;

		y2 = White[13]->y;

		for (ij = 1; ij <= Moves; ij++)
		{
			if (White[13]->dead)
			{
				break;
			}

			x2 -= 80;
			y2 -= 80;

			IsItOkToMoveReturnValue = CheckIfItsPosibleToMovee(x2, y2, 1, Black, White);

			if (IsItOkToMoveReturnValue != -2)
			{
				if (IsItOkToMoveReturnValue == -1)
				{
					break;
				}
				else
				{
					if (x2 == king.x && y2 == king.y)
					{
						return 1;
					}
					else
					{
						break;
					}
				}
			}
		}

		//Knight
		for (z = 14; z <= 15; z++)
		{
			if (!White[z]->dead && ((White[z]->x - 80 == king.x && White[z]->y - 160 == king.y) || (White[z]->x + 80 == king.x && White[z]->y - 160 == king.y) || (White[z]->x - 80 == king.x && White[z]->y + 160 == king.y) || (White[z]->x + 80 == king.x && White[z]->y + 160 == king.y)))
			{
				return 1;
			}
			else if (!White[z]->dead && ((White[z]->x - 160 == king.x && White[z]->y - 80 == king.y) || (White[z]->x - 160 == king.x && White[z]->y + 80 == king.y) || (White[z]->x + 160 == king.x && White[z]->y - 80 == king.y) || (White[z]->x + 160 == king.x && White[z]->y + 80 == king.y)))
			{
				return 1;
			}
		}

		//King
		if (!White[12]->dead && ((White[12]->x == king.x && White[12]->y - 80 == king.y) || (White[12]->x == king.x && White[12]->y + 80 == king.y) || (White[12]->x + 80 == king.x && White[12]->y == king.y) || (White[12]->x - 80 == king.x && White[12]->y == king.y)))
		{
			return 1;
		}
		else if (!White[12]->dead && ((White[12]->x + 80 == king.x && White[12]->y - 80 == king.y) || (White[12]->x - 80 == king.x && White[12]->y - 80 == king.y) || (White[12]->x + 80 == king.x && White[12]->y + 80 == king.y) || (White[12]->x - 80 == king.x && White[12]->y + 80 == king.y)))
		{
			return 1;
		}
	}

	return 0;

}
