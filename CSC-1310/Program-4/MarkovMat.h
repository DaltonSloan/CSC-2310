/*
	Title: Program 4
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 30 November 2023
	Purpose: 1,000 Graphs and a Keyboard.
*/
#ifndef MARKOVMAT_H
#define MARKOVMAT_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Class definition for MarkovMatrix
class MarkovMatrix {
private:
    map<string, map<string, float>> transitionMatrix;  // Matrix to store transition probabilities
    int corpusSize;  // Size of the corpus, i.e., the number of distinct states

public:
    // Constructor: Reads transition probabilities from a file specified by 'filename'
    MarkovMatrix(const char*);
    
    // Destructor: No dynamic memory to release, so the default destructor is sufficient
    ~MarkovMatrix();

    // Generates a Markov chain of the specified 'length' and returns the result
    string generate(int);
};

// Implementation of the MarkovMatrix class

// Constructor implementation
MarkovMatrix::MarkovMatrix(const char* filename) {
    ifstream file(filename);  // Open the file specified by 'filename'
    stringstream parser, splitter;  // Stringstreams for parsing the file content
    string line, index, word;  // Variables to store lines, indices, and words
    float weight;  // Variable to store transition weights

    srand(time(0));  // Seed the random number generator with the current time

    // Check if the file is open and readable
    if (file.good()) {
        file >> corpusSize;  // Read the corpus size from the first line of the file
        file.ignore(1, '\n');  // Ignore the newline character

        // Read each line in the file
        while (getline(file, line, '\n')) {
            parser.clear();  // Clear the parser stringstream
            parser << line;  // Load the line into the parser stringstream
            getline(parser, index, ',');  // Extract the index (source state)

            transitionMatrix[index];  // Create an empty map for the index (if not already created)

            // Process the rest of the line, extracting destination states and transition weights
            while (getline(parser, word, ',')) {
                splitter.clear();  // Clear the splitter stringstream
                splitter.str(word);  // Load the word into the splitter stringstream
                splitter >> word >> weight;  // Extract the destination state and transition weight
                transitionMatrix[index][word] = weight;  // Store the transition weight in the matrix
            }
        }
    }
    file.close();  // Close the file
}

// Destructor implementation
MarkovMatrix::~MarkovMatrix() {
    // No need to delete dynamically allocated edges/nodes in this representation
}

// Generate method implementation
string MarkovMatrix::generate(int length) {
    map<string, map<string, float>>::iterator it = transitionMatrix.begin();  // Iterator pointing to a random starting state
    advance(it, rand() % corpusSize);  // Advance the iterator to a random starting state
    string result = it->first;  // Initialize the result with the starting state

    // Generate the Markov chain of the specified length
    for (int i = 0; i < length; i++) {
        float roll = (float)rand() / RAND_MAX;  // Generate a random float between 0 and 1
        float cumulativeWeight = 0.0;  // Cumulative weight for probabilistic state transition

        const map<string, float>& transitions = it->second;  // Extract transition probabilities for the current state
        // Iterate over possible transitions from the current state
        for (const auto& transition : transitions) {
            cumulativeWeight += transition.second;  // Add the transition weight to the cumulative weight
            // Check if the randomly generated value falls within the cumulative weight
            if (roll < cumulativeWeight) {
                result += " " + transition.first;  // Append the selected state to the result
                it = transitionMatrix.find(transition.first);  // Move to the next state
                break;  // Exit the loop after selecting the next state
            }
        }
    }

    return result;  // Return the generated Markov chain as a string
}

#endif
