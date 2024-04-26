/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"

using namespace std;

int main() {
    // Variable to hold the maximum number of games the library can hold
    int maxGames;
    cout << "How many video games can your library hold? ";
    cin >> maxGames;

    // Create a new VideoGameLibrary object on the heap with a maximum capacity
    VideoGameLibrary* library = new VideoGameLibrary(maxGames);

    // Variable to hold the user's menu choice
    int choice;

    // Main program loop
    do {
        // Display the main menu to the user
        cout << "\nWhat would you like to do?\n"
        << "1. Load video games from file.\n"
        << "2. Save video games to a file.\n"
        << "3. Add a video game.\n"
        << "4. Remove a video game.\n"
        << "5. Display all video games.\n"
        << "6. Remove ALL video games from this library and end program.\n\n"
        << "CHOOSE 1-6: ";
        
        // Get the user's menu choice
        cin >> choice;

        // Perform an action based on the user's choice
        switch (choice) {
            case 1:  // Load video games from file
                {
                    string filename;
                    cout << "\nEnter the filename to load from: ";
                    cin >> filename;
                    library->loadVideoGamesFromFile(filename.c_str());
                }
                break;
            case 2:  // Save video games to a file
                {
                    string filename;
                    cout << "\nEnter the filename to save to: ";
                    cin >> filename;
                    library->saveToFile(filename.c_str());
                }
                break;
            case 3:  // Add a new video game to the library
                {
                    string title, developer, publisher;
                    int year;
                    cout << "\nVideo Game TITLE: ";
                    cin.ignore();  // Clear the newline character from the buffer
                    getline(cin, title);
                    cout << "Video Game DEVELOPER: ";
                    getline(cin, developer);
                    cout << "Video Game PUBLISHER: ";
                    getline(cin, publisher);
                    cout << "Video Game YEAR: ";
                    cin >> year;
                    // Create new Text and VideoGame objects on the heap
                    Text* titleText = new Text(title.c_str());
                    Text* devText = new Text(developer.c_str());
                    Text* pubText = new Text(publisher.c_str());
                    VideoGame* newGame = new VideoGame(titleText, devText, pubText, year);
                    library->addVideoGameToArray(newGame);
                }
                break;
            case 4:  // Remove a video game from the library
                {
                    string title;
                    cout << "\nChoose from the following video games to remove: ";
                    cout << "\n";
                    library->displayVideoGameTitles();
                    cin.ignore();  // Clear the newline character from the buffer
                    getline(cin, title);
                    library->removeVideoGameFromArray(title);
                }
                break;
            case 5:  // Display all video games in the library
                library->displayVideoGames();
                break;
            case 6:  // Remove all video games and exit program
                delete library;
                cout << "\nAll games removed. Library deleted. Exiting program." << endl;
                return 0;
            default:  // Invalid choice
                cout << "\nInvalid choice. Please choose a valid option (1-6)." << endl;
        }
    } while (choice != 6);

    // Safeguard: Deleting the library, although the code should not reach this point
    delete library;

    return 0;
}