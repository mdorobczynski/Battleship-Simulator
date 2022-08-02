/*
Martin Dorobczynski

Battleship Project
Step #3

In this program
- create the board
- create the ship class
- Initalize 5 instances of the ship class
- ships take random spots on the board
- show each ship position using the first letter of the ship name

Main.CPP
 */

#include "Battleship.h" //include header file
#include "Gameboard.h"
#include <iostream> //allows reading/writing to standard input/output stream
#include <string>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
using namespace std;

int getRandom()
{
    /* generate secret number between 1 and 10: */
    return (rand() % 10 + 1);
}

int main()
{
    //instance of the Gameboard class
    Gameboard newBoard;

    //bool variable for while loop
    bool playGame = true;

    //user input for HitOrMiss
    int UserX = 0;
    int UserY = 0;

    //tracks number of misses
    int missScore = 0;

    // initialize random seed
    srand(time(NULL));

    /*5 instances of the Battleship class initalized (b1,b2,b3,b4,b5)
    member function updateBoard called on Battleship object (b1) and passed onto gameBoard object (newBoard)
    */
    Battleship b1(2, getRandom(), getRandom(), true, "frigate");
    newBoard.updateBoard(b1);


    Battleship b2(3, getRandom(), getRandom(), false, "sub");
    //checking overlapping before updating the board
    //while loop calls overLap member function on Battleship object (b2) and passes onto gameBoard object (newBoard)
    while (newBoard.overLap(b2))
    {
        b2.setX(getRandom());   //access private member variable xPos
        b2.setY(getRandom());   //access private member variable yPos
    }
    newBoard.updateBoard(b2);

    Battleship b3(4, getRandom(), getRandom(), true, "destroyer");
    while (newBoard.overLap(b3))
    {
        b3.setX(getRandom());
        b3.setY(getRandom());
    }
    newBoard.updateBoard(b3);

    Battleship b4(4, getRandom(), getRandom(), false, "battleship");
    while (newBoard.overLap(b4))
    {
        b4.setX(getRandom());
        b4.setY(getRandom());
    }
    newBoard.updateBoard(b4);

    Battleship b5(5, getRandom(), getRandom(), true, "aircraft");
    while (newBoard.overLap(b5))
    {
        b5.setX(getRandom());
        b5.setY(getRandom());
    }
    newBoard.updateBoard(b5);

    //Game outstream statements
    cout << "EMERGENCY... ALL HANDS ON DECK.No place to run or hide soldier, the time has come." << endl << endl;

    while (playGame)        //initialized to true
    {
        int Escape = 0;        //sentinel quit command

        cout << "Press -1 now to exit the War otherwise enter an integer to ENTER THE BATTLEFIELD" << endl;
        cin >> Escape;

        if (Escape == -1)       //avaliable to user for quick game exit
        {
            cout << endl << "*Desertion* carries a maximum punishment of dishonorable discharge" << endl;

            break;  //exit while loop and game
        }

        UserX = 0;      //resetting X-value

        //legal case is between 1-10
        while ((UserX < 1) || (UserX > 10))
        {
            cout << endl << "ATTACK MODE: Please enter 1 X-value position (1-10)" << endl;
            cin >> UserX;           //user input saved
        }

        UserY = 0;       //resetting Y-value

        //legal case is between 1-10
        while ((UserY < 1) || (UserY > 10))
        {
            cout << "ATTACK MODE: Please enter 1 Y-value position (1-10)" << endl;
            cin >> UserY;           //user input saved
        }

        //after member function HitOrMiss validates, variables are passed into variable checkNum
        int checkNum = newBoard.HitOrMiss(UserX, UserY);

        //after member function checkBoard validates, true or false passed into while loop playGame
        playGame = newBoard.checkBoard();
        cout << endl;

        if (checkNum == 0)      //loop to incremement the number of misses
        {
            missScore++;            //variable incremented

            if (missScore >= 15)    //15 consecutive misses ends the game
            {
                cout << endl
                    << "GAME OVER soldier. You missed 15 consecutive attacks.  The War is lost." << endl;

                //exit loop
                playGame = false;       //loop exited
            }
        }
        else
        {
            //checknum == 1
            //hit means reset missScore
            missScore = 0;
        }
    }
    cout << endl << "GAME OVER soldier.  The War is lost." << endl
        << endl;

    newBoard.printBoard();          //output the finished battlefield

    return 0;
}