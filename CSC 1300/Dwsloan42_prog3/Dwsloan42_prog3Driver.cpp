/*
	Title: Program 3.cpp
	Author: Dalton W. Sloan
	Date: 5 April 2023
	Purpose: The Game of Like.
*/
#include "Dwsloan42_prog3.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Main function.
int main()
{
  // Variable bank.
    char pick1;
    int menuChoice = 0;;
    int playerNumber;
    int dieRoll = 0;
    string playerNames[maxPlayers];
    float totalMoney[maxPlayers];
    int boardSpace[maxPlayers];
    
    // A loop for menu options.
    do
        {
            cout << "\n\nWelcome to the The Game of Life!" << endl;
            cout << "How many Players?: ";
            cin >> playerNumber;
            cin.ignore();
            // Clearing the arrays.
            for (int i=0;i<playerNumber;i++)
            {
                playerNames[i] = "";
                totalMoney[i] = 0.00;
                boardSpace[i] = 0;
            }
            // Call to user input function.
            getPlayerNames(playerNumber, playerNames);

            while (playerNumber > maxPlayers || playerNumber <= 0)
            {
                cout << "\nERROR! Please enter the number of players between 1 and 20: ";
                cin >> playerNumber;
            }
            // A loop to iterate through the board.
            for (int i = 0; i < boardSize; i++) 
            {
                // a loop to iterate through players.
                for (int j = 0; j < playerNumber; j++)
                {
                    if (boardSpace[j] >= boardSize)
                    {
                        break;
                    }
                string playerName = playerNames[j];
                // Assigning return value of the function to a variable.
                boardSpace[j] += ROLLDIE(j,playerName);

                if (boardSpace[j] >= boardSize)
                {
                    // Call to player finish function.
                    PLAYERFINISHEDBOARD(j,playerNumber,playerNames,boardSpace,totalMoney);
                    break;
                }

                else
                {
                    // Call to board space events function.
                    ACTIVATEACTIONSPACE(j,playerNames,boardSpace,totalMoney);
                }
                }
            }
        // Menu to continue the loop or not.
        cout << "Do you want to play again?\nY or N:";
        cin >> pick1;
        menuChoice = pick1;

    } while (menuChoice == 89 || menuChoice == 121);
    return 0;
}