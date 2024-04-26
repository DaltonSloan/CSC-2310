/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/
// Preprocessor directive to prevent multiple inclusions of the header file
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

// Include the "Text" header for Text objects that will hold textual information like title, developer, etc.
#include "Text.h"
// Include <fstream> for file output operations
#include <fstream>

// VideoGame class definition
class VideoGame {
private:
    Text* title;       // Pointer to Text object that holds the game's title
    Text* developer;   // Pointer to Text object that holds the game's developer
    Text* publisher;   // Pointer to Text object that holds the game's publisher
    int year;          // Integer to hold the release year of the game

public:
    // Constructor: Initializes a new VideoGame object with title, developer, publisher, and release year
    VideoGame(Text* title, Text* developer, Text* publisher, int year);
    
    // Destructor: Cleans up dynamically allocated resources
    ~VideoGame();

    // displayInfo: Method to display all the information about a VideoGame object
    void displayInfo() const;

    // displayInfoToFile: Method to save all the information about a VideoGame object to a file
    void displayInfoToFile(std::ofstream& outFile) const;

    // getTitle: Returns a pointer to the Text object that holds the game's title
    Text* getTitle() const;
};

// End of preprocessor directive for preventing multiple inclusions
#endif
