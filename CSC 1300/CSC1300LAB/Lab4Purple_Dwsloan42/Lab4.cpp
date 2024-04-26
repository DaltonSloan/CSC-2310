/*

Title: lab4.cpp
Author: Dalton W. Sloan
Date: 15 Feb 2023
Purpose: Study vs. Phone Time.

*/

#include <iostream>
using namespace std;

int main() {
// Varible Bank.
    int phone;
    int study;


// User Input.
    cout << "\n\n\nRounding to the nearest hour, what is the average amount of hours you spend on your phone daily?\nAVG DAILY SCREEN-TIME:  ";
    cin >> phone;

// Input Validation Using While Loop.
    while (phone < -1 || phone > 24 ) {
        cout << "ERROR! Please input a number 0 through 24:  ";
        cin >> phone;
    }
// User Input.
    cout << "Rounding to the nearest hour, how many hours on average to you study daily?\nAVG DAILY STUDY or HOMEWORK HOURS:  ";
    cin >> study;

// Input Validation Using While Loop.
    while (study < 0 || study > 24) {
        cout << "ERROR! Please input a number 0 through 24:  ";
        cin >> study;
    }

// Different Outputs Based on Number of Study Hours VS. Number of Phone Time Hours.
    if (phone <= 2 && study < 2) {
        cout << "You may want to study more if you wish to learn anything." << endl;
    }

    if (phone <= 2 && study >= 6) {
        cout << "You need to socialize with people more often." << endl;
    }

    if (phone > 2 && study >= 6) {
        cout << "You need to socialize with people more often and get off that phone." << endl;
    }

    if (phone <= 2 && study >= 2 && study < 6) {
        cout << "You manage your time well." << endl;
    }

    if (phone > 2 && study < 6) {
        cout << "What are you going to do if you lose that phone?  It is interfering with your ability to have a real life." << endl;
    }


return 0;
}
