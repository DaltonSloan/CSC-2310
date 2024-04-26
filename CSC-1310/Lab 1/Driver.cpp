/*
	Title: lab1
	Author: Dalton W. Sloan
	Date: 30 August 2023
	Purpose: Dynamic Stuct.
*/
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;


int main() {
    int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	//LOOK!!
	//Dynamically allocate a new array of pointers to Courses of size numCourses and assign this array to myCourses
    Course** myCourses = new Course*[numCourses];
	
	
	for (int i=0; i< numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		//LOOK!!
		//Call the createCourse function and make sure to assign the returned value to myCourses[i] 
        myCourses[i] = createCourse(name, location, numSections, numHours);
    


		
		for(int x=0; x<numSections; x++)
		{
			cout << "\nSECTION " << x+1 << ":\t\t";
			//LOOK!!
			//Read in the string from the user and put in the correct array element of the sections array
            getline(cin, myCourses[i]->Sections[x]);
		}
		cout << "\n*******************************\n";
	}
	
	cout << "\n\nThe following are the courses you entered:\n\n";
	for(int i=0; i<numCourses; i++)
	{
		cout << "******************************* COURSE " << (i+1) << "*******************************\n";
		printCourse(myCourses[i]);
	}
	
	for(int i=0;  i< numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete []  myCourses;
	
	cout << endl << endl;


    return 0;
}
