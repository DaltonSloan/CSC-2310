/*
	Title: lab1
	Author: Dalton W. Sloan
	Date: 30 August 2023
	Purpose: Dynamic Stuct.
*/
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

Course* createCourse(string name, string location, int numSections, int creditHours) {
    Course* newCourse = new Course;
    newCourse->Name = name;
    newCourse->Location = location;
    newCourse->NumSections = numSections;
    newCourse->CreditHours = creditHours;
    
    // Dynamically allocate memory for the sections array
    newCourse->Sections = new string[numSections];
    
    return newCourse;
}

void destroyCourse(Course* myCourse) {
    // Deallocate memory for the sections array
    delete[] myCourse->Sections;
    
    // Deallocate memory for the course structure
    delete myCourse;
}

void printCourse(Course* myCourse) {
    cout << "Course Name: " << myCourse->Name << endl;
    cout << "Location: " << myCourse->Location << endl;
    cout << "Credit Hours: " << myCourse->CreditHours << endl;
    cout << "Number of Sections: " << myCourse->NumSections << endl;
    
    cout << "Sections:" << endl;
    for (int i = 0; i < myCourse->NumSections; ++i) {
        std::cout << "Section " << (i + 1) << ": " << myCourse->Sections[i] << endl;
    }
}
