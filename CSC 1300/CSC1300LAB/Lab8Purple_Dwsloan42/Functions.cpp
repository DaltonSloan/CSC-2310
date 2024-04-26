/*
	Title: lab8.cpp
	Author: Dalton W. Sloan
	Date: 21 March 2023
	Purpose: Spell Book.
*/

#include <iostream>
#include <string>
#include "Spells.h"
using namespace std;

void getInfoFromUser(string spellName[], int spellDamage[])
{
    cout << "Please enter the spell(s)that you have learned." << endl;

    for(int i = 0; i < SIZE; i++)
    {
        cout << "Spell " << i + 1 << ": " << endl;
        cout << "        Enter the name of the spell: ";
        getline(cin, spellName[i]);
        cout << "        Enter the damage of the spell: ";
        cin >> spellDamage[i];
        cin.ignore();
    }
}

double calculateAverage(int spellDamage[])
{
    double sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += spellDamage[i];
    }
    return sum / SIZE;
}

int findLowest(int spellDamage[])
{
    int j = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if (spellDamage[i] < spellDamage[j])
        {
            j = i;
        }
    }
    return j;
}

int findHighest(int spellDamage[])
{
    int j = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(spellDamage[j] < spellDamage[i])
        {
            j = i;
        }
    }
    return j;
}