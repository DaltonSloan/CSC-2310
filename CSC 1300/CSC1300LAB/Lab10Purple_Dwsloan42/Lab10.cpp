/*
	Title: lab10.cpp
	Author: Dalton W. Sloan and Grant Christy
	Date: 21 March 2023
	Purpose: Chef Competition.
*/

#include <iostream>
#include <limits>
using namespace std;

struct PastryCategory {
    string name;
    int numAwards;
};

struct Chef {
    string name;
    string hometown;
    int numCategories;
    PastryCategory* categories;
};

int main() {
    int numChefs;
    cout << "\n\nHow many chiefs are competing?: ";
    cin >> numChefs;

    // Allocate an array of Chef structures
    Chef* chefs = new Chef[numChefs];

    for (int i = 0; i < numChefs; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Read in chef's name and hometown
        cout << "\n****CHEF" << i + 1 << "****";
        cout << "\n        NAME: ";
        getline(cin, chefs[i].name);

        cout << "\n        HOMETOWN: "; 
        getline(cin, chefs[i].hometown);

        // Read in number of categories and allocate an array of PastryCategory structures
        cout << "\nHow many categories has " << chefs[i].name << " won awards in? ";
        cin >> chefs[i].numCategories;
        chefs[i].categories = new PastryCategory[chefs[i].numCategories];

        // Read in category names and number of awards for each category
        for (int j = 0; j < chefs[i].numCategories; j++) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nFOR CATEGORY " << j + 1 <<":";
            cout << "\n        Name of Category: ";
            getline(cin, chefs[i].categories[j].name);

            cout << "\n        Number of awards in " << chefs[i].categories[j].name << ": ";
            cin >> chefs[i].categories[j].numAwards;
        }
    }

    // Find chef with the most awards
    int maxAwards = numeric_limits<int>::min();
    int maxIndex = -1;

    for (int i = 0; i < numChefs; i++) {
        int totalAwards = 0;
        for (int j = 0; j < chefs[i].numCategories; j++) {
            totalAwards += chefs[i].categories[j].numAwards;
        }

        if (totalAwards > maxAwards) {
            maxAwards = totalAwards;
            maxIndex = i;
        }
    }

    // Print chef with the most awards and their award categories
    cout << "\nChef " << chefs[maxIndex].name << " from " << chefs[maxIndex].hometown
        << " has won the most awards, with a total of " << maxAwards << " awards.\n";
    cout << "Award categories:\n";
    for (int i = 0; i < chefs[maxIndex].numCategories; i++) {
        cout << chefs[maxIndex].categories[i].name << ": " << chefs[maxIndex].categories[i].numAwards << "\n";
    }

    // Release all dynamically allocated memory
    for (int i = 0; i < numChefs; i++) {
        delete[] chefs[i].categories;
    }
    delete[] chefs;

    return 0;
}
