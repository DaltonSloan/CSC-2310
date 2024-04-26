/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/
#include <iostream>
#include <string>
#include "VideoGame.h"
#include <fstream>
using namespace std;

// Constructor: Initializes a new VideoGame object with given title, developer, publisher, and year
VideoGame::VideoGame(Text* title, Text* developer, Text* publisher, int year) {
    this->title = title;
    this->developer = developer;
    this->publisher = publisher;
    this->year = year;
}

// Destructor: Releases dynamic memory allocated for the title, developer, and publisher Text objects
VideoGame::~VideoGame() {
    delete title;
    delete developer;
    delete publisher;
    cout << "\nVideoGame destructor: Released memory for VideoGame object." << endl;
}

// displayInfo: Outputs video game details to the console
void VideoGame::displayInfo() const {
    cout << "\nGame Title: ";
    title->displayText();  // Call Text object's displayText() method to display the title
    cout << "\nDeveloper: ";
    developer->displayText();  // Display the developer
    cout << "\nPublisher: ";
    publisher->displayText();  // Display the publisher
    cout << "\nYear Released: " << year << endl;  // Display the year
}

// displayInfoToFile: Outputs video game details to a file stream
void VideoGame::displayInfoToFile(ofstream& outFile) const {
    outFile << "Title: " << title->getText() << endl;  // Write the title to the file
    outFile << "Developer: " << developer->getText() << endl;  // Write the developer to the file
    outFile << "Publisher: " << publisher->getText() << endl;  // Write the publisher to the file
    outFile << "Year: " << year << endl;  // Write the year to the file
}

// getTitle: Returns a pointer to the Text object that holds the game's title
Text* VideoGame::getTitle() const {
    return title;
}
