/*
	Title: lab7.cpp
	Author: Dalton W. Sloan
	Date: 21 March 2023
	Purpose: Roommate Capability.
*/
#include <iostream>
#include <string>
#include "Lab7.h"
using namespace std;
// Function prototypes.
void getData(string& nameA, string& nameB, int& ageA, int& ageB, string& petA, string& petB);
bool calculatorResults(string& nameA,string& nameB,int,int,string,string);
// Main program.
int main()
{
// Variable declaration.
    string nameA;
    string nameB;
    int ageA;
    int ageB;
    string petA;
    string petB;
    bool cap;
    
    cout << "\n\nSuper Hero Roommate Compatibility Check" << endl;
    // Assigning function results to a variable.
    cap = calculatorResults(nameA,nameB,ageA,ageB,petA,petB);
    
    cout << "\n***** RESULTS *****" << endl;
    // if statement to determine if Roommates are compatible.
    if (cap == true)
    {
        cout << nameA << " and " << nameB << " are compatible to be roommates!" << endl;
    }
    
    else
    {
        cout << nameA << " and " << nameB << " are not compatible to be roommates." << endl;
    }
    
    return 0;
}