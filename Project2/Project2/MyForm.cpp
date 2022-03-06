#include "MyForm.h"
#include "CheckKing.h"

// Doing this Project i learned a lot. If i whould do this project again i would do it very differently.

using namespace System;
using namespace System::Windows::Forms;

int GetMoX(System::EventArgs^  e)
{
	MouseEventArgs^ me = (MouseEventArgs^)e;
	return me->Location.X;
}

int GetMoY(System::EventArgs^  e)
{
	MouseEventArgs^ me = (MouseEventArgs^)e;
	return me->Location.Y;
}

int j;

// -1 - for frendly j - for enemy
int CheckIfItsPosibleToMove(int x, int y, int color)
{
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
                                   
int CheckIfPosibleToKill(int x, int y, int disx, int disy,  int color, int num)
{
	
	if (color == 1)
	{
		if ((abs(x / 80 - Black[num]->x / 80) == disx) && (abs(y / 80 - Black[num]->y / 80) == disy))
		{
			take_color = color;

			take = true;

			take_num = num;

			return 1;
		}
	}
	else if (color == 2)
	{
		if ((abs(x / 80 - White[num]->x / 80) == disx) && (abs(y / 80 - White[num]->y / 80) == disy))
		{
			take_color = color;

			take = true;

			take_num = num;

			return 1;
		}
	}

	return 0;
}

void ChangeTurn()
{
	if (turn == 1)
	{
		turn++;
	}
	else
	{
		turn--;
	}
}

int CheckKing(ChessPiece& king, int color)
{
	return checkKing(king, color, Black, White);
}

void MoveBishop(System::Windows::Forms::PictureBox^ Bishop, int GetMoX, int GetMoY, ChessPiece& bishop, int color)
{
	int y;

	int x;

	int dis;

	int newx;

	int newy;

	bool isitoktomove = true;

	int isitoktomove_num;

	int i;

	x = Bishop->Location.X;
	y = Bishop->Location.Y;

	if (bishop.selected)
	{

		if (x < GetMoX && y > GetMoY)
		{

			isitoktomove = true;

			dis = GetMoX / 80 - x / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{									// using abs() here so i can just copy and paste it
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}

			}

			if ((y / 80 - GetMoY / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}
		else if (x > GetMoX && y > GetMoY)
		{

			isitoktomove = true;

			dis = x / 80 - GetMoX / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((y / 80 - GetMoY / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{
				x = newx;
				y = newy;

				ChangeTurn();

			}
		}
		else if (x < GetMoX && y < GetMoY)
		{

			isitoktomove = true;

			dis = GetMoX / 80 - x / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((GetMoY / 80 - y / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{
				x = newx;
				y = newy;

				ChangeTurn();

			}
		}

		else if (x > GetMoX && y < GetMoY)
		{

			isitoktomove = true;

			dis = x / 80 - GetMoX / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((GetMoY / 80 - y / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}

		isitoktomove = true;

		bishop.selected = false;

		bishop.x = x;

		bishop.y = y;

		Bishop->BorderStyle = BorderStyle::None;

		Bishop->Location = System::Drawing::Point(x, y);
	}

	
}

void MovePawn(System::Windows::Forms::PictureBox^ Pawn, int GetMoX, int GetMoY, ChessPiece& pawn, int color, int number, System::Windows::Forms::PictureBox^ C_Queen, System::Windows::Forms::PictureBox^ C_Bishop, System::Windows::Forms::PictureBox^ C_Knight, System::Windows::Forms::PictureBox^ C_Rook)
{
	int y;

	int x;

	int dis;

	int newx;

	int newy;

	bool isitoktomove = true;

	int isitoktomove_num;

	int i;

	x = Pawn->Location.X;
	y = Pawn->Location.Y;

	if (pawn.selected)
	{
		if (y > GetMoY && (x < GetMoX && (x + 50) > GetMoX) && pawn.type == "pawn" && color == 1)
		{
			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newy -= 80;

				if (CheckIfItsPosibleToMove(newx, newy, color) != -2)
				{
					isitoktomove = false;
					break;
				}

			}

			if (dis == 2 && pawn.moves == 0 && isitoktomove)
			{

				y = newy;

				pawn.moves++;

				ChangeTurn();

			}
			else if (dis == 1 && isitoktomove)
			{
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}

		}
		else if (x < GetMoX && y > GetMoY && pawn.type == "pawn" && color == 1)
		{
			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			isitoktomove_num = CheckIfItsPosibleToMove(newx + 80, newy - 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, GetMoX / 80 - x / 80, y / 80 - GetMoY / 80, color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
					else
					{
						newx += 80;
						newy -= 80;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}
			else
			{
				isitoktomove = false;
			}

			if (dis == 1 && isitoktomove)
			{
				x = newx;
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}


		}
		else if (x > GetMoX && y > GetMoY && pawn.type == "pawn" && color == 1)
		{
			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			isitoktomove_num = CheckIfItsPosibleToMove(newx - 80, newy - 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, x / 80 - GetMoX / 80, y / 80 - GetMoY / 80, color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
					else
					{
						newx -= 80;
						newy -= 80;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}
			else
			{
				isitoktomove = false;
			}

			if (dis == 1 && isitoktomove)
			{
				x = newx;
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}


		}
		else if (y < GetMoY && (x < GetMoX && (x + 50) > GetMoX) && pawn.type == "pawn" && color == 2)
		{

			isitoktomove = true;

			dis = GetMoY / 80 - y / 80 ;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newy += 80;

				if (CheckIfItsPosibleToMove(newx, newy, color) != -2)
				{
					isitoktomove = false;
					break;
				}

			}

			if (dis == 2 && pawn.moves == 0 && isitoktomove)
			{

				y = newy;

				pawn.moves++;

				ChangeTurn();

			}
			else if (dis == 1 && isitoktomove)
			{
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}

		}
		else if (x < GetMoX && y < GetMoY && pawn.type == "pawn" && color == 2)
		{

			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			isitoktomove_num = CheckIfItsPosibleToMove(newx + 80, newy + 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, GetMoX / 80 - x / 80,GetMoY / 80 - y / 80, color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
					else
					{
						newx += 80;
						newy += 80;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}
			else
			{
				isitoktomove = false;
			}

			if (dis < 2 && isitoktomove)
			{
				x = newx;
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}


		}
		else if (x > GetMoX && y < GetMoY && pawn.type == "pawn" && color == 2)
		{

			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			isitoktomove_num = CheckIfItsPosibleToMove(newx - 80, newy + 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, x / 80 - GetMoX / 80, GetMoY / 80 - y / 80, color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
					else
					{
						newx -= 80;
						newy += 80;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}
			else
			{
				isitoktomove = false;
			}

			if (dis < 2 && isitoktomove)
			{
				x = newx;
				y = newy;

				if (pawn.moves == 0)
				{
					pawn.moves++;

				}

				ChangeTurn();
			}


		}
		else if (pawn.type == "queen")
		{
			MoveQueen(Pawn, GetMoX, GetMoY, pawn, color);
		}
		else if (pawn.type == "bishop")
		{
			MoveBishop(Pawn, GetMoX, GetMoY, pawn, color);
		}
		else if (pawn.type == "knight")
		{
			MoveKnight(Pawn, GetMoX, GetMoY, pawn, color);
		}
		else if (pawn.type == "rook")
		{
			MoveRook(Pawn, GetMoX, GetMoY, pawn, color);
		}
		// brings the pieces that change the pawn
		if (color == 1 && pawn.type == "pawn" && y == 10)
		{
			paused = true;

			PawnBeingPromoted = number;

			PawnBeingPromotedColor = color;

			C_Queen->Image = System::Drawing::Image::FromFile("img/Chess_qlt60.png");
			C_Queen->Location = System::Drawing::Point(x, y + 80);

			C_Bishop->Image = System::Drawing::Image::FromFile("img/Chess_blt60.png");
			C_Bishop->Location = System::Drawing::Point(x, y + 160);

			C_Knight->Image = System::Drawing::Image::FromFile("img/Chess_nlt60.png");
			C_Knight->Location = System::Drawing::Point(x, y + 240);

			C_Rook->Image = System::Drawing::Image::FromFile("img/Chess_rlt60.png");
			C_Rook->Location = System::Drawing::Point(x, y + 320);
		}
		else if (color == 2 && pawn.type == "pawn" && y == 570)
		{
			paused = true;

			PawnBeingPromoted = number;

			PawnBeingPromotedColor = color;

			C_Queen->Image = System::Drawing::Image::FromFile("img/Chess_qdt60.png");
			C_Queen->Location = System::Drawing::Point(x, y - 80);

			C_Bishop->Image = System::Drawing::Image::FromFile("img/Chess_bdt60.png");
			C_Bishop->Location = System::Drawing::Point(x, y - 160);

			C_Knight->Image = System::Drawing::Image::FromFile("img/Chess_ndt60.png");
			C_Knight->Location = System::Drawing::Point(x, y - 240);

			C_Rook->Image = System::Drawing::Image::FromFile("img/Chess_rdt60.png");
			C_Rook->Location = System::Drawing::Point(x, y - 320);
		}

		if (pawn.type == "pawn")
		{
			isitoktomove = true;

			pawn.selected = false;

			pawn.y = y;
			pawn.x = x;

			Pawn->BorderStyle = BorderStyle::None;

			Pawn->Location = System::Drawing::Point(x, y);
		}

	}
}

void MoveKnight(System::Windows::Forms::PictureBox^ Knight, int GetMoX, int GetMoY, ChessPiece& knight, int color)
{
	int y;

	int x;

	int newx;

	int newy;

	bool isitoktomove = true;

	int isitoktomove_num;

	x = Knight->Location.X;
	y = Knight->Location.Y;

	newx = x;
	newy = y;

	if (knight.selected)
	{
		if (x > GetMoX && y > GetMoY)
		{
			if (y / 80 - GetMoY / 80 == 2 && x / 80 - GetMoX / 80 == 1)
			{

				newx -= 80;
				newy -= 160;

			}
			else if (x / 80 - GetMoX / 80 == 2 && y / 80 - GetMoY / 80 == 1)
			{

				newx -= 160;
				newy -= 80;

			}
		}
		else if (x < GetMoX && y > GetMoY)
		{
			if (y / 80 - GetMoY / 80 == 2 && GetMoX / 80 - x / 80  == 1)
			{

				newx += 80;
				newy -= 160;

			}
			else if (GetMoX / 80 - x / 80 == 2 && y / 80 - GetMoY / 80 == 1)
			{

				newx += 160;
				newy -= 80;

			}
			
		}
		else if (x > GetMoX && y < GetMoY)
		{
			if (GetMoY / 80 - y / 80 == 2 && x / 80 - GetMoX / 80 == 1)
			{

				newx -= 80;
				newy += 160;

			}
			else if (x / 80 - GetMoX / 80 == 2 && GetMoY / 80 - y / 80 == 1)
			{

				newx -= 160;
				newy += 80;

			}
		}
		else if (x < GetMoX && y < GetMoY)
		{
			if (GetMoY / 80 - y / 80 == 2 && GetMoX / 80 - x / 80  == 1)
			{
				newx += 80;
				newy += 160;

			}
			else if (GetMoX / 80 - x / 80 == 2 && GetMoY / 80 - y / 80 == 1)
			{

				newx += 160;
				newy += 80;

			}
		}

		if (x != newx && y != newy)
		{

			isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}
			if (isitoktomove)
			{
				x = newx;
				y = newy;

				ChangeTurn();
			}
			
		}


		isitoktomove = true;

		knight.x = x;
		knight.y = y;

		knight.selected = false;

		Knight->BorderStyle = BorderStyle::None;

		Knight->Location = System::Drawing::Point(x, y);
	}
}

void MoveQueen(System::Windows::Forms::PictureBox^ Queen, int GetMoX, int GetMoY, ChessPiece& queen, int color)
{
	int y;

	int x;

	int dis;

	int newx;

	int newy;

	bool isitoktomove = true;

	int isitoktomove_num;

	int i;

	x = Queen->Location.X;
	y = Queen->Location.Y;

	if (queen.selected)
	{

		if (y / 80 - GetMoY / 80 == 0 && (y <= GetMoY && y + 50 >= GetMoY) && x < GetMoX)
		{

			isitoktomove = true;

			dis = GetMoX / 80 - x / 80;

			newy = y;
			newx = x;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && x != newx)
			{
				x = newx;

				ChangeTurn();
			}
		}
		else if (y / 80 - GetMoY / 80 == 0 && (y <= GetMoY && y + 50 >= GetMoY) && x > GetMoX)
		{

			isitoktomove = true;

			dis = x / 80 - GetMoX / 80;

			newy = y;
			newx = x;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && x != newx)
			{
				x = newx;

				ChangeTurn();
			}
		}
		else if (x / 80 - GetMoX / 80 == 0 && (x <= GetMoX && x + 50 >= GetMoX) && y > GetMoY)
		{

			isitoktomove = true;

			dis = y / 80 - GetMoY / 80;

			newy = y;
			newx = x;

			for (i = 1; i <= dis; i++)
			{
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && y != newy)
			{
				y = newy;

				ChangeTurn();
			}
		}
		else if (x / 80 - GetMoX / 80 == 0 && (x <= GetMoX && x + 50 >= GetMoX) && y < GetMoY)
		{

			isitoktomove = true;

			dis = GetMoY / 80 - y / 80;

			newy = y;
			newx = x;

			for (i = 1; i <= dis; i++)
			{
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && y != newy)
			{
				y = newy;

				ChangeTurn();
			}
		}
		else if (x < GetMoX && y > GetMoY)
		{

			isitoktomove = true;

			dis = GetMoX / 80 - x / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((y / 80 - GetMoY / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}
		else if (x > GetMoX && y > GetMoY)
		{

			isitoktomove = true;

			dis = x / 80 - GetMoX / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((y / 80 - GetMoY / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}
		else if (x < GetMoX && y < GetMoY)
		{
			
			isitoktomove = true;
			
			dis = GetMoX / 80 - x / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}

			}

			if ((GetMoY / 80 - y / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}
		else if (x > GetMoX && y < GetMoY)
		{

			isitoktomove = true;

			dis = x / 80 - GetMoX / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if ((GetMoY / 80 - y / 80 == dis) && isitoktomove && (x != newx && y != newy))
			{

				x = newx;
				y = newy;

				ChangeTurn();

			}
		}

		isitoktomove = true;

		queen.selected = false;

		queen.x = x;

		queen.y = y;

		Queen->BorderStyle = BorderStyle::None;

		Queen->Location = System::Drawing::Point(x, y);
		
	}
}

void MoveRook(System::Windows::Forms::PictureBox^ Rook, int GetMoX, int GetMoY, ChessPiece& rook, int color)
{
	int y;

	int x;

	int dis;

	int newx;

	int newy;

	bool isitoktomove = true;

	int isitoktomove_num;

	int i;

	x = Rook->Location.X;
	y = Rook->Location.Y;

	if (rook.selected)
	{
		if (y >= GetMoY && (x <= GetMoX && x + 50 >= GetMoX))
		{
			dis = y / 80 - GetMoY / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newy -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && y != newy) 
			{
				y = newy;

				ChangeTurn();
			}
		}
		else if (y <= GetMoY && (x <= GetMoX && x + 50 >= GetMoX))
		{
			dis = GetMoY / 80 - y / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newy += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && y != newy)
			{
				y = newy;

				ChangeTurn();
			}
		}
		else if (x >= GetMoX && (y <= GetMoY && y + 50 >= GetMoY))
		{
			dis = x / 80 - GetMoX / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx -= 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && x != newx)
			{
				x = newx;

				ChangeTurn();
			}
		}
		else if (x <= GetMoX && (y <= GetMoY && y + 50 >= GetMoY))
		{
			dis = GetMoX / 80 - x / 80;
			newx = x;
			newy = y;

			for (i = 1; i <= dis; i++)
			{
				newx += 80;

				isitoktomove_num = CheckIfItsPosibleToMove(newx, newy, color);

				if (isitoktomove_num != -2)
				{
					if (isitoktomove_num != -1)
					{
						if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
						{
							isitoktomove = false;
							break;
						}
					}
					else
					{
						isitoktomove = false;
						break;
					}
				}
			}

			if (isitoktomove && x != newx)
			{
				x = newx;

				ChangeTurn();
			}
		}

		isitoktomove = true;

		rook.selected = false;

		rook.x = x;

		rook.y = y;

		Rook->BorderStyle = BorderStyle::None;

		Rook->Location = System::Drawing::Point(x, y);
		
	}
	
}

void MoveKing(System::Windows::Forms::PictureBox^ King, int GetMoX, int GetMoY, ChessPiece& king, int color)
{
	int y;

	int x;

	bool isitoktomove = true;

	int isitoktomove_num;

	x = King->Location.X;
	y = King->Location.Y;

	isitoktomove = true;

	if (king.selected)
	{
		if (x <= GetMoX && y >= GetMoY && y / 80 - GetMoY / 80 == 1 && GetMoX / 80 - x / 80 == 1)
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x + 80, y - 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x += 80;
				y -= 80;

				ChangeTurn();
			}
		}
		else if (x >= GetMoX && y >= GetMoY && y / 80 - GetMoY / 80 == 1 && x / 80 - GetMoX / 80 == 1)
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x - 80, y - 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x -= 80;
				y -= 80;

				ChangeTurn();
			}
		}
		else if (y >= GetMoY && y / 80 - GetMoY / 80 == 1 && (x <= GetMoX && x + 50 >= GetMoX))
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x, y - 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				y -= 80;

				ChangeTurn();
			}
		}
		else if (x >= GetMoX && x / 80 - GetMoX / 80 == 1 && (y <= GetMoY && y + 50 >= GetMoY))
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x - 80, y, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x -= 80;

				ChangeTurn();
			}
		}
		else if (x <= GetMoX && GetMoX / 80 - x / 80 == 1 && (y <= GetMoY && y + 50 >= GetMoY))
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x + 80, y, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x += 80;

				ChangeTurn();
			}
		}
		else if (x >= GetMoX && y <= GetMoY && GetMoY / 80 - y / 80  == 1 && x / 80 - GetMoX / 80 == 1)
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x - 80, y + 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x -= 80;
				y += 80;

				ChangeTurn();
			}
		}
		else if (x <= GetMoX && y <= GetMoY && GetMoY / 80 - y / 80 == 1 && GetMoX / 80 - x / 80  == 1)
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x + 80, y + 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				x += 80;
				y += 80;

				ChangeTurn();
			}
		}
		else if (y <= GetMoY && GetMoY / 80 - y / 80 == 1 && (x <= GetMoX && x + 50 >= GetMoX))
		{
			isitoktomove_num = CheckIfItsPosibleToMove(x, y + 80, color);

			if (isitoktomove_num != -2)
			{
				if (isitoktomove_num != -1)
				{
					if (CheckIfPosibleToKill(x, y, abs(GetMoX / 80 - x / 80), abs(y / 80 - GetMoY / 80), color, isitoktomove_num) == 0)
					{
						isitoktomove = false;
					}
				}
				else
				{
					isitoktomove = false;
				}
			}

			if (isitoktomove)
			{
				y += 80;

				ChangeTurn();
			}
		}

		isitoktomove = true;

		king.selected = false;

		king.x = x;

		king.y = y;

		King->BorderStyle = BorderStyle::None;

		King->Location = System::Drawing::Point(x, y);
	}
}

[STAThreadAttribute]
void Main(cli::array<String^>^ args)
{
	turn = 1;

	take_color = 0;

	take = false;

	take_num = -1;

	Promotions[0] = { "queen" };
	Promotions[1] = { "bishop" };
	Promotions[2] = { "knight" };
	Promotions[3] = { "rook" };

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);


}

