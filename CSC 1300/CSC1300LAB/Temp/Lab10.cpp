/*
	Title: lab10.cpp
	Author: Dalton W. Sloan and Grant Christy
	Date: 25 April 2023
	Purpose: Pastry Competition.
*/

#include <iostream>
#include <string>
#include <limits> 
using namespace std;

struct PastryCategory
{
    string name;
    int numAwards;
};

struct Chef
{
    string chefName;
    string homeTownName;
    int numCategories;
};


int main()
{

    int numChef = 0;
    int chefAwards = 0;
    int sum[numChef];
    int highest = 0;
    int num1Chef = 0;

    cout << "\n\nHow many chiefs are competing? " << endl;
    cin >> numChef;
    cin.ignore();

    Chef* cookArray = new Chef[numChef];
    Chef cook;
    
    PastryCategory** awardsArray;
    awardsArray = new PastryCategory*[numChef];

    PastryCategory* categoriesArray;
    categoriesArray = new PastryCategory[cook.numCategories];


    for (int i = 0; i < numChef; i++)
    {
        cout << "\n****CHEF" << i + 1 << "****";
        cout << "\n        NAME: ";
        getline(cin, (cookArray[i].chefName));
        cout << "\n        HOMETOWN: "; 
        getline(cin, (cookArray[i].homeTownName));
        cout << "\nHow many categories has " << (cookArray[i].chefName) << endl;
        cout << "won awards in? ";
        cin >> cookArray[i].numCategories;
        cin.ignore();

        for (int j = 0; j < cookArray[i].numCategories; j++)
        {
            cout << "\nFOR CATEGORY " << j + 1 <<":";
            cout << "\n        Name of Category: ";
            getline(cin, (categoriesArray[j].name));
            cout << "\n        Number of awards in " << (categoriesArray[j].name) << ": ";
            cin >> (categoriesArray[j].numAwards);
            cin.ignore();
            sum[i] += (categoriesArray[j].numAwards);
        } 

        if (sum[i] > highest)
        highest = sum[i];
        num1Chef = i;
    }

cout << "\nThe pastry chef that has won the most awards (" << highest << " awards) is " << cookArray[num1Chef].chefName  << ", " << endl;
cout << "with awards in the following categories: " << endl;




delete[] cookArray;
delete[] awardsArray;
delete[]categoriesArray;
return 0;
}
