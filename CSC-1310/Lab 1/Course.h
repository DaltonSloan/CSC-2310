/*
	Title: lab1
	Author: Dalton W. Sloan
	Date: 30 August 2023
	Purpose: Dynamic Stuct.
*/
#ifndef COURSE_H
#define COURSE_H

#include <string>

struct Course {
    string Name;
    string Location;
    string* Sections;
    int NumSections;
    int CreditHours;
};

Course* createCourse(std::string name, std::string location, int numSections, int creditHours);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif // COURSE_H