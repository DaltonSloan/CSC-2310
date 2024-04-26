/*
	Title: Program 4
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 30 November 2023
	Purpose: 1,000 Graphs and a Keyboard.
*/
#include<iostream>
#include "markovList.h"
using namespace std;

int main()
{
	//markovMat* chain = new markovMat("corpus.txt");
	markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}