/*Martin Dorobczynski

Battleship Project
Step #3

gameBoard.CPP

Contains the implementation of the header class
*/
#include "Gameboard.h"
#include <iostream>
using namespace std;

//****************************************************************
//  The constructor utilizes the private member variables        *                                                   
//****************************************************************
Gameboard::Gameboard()
{
    //default access to char board[][]
    row = 10; //hard coded for this Gameboard object
    col = 10;

    for (int i = 0; i < row; i++)
        //outer for loop, populates the rows
        //"i" initalized to zero
        //loop will execute as long as "i" is less than variable row
        //then "i" increments by 1
    {
        for (int j = 0; j < col; j++)
            //inner for loop, populates the columns
            //"i" initalized to zero
            //loop will execute as long as "i" is less than variable row
            //then "i" increments by 1
        {
            board[i][j] = '.';
            //By default before being replaced by specific ships,
            //     each spot on the gameboard is represented by a dot
        }
    }
}
//****************************************************************
//  The destructor                                               *                                                   
//****************************************************************
Gameboard::~Gameboard()
{
}
/**
 *      Displays a 10x10 box of characters illustrating a gameboard
 *
 *      @param array type char, row variable type int and col variable type int
 *      @ return void
 */

 //********************************************************************************
 //  printBoard populates and outputs each row and column of the Gameboard        *                                                   
 //********************************************************************************
void Gameboard::printBoard()
{
    for (int i = 0; i < row; i++)
        //outer for loop, populates the rows
        //"i" initalized to zero
        //loop will execute as long as "i" is less than variable row
        //then "i" increments by 1
    {
        for (int j = 0; j < col; j++)
            //inner loop, populates the columns
            //"i" initalized to zero
            //loop will execute as long as "i" is less than variable col
            //then "i" increments by 1
        {
            cout << board[i][j] << " ";
            //displays a space inbetween the rows & columns
            //simply for aesthics
        }
        cout << endl;
        //forces a new line after the 10th column is populated
    }
}

//****************************************************************
//  updateBoard fills the Gameboard with ships                   *                                                   
//****************************************************************
void Gameboard::updateBoard(Battleship b)
{
    //get functions called
    //values passed into object "b"
    //stored in temporary variables
    int tempLength = b.getshipLength();
    int tempX = b.getX();
    int tempY = b.getY();
    char tempChar = b.getChar();
    bool tempOreint = b.getO();

    //x represents rows
    //y represents columns

    if (tempOreint)
        //bool is "true"
        //ship will populate horizontally
    {
        tempLength = tempY + tempLength;
        //avoiding issue with for loop not executing
        //because ship length could be >= Y (column) location
        for (int i = tempY; i < tempLength; i++)
            //loop works thru columns
            //ships Y location is passed into "i"
            //loop will execute as long as "i" is less than ship length
            //then "i" increments by 1
        {
            board[tempX - 1][i - 1] = tempChar;
            //array index is filled with char variable
            //      which is the first letter of the ship string name
            //since we already determined the ship has horizontal oreintation
            //      only the y represented by "i",index is changing within the loop
        }
    }

    else
        //ship oreintation squals "false"
        //ship will populate vertically
    {
        tempLength = tempX + tempLength;
        //avoiding issue with for loop not executing
        //because ship length could be >= X (row) location
        for (int i = tempX; i < tempLength; i++)
            //loop works thru rows
            //ships X location is passed into "i"
            //loop will execute as long as "i" is less than  ship length
            //then "i" increments by 1
        {
            board[i - 1][tempY - 1] = tempChar;
            //array index is filled with char variable
            //      which is the first letter of the ship string name
            //since we already determined the ship has vertical oreintation
            //      only the x represented by "i",index is changing within the loop
        }
    }
}
//*************************************************************************
//  HitOrMiss populates the Gameboard with 'X' for hit and 'O' for miss   *                                                   
//*************************************************************************
int Gameboard::HitOrMiss(int x, int y)
{
    //retrieve value
    //then compare
    if (board[x - 1][y - 1] == '.')
    {
        //miss
        //update the board
        // negative 1 to handle the proper index 0-9 instead of 1-10
        board[x - 1][y - 1] = 'O';
        return 0;
    }
    else
    {
        //hit
        //update the board
        board[x - 1][y - 1] = 'X';

        return 1;
    }
}
//*************************************************************************
//  checkBoard validates that gameBoard contains a ship; not X,O or '.'   *                                                   
//*************************************************************************
bool Gameboard::checkBoard()
{
    //need to check entire board array for one of three variables
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //inserting variable from array into variable
            char checkVariable = board[i][j];

            //validating
            if ((checkVariable != 'X') && (checkVariable != 'O') && (checkVariable != '.'))
            {
                return true;    //passed to checkBoard
            }
        }
    }

    return false;       //passed to checkBoard
}

//*************************************************************************
//  overLap checks ships for overlapping returning true or false to Main  *                                                   
//*************************************************************************
bool Gameboard::overLap(Battleship b)
{
    //xPos == localX;
    int localX = b.getX();      //retrieve private member variable xPos
    int localY = b.getY();

    if (board[localX][localY] != '.')   //validates that current user chosen spot is NOT empty
    {
        return true;
    }
    else
    {
        return false;
    }
}