/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/
#include <iostream>  // For using cout
#include <string>     // For using string operations (although not used here)
#include "Text.h"     // Include the header file for the Text class
#include <cstring>    // For using C-string functions like strlen and strcpy
using namespace std;

// Constructor: Initializes the Text object with a given C-string
Text::Text(const char* text) {
    textLength = strlen(text);  // Get the length of the given text
    textArray = new char[textLength + 1];  // Allocate memory for the text (plus null terminator)
    strcpy(textArray, text);  // Copy the given text into the allocated memory
}

// Destructor: Cleans up dynamic memory allocated for the Text object
Text::~Text() {
    delete[] textArray;  // Release the memory allocated for textArray
    cout << "Text destructor: Released memory for textArray." << endl;  // Informative message
}

// Display the text stored in the object
void Text::displayText() const {
    cout << textArray;  // Output the text stored in textArray
}

// Get the text stored in the object as a const C-string
const char* Text::getText() const {
    return textArray;  // Return the pointer to the internal text array
}

// Get the length of the stored text
int Text::getLength() const {
    return textLength;  // Return the length of the text stored in the object
}
