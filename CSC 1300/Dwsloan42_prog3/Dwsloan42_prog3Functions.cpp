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
// User input function.
void getPlayerNames(int playerNumber, string playerNames[])
{
    for (int i = 0; i < playerNumber; ++i) 
	{
		cout << "\n\nPlayer " << i + 1 << ", what is your name? ";
		getline(cin,playerNames[i]);
    }
}
// Random number generator function.
int ROLLDIE(int j, string& playerName)
{
	srand(time(0));
	int dieRoll = (rand() % 6 + 1);
	cout << "\n----------" << endl;
	cout << playerName << ", PRESS ENTER TO ROLL DIE.";
	cin.get();
	cout << "\nYOU ROLLED A " << dieRoll << endl << endl;

	switch(dieRoll) {
		case 1:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|    o    |\n";
			cout << "|         |\n";
			cout << "|_________|\n\n";
			break;
		case 2:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|  o      |\n";
			cout << "|      o  |\n";
			cout << "|_________|\n\n";
			break;
		case 3:
			cout << " _________\n";
			cout << "| o       |\n";
			cout << "|    o    |\n";
			cout << "|       o |\n";
			cout << "|_________|\n\n";
			break;
		case 4:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|         |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
		case 5:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|    o    |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
		case 6:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
			break;
}

return dieRoll;
}
// Board space events.
void ACTIVATEACTIONSPACE(int j,string playerNames[],int boardSpace[],float totalMoney[])
{
	srand(time(0));
	int goodOrBad = (rand() % 2 + 1);
	int pick = (rand() % 20 + 1);
	int money = (rand() % 100000 + 1);
	ifstream good;
	ifstream bad;
	string good2;
	string bad2;

	cout << playerNames[j] << " IS NOW ON SPACE " << boardSpace[j] << endl;

	if (goodOrBad == 1)
	{
		good.open("Good Events.txt");

		if (!good.is_open())
		{
			cout << "ERROR!";
		}
    
    cout << "( ˶ˆᗜˆ˵ )" << endl;
    cout << "GREAT!" << endl << endl;


		for (int i = 0; i < pick; i++)
		{
			getline(good,good2);
		}

    cout << good2 << " ADD $" << money << " TO YOUR ACCOUNT" << endl;
    totalMoney[j] += money;
    cout << "YOU NOW HAVE $" << totalMoney[j] << " IN YOUR ACCOUNT" << endl;
    cout << "----------" << endl;
	}


	if (goodOrBad == 2)
	{
		bad.open("Bad Events.txt");

		if (!bad.is_open())
		{
			cout << "ERROR!";
		}

    cout << "( ·•᷄∩•᷅ )" << endl;
    cout << "OH NO!" << endl << endl;

    for (int i = 0; i < pick; i++)
    {
		getline(bad,bad2);
    }

    cout << bad2 << " Pay $" << money << " FROM YOUR ACCOUNT" << endl;
    totalMoney[j] -= money;
    cout << "YOU NOW HAVE $" << totalMoney[j] << " IN YOUR ACCOUNT" << endl;
    cout << "----------" << endl;
	}

}
// Player finished function.
void PLAYERFINISHEDBOARD(int j,int playerNumber ,string playerNames[],int boardSpace[],float totalMoney[])
{
	int k = 0;
	int l = 0;

	cout << "YOU FINISHED The Game of Life!" << endl;
	cout << "----------" << endl << endl;

	for (int i = 0; i < playerNumber; i++)
    {
		if(boardSpace[j] <= boardSpace[i])
		{
			k = i;
		}

		if (totalMoney[j] < totalMoney[i])
		{
		l = i;
		}
    }

	cout << "PLAYER WHO SURVIVED The Game of Life BOARD: " << playerNames[k] << endl;
	cout << "PLAYER WHO HAS THE MOST MONEY " << playerNames[l] << ": $" << totalMoney[l] << endl << endl;
}