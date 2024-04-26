/*
	Title: Program 3.cpp
	Author: Dalton W. Sloan
	Date: 5 April 2023
	Purpose: The Game of Like.
*/
#ifndef Dwsloan42_prog3
#define Dwsloan42_prog3

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Variable constants.
const int maxPlayers = 20;
const int boardSize = 25;
// Function bank.
void getPlayerNames(int,string[]);
int ROLLDIE(int,string&);
void ACTIVATEACTIONSPACE(int,string[],int[],float[]);
void PLAYERFINISHEDBOARD(int,int,string[],int[],float[]);



#endif