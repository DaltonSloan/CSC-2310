/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/

// Include the relevant headers
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor to initialize a VideoGameLibrary with a maximum number of games it can hold
VideoGameLibrary::VideoGameLibrary(int maxGames) {
    this->maxGames = maxGames;
    numGames = 0;  // Initialize the number of games to zero
    videoGamesArray = new VideoGame*[maxGames];  // Dynamically allocate an array of VideoGame pointers
}

// Destructor to release memory allocated for VideoGame objects and the array itself
VideoGameLibrary::~VideoGameLibrary() {
    for (int i = 0; i < numGames; i++) {
        delete videoGamesArray[i];  // Delete each VideoGame object
    }
    delete[] videoGamesArray;  // Delete the array of pointers
    cout << "\nVideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
}

// Function to resize the array of VideoGame pointers when it becomes full
void VideoGameLibrary::resizeVideoGameArray() {
    int newMaxGames = maxGames * 2;
    VideoGame **newArray = new VideoGame*[newMaxGames];
    
    for (int i = 0; i < numGames; i++) {
        newArray[i] = videoGamesArray[i];
    }

    delete[] videoGamesArray;
    videoGamesArray = newArray;
    maxGames = newMaxGames;
}

// Function to add a new VideoGame object to the array
void VideoGameLibrary::addVideoGameToArray(VideoGame *videoGame) {
    if (numGames == maxGames) {
        resizeVideoGameArray();
    }
    videoGamesArray[numGames++] = videoGame;
}

// Function to display all video games in the array
void VideoGameLibrary::displayVideoGames() const {
    for (int i = 0; i < numGames; i++) {
        cout << "\n----------Video Game " << i+1 << "----------" << endl;
        videoGamesArray[i]->displayInfo();
    }
}

// Function to display only the titles of the video games in the array
void VideoGameLibrary::displayVideoGameTitles() const {
    for (int i = 0; i < numGames; i++) {
        videoGamesArray[i]->getTitle()->displayText();  
        cout << endl;
    }
}

// Function to load video games from a file
void VideoGameLibrary::loadVideoGamesFromFile(const char* filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    // Variables to temporarily hold the data read from the file
    string title, developer, publisher;
    int year;
    int gamesAdded = 0;

    while (getline(inFile, title) && getline(inFile, developer) && getline(inFile, publisher) && inFile >> year) {
        inFile.ignore();  // Ignore the remaining newline character
        
        VideoGame *videoGame = new VideoGame(new Text(title.c_str()), new Text(developer.c_str()), new Text(publisher.c_str()), year);

        // Check if the array needs resizing
        if (numGames == maxGames) {
            resizeVideoGameArray();
        }

        addVideoGameToArray(videoGame);

        // Increment number of games added
        gamesAdded++;

        // Output the title of the video game and indicate that it was added successfully
        cout << title << " was added successfully" << endl;
    }

    inFile.close();  // Close the input file

    cout << gamesAdded << " video games were read from the file & added to the library." << endl;


    inFile.close();  // Close the input file
}

// Function to remove a video game from the array
void VideoGameLibrary::removeVideoGameFromArray(const string& title) {
    for (int i = 0; i < numGames; i++) {
        if (string(videoGamesArray[i]->getTitle()->getText()) == title) {
            delete videoGamesArray[i];
            // Shift elements down to fill the gap
            for (int j = i; j < numGames - 1; j++) {
                videoGamesArray[j] = videoGamesArray[j + 1];
            }
            numGames--;
            return;
        }
    }
    cout << "Game not found." << endl;  // If the loop completes without returning, the game wasn't found
}

// Function to save video game titles to a file
void VideoGameLibrary::saveToFile(const char* filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    for (int i = 0; i < numGames; i++) {
        outFile << videoGamesArray[i]->getTitle()->getText() << endl;  
    }

    outFile.close();  // Close the output file
}
