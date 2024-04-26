/*
	Title: lab7.cpp
	Author: Dalton W. Sloan
	Date: 21 March 2023
	Purpose: Roommate Capability.
*/
#include "Lab7.h"
#include <iostream>
#include <string>
using namespace std;
// Void function prototype.
void getData(string& name_1, string& name_2, int& age_1, int& age_2, string& petA, string& petB);

// Bool calculator function.
bool calculatorResults(string& nameA,string& nameB,int,int,string,string)
{
// Variable declaration.
    int ageA;
    int ageB;
    string petA;
    string petB;
// Get data from user.
    getData(nameA,nameB,ageA,ageB,petA,petB);
// variable declaration continued.
    int t = 0;
    int total;
    int total2 = 0;
    int total3 = 0;
    int totalAge;


// Setting i to length of nameA.
    int x = nameA.length();
// Adding ASCII value of each character of nameA to total2.
    for (int i = 0; i < x; i++) 
    {
        total2 += nameA[i];
    }


// Setting i to length of nameB.
    int y = nameB.length();
// Adding ASCII value of each character of nameB to total3.
    for (int i = 0; i < y; i++) 
    {
        total3 += nameB[i];
    }

// Printing results.
    cout << "\n\nThe added ASCII value of " << nameA << " is " << total2 << "." << endl;
    cout << "The added ASCII value of "<< nameB << " is " << total3 << "." << endl;


// Subtracting the totals of nameA and nameB.
    total = total2 - total3;
// Determining if the totals are within 50 of each other.
    if (total <= 50 && total >= -50)
    {
        t = t + 1;
        cout << "CHECK 1 is true." << endl;
    }

    else
    {
        t = t + 0;
        cout << "CHECK 1 is false." << endl;
    }

    
// Subtracting ageA and ageB.
    totalAge = ageA - ageB;
// Determining if the totals are within 10 of each other.
    if (totalAge <= 10 && totalAge >= -10)
    {
        t = t + 1;
        cout << "CHECK 2 is true." << endl;
    }

    else
    {
        t = t + 0;
        cout << "CHECK 2 is false." << endl;
    }


// Checking if patA and patB are equal.
    if (petA == petB)
    {
        t = t + 1;
        cout << "CHECK 3 is true." << endl;
    }

    else
    {
        t = t + 0;
        cout << "CHECK 3 is false." << endl;
    }


// Creating a running total using Variable t to calculate a true or false result.
    if (t >= 2)
    {
        return true;
    }

    else
    {
        return false;
    }
}
// GetData function definition
void getData(string& name_1, string& name_2, int& age_1, int& age_2, string& pet_1, string& pet_2)
{

// Getting data from user.
    cout << "\nEnter the data for the first hero:" << endl;


    cout << "NAME: ";
    getline(cin,name_1);

    cout << "AGE: ";
    cin >> age_1;

    cout << "PET (dog/cat/rabbit/guinea pig): ";
    cin.ignore();
    getline(cin,pet_1);



    cout << "\nEnter the data for the second super hero: " << endl;


    cout << "NAME: ";
    getline(cin,name_2);

    cout << "AGE: ";
    cin >> age_2;

    cout << "PET (dog/cat/rabbit/guinea pig): ";
    cin.ignore();
    getline(cin,pet_2);

}

