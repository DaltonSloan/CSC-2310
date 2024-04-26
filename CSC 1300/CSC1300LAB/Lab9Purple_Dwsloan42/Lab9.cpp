/*
	Title: lab9.cpp
	Author: Dalton W. Sloan
	Date: 18 April 2023
	Purpose: Paranormal Activity.
*/

#include <iostream>
#include <string>
using namespace std;
// Function prototypes.
void getParanormalData(int,int*,string*,string*);
void getStats(int numInvestigators, int* investNumRecordings, int& totalRecordings, double& aveNumRecordings, int& i);

// Main fuction.
int main()
{
    // Variable bank.
    int numInvestigators = 0;
    int totalRecordings = 0;
    double aveNumRecordings = 0;
    int i = 0;
    char locations[100];
    int* investNumRecordings;
    string* investName;
    string* investRecordingDate;

    // User data collection.
    cout << "\n\nHello!  What haunted location are you investigating?" << endl;
    cin.get(locations,100);

    cout << "How many investigators will be working this location?" << endl;
    cin >> numInvestigators;
    cin.ignore();

    while (numInvestigators < 1 || numInvestigators > 25)
    {
        cout << "Oops!  You must enter 1 through 25." << endl;
        cin >> numInvestigators;
        cin.ignore();
    }
    // Allocating memory.
    investNumRecordings = new int[numInvestigators];
    investName = new string[numInvestigators];
    investRecordingDate = new string[numInvestigators];
    // Function calls.
    getParanormalData(numInvestigators,investNumRecordings,investName,investRecordingDate);

    getStats(numInvestigators,investNumRecordings,totalRecordings,aveNumRecordings,i);
    // Data output after calculations.
    cout << "\n\n-----------------------------------------------------------------" << endl;
    cout << "The total amount of EVPs recorded by all " << numInvestigators << " investigators at " << endl;
    cout << locations << " is " << totalRecordings << " recordings." << endl << endl;
    cout << "The average amount of EVPs recorded at " << locations << " is " << aveNumRecordings << " recordings." << endl << endl;
    cout << "The investigator who recorded the most is " << investName[i] << " with " << investNumRecordings[i] << endl;
    cout << " on " << investRecordingDate[i] << endl;

    // Freeing the memory.
    delete[] investNumRecordings;
    delete[] investName;
    delete[] investRecordingDate;

}
// Function definitions.
void getParanormalData(int numInvestigators,int* investNumRecordings,string* investName,string* investRecordingDate)
{
    for (int i = 0; i < numInvestigators; i++)
    {
        // A loop to collect data from each user inputted.
        cout << "\nEnter the investigator's name, the day of their investigation, and the number of EVPs" << endl; 
        cout << "they recorded on their voice recorder." << endl;
        cout << "INVESTIGATOR " << i + 1 << ":" << endl;
        cout << "        NAME: ";
        getline(cin,investName[i]);
        cout << "        Day(mm-dd-yyyy): ";
        getline(cin,investRecordingDate[i]);
        cout << "        NUMBER OF EVPs:";
        cin >> investNumRecordings[i];
        cin.ignore();

        
    }
}

void getStats(int numInvestigators, int* investNumRecordings, int& totalRecordings, double& aveNumRecordings, int& i)
{
    // A loop to determine total Recordings, highest number of recordings, and the average number of recordings.
    for(int j = 0; j < numInvestigators; j++)
    {
        
        totalRecordings += investNumRecordings[j];

        if(investNumRecordings[i] < investNumRecordings[j])
        {
            i = j;
        }
    }
        aveNumRecordings = static_cast<double> (totalRecordings) / numInvestigators;
}

