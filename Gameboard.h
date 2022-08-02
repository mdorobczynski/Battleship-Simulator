/*Martin Dorobczynski

Battleship Project
Step #3

gameBoard.H

Contains class definitions & functions
*/
#ifndef Gameboard_hpp
#define Gameboard_hpp
#include "Battleship.h"

class Gameboard
{
public:
	//member variables
	char board[10][10]; //official game board

	//member function
	void printBoard();
	void updateBoard(Battleship b);
	int HitOrMiss(int x, int y);
	bool checkBoard();
	bool overLap(Battleship b);

	//default constructor
	Gameboard();

	//destructor
	~Gameboard();

	//member functions

private:
	//member variables
	int row;
	int col;
};
#endif