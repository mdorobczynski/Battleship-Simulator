/*Martin Dorobczynski

Battleship Project
Step #3

battleship.CPP

Contains the implementation of the header class
*/
#include "Battleship.h"   //include header file
#include <iostream>
using namespace std;

//****************************************************************
//  The constructor utilizes the private member variables        *                                                   
//****************************************************************
Battleship::Battleship(int ishipLength, int ixPos, int iyPos, bool ioreint, string inameOfShip)
{
    shipLength = ishipLength;
    xPos = ixPos - 1;
    yPos = iyPos - 1;
    oreint = ioreint;
    nameOfShip = inameOfShip;
}
//*****************************************************************
//  getshipLength returns the private member variable shipLength  *                                                               
//*****************************************************************
int Battleship::getshipLength()
{
    return shipLength;
}
//*****************************************************************
//  getX returns the private member variable xPos                 *                                                               
//*****************************************************************
int Battleship::getX()
{
    return xPos;
}
//*****************************************************************
//  getY returns the private member variable yPos                 *                                                               
//*****************************************************************
int Battleship::getY()
{
    return yPos;
}
//*****************************************************************
//  getChar returns the private member variable nameOfShip        *                                                               
//*****************************************************************
char Battleship::getChar()
{
    return nameOfShip[0];
    //index 1 of array
    //first character of the string name
}
//*****************************************************************
//  get0 returns the private member variable oreint               *                                                               
//*****************************************************************
bool Battleship::getO()
{
    //true represents horizontal
    return oreint;
}
//*****************************************************************
//  setX assigns the X value into variable xPos                   *                                                               
//*****************************************************************
void Battleship::setX(int X)
{
    xPos = X;
}
//*****************************************************************
//  setY assigns the Y value into variable yPos                   *                                                               
//*****************************************************************
void Battleship::setY(int Y)
{
    yPos = Y;
}