/*Martin Dorobczynski

Battleship Project
Step #3

battleship.H

Contains class definitions & functions
*/
#ifndef Battleship_hpp
#define Battleship_hpp

#include <stdio.h>
#include <string>
using namespace std;

//Ship class
class Battleship
{
    //PUBLIC MEMBERS
public:

    //functions
    int getshipLength();    //gets ship length
    int getX();             //gets row location
    int getY();             //gets column location
    char getChar();         //gets first initial of ship string name
    bool getO();            //gets ship oreintation
    char getChoice();       //gets 
    void setX(int);         //accesses private variable
    void setY(int);         //accesses private variable

    //Overloaded Constructor
    Battleship(int, int, int, bool, string);

    //destructor
   // ~Battleship();

        //PRIVATE MEMBERS
private:

    //variables
    int shipLength;         //ship length
    int xPos;               //row location
    int yPos;               //column location
    bool oreint;            //ship oreintation
    string nameOfShip;      //name of the ship datatype string

};
#endif /* Battleship_h */
