/*
	Title: Program 1
	Author: Dalton W. Sloan
	Date: 18 September 2023
	Purpose: Video Game Library.
*/
#ifndef TEXT_H  // Include guard to prevent double inclusion of this header file
#define TEXT_H

// The Text class encapsulates a dynamically allocated C-string.
class Text {
private:
    char* textArray;  // Pointer to the first element of the dynamically allocated character array
    int textLength;   // Length of the text stored in textArray (not counting null-terminator)

public:
    // Constructor: Initializes the Text object with a given C-string
    Text(const char* text);

    // Destructor: Cleans up dynamic memory allocated for the Text object
    ~Text();

    // Displays the text stored in the Text object
    void displayText() const;

    // Gets the C-string stored in the Text object as a constant character pointer
    const char* getText() const;

    // Returns the length of the text stored in the Text object
    int getLength() const;
};

#endif  // End of include guard
