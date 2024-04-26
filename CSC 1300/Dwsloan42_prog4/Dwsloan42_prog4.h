/*
	Title: Program 4.cpp
	Author: Dalton W. Sloan
	Date: 24 April 2023
	Purpose: Monster Zoo.
*/
#ifndef Dwsloan42_prog4
#define Dwsloan42_prog4

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
// Struct definitions.
struct Cost
{
    float hours;
    float careCost;
    float foodCost;
    float matsCost;
};

struct Monsters
{
    string name;
    string description;
    double weight;
    float height;
    string location;
    int dangerLevel;
    Cost m;
};
// Function prototypes.
int loadMonstersFromFile(int, Monsters[]);
int registerMonster(int, Monsters[]);
int removeMonster(int, Monsters[]);
void printMonsters(int, Monsters*);
void printCostInfo(int, Monsters[]);
void saveMonstersToFile(int, Monsters*);
#endif