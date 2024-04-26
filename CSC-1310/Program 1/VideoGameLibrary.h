/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/

// Make sure this header is included only once
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

// Include necessary headers
#include "VideoGame.h"
#include <string>
#include <fstream>

// VideoGameLibrary class definition
class VideoGameLibrary {
private:
    // An array of pointers to VideoGame objects
    VideoGame** videoGamesArray;
    // Maximum number of games the array can hold
    int maxGames;
    // Current number of games in the array
    int numGames;

    // Private method to resize the videoGamesArray when it's full
    void resizeVideoGameArray();

public:
    // Constructor that initializes with a maximum number of games
    VideoGameLibrary(int maxGames);
    // Destructor to release dynamically allocated memory
    ~VideoGameLibrary();
    
    // Method to add a VideoGame object to the array
    void addVideoGameToArray(VideoGame *videoGame);
    // Method to display information of all games in the array
    void displayVideoGames() const;
    // Method to display only the titles of all games in the array
    void displayVideoGameTitles() const;
    // Method to load games from a file
    void loadVideoGamesFromFile(const char* filename);
    // Method to remove a game by its title
    void removeVideoGameFromArray(const std::string& title);
    // Method to save the titles of games to a file
    void saveToFile(const char* filename) const;
};

#endif  // End of include guard
