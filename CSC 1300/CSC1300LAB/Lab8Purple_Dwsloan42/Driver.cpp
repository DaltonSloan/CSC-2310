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



int main()
{
    string spellName[SIZE];
    int spellDamage[SIZE];
    double averageSpellDamage;
    int highestSpellDamage;
    int lowestSpellDamage;


    cout << "Welcome to the Hogwarts School of Witchcraft and Wizardry." << endl;
    cout << "This is the Hogwarts Spell Evaluation program." << endl;
    
    getInfoFromUser(spellName,spellDamage);

    averageSpellDamage = calculateAverage(spellDamage);

    lowestSpellDamage = findLowest(spellDamage);

    highestSpellDamage = findHighest(spellDamage);

    
    cout << "\n-----------------------------------------------------------------" << endl;
    cout <<"The average amount of effect of spells: " << averageSpellDamage << endl;
    cout << "The spell with the lowest amount of effect is "<< spellName[lowestSpellDamage] <<" with value of " << spellDamage[lowestSpellDamage] << "." << endl;
    cout << "The spell with the highest amount of effect is " << spellName[highestSpellDamage] <<" with value of "<< spellDamage[highestSpellDamage] << "." << endl;


    return 0;
}