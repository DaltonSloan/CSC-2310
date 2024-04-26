/*
	Title: lab8.cpp
	Author: Dalton W. Sloan
	Date: 21 March 2023
	Purpose: Spell Book.
*/
#ifndef Spells_H
#define Spells_H

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

void getInfoFromUser(string[],int[]);
double calculateAverage(int spellDamage[]);
int findLowest(int spellDamage[]);
int findHighest(int spellDamage[]);


#endif