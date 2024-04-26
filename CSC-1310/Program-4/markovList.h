/*
	Title: Program 4
    Class: 1310-001
	Author: Dalton W. Sloan
	Date: 30 November 2023
	Purpose: 1,000 Graphs and a Keyboard.
*/
#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Struct to represent an edge in the linked list
struct edge
{
	string destination;  // Destination state of the transition
	float weight;        // Weight of the transition
	edge* next;          // Pointer to the next edge in the linked list
};

// Class definition for markovList
class markovList
{
	private:
		map<string, edge*> corpus;  // Map to store the linked lists for each state
		int corpusSize;             // Size of the corpus, i.e., the number of distinct states

	public:
		// Constructor: Reads transition probabilities from a file specified by 'filename'
		markovList(const char*);
		
		// Destructor: Releases dynamically allocated memory for linked lists
		~markovList();
		
		// Generates a Markov chain of the specified 'length' and returns the result
		string generate(int);
};

// Implementation of the markovList class

// Constructor implementation
markovList::markovList(const char* filename)
{
	ifstream file(filename);  // Open the file specified by 'filename'
	stringstream parser, splitter;  // String streams for parsing the file content
	string line, index, word;  // Variables to store lines, indices, and words
	float weight;  // Variable to store transition weights
	edge* newEdge;  // Pointer to a new edge
	srand(time(0));  // Seed the random number generator with the current time
	
	if(file.good()) 
	{
		file >> corpusSize;  // Read the corpus size from the first line of the file
		file.ignore(1, '\n');  // Ignore the newline character
	
		// Read each line in the file
		while(getline(file, line, '\n'))
		{
			parser.clear();  // Clear the parser stringstream
			parser << line;  // Load the line into the parser stringstream
			getline(parser, index, ',');  // Extract the index (source state)
			
			// Initialize an empty list at the index
			edge* tail = nullptr;
			corpus[index] = nullptr;
			
			// Process the rest of the line, extracting destination states and transition weights
			while(getline(parser, word, ','))
			{
				// Allocate a new node in the edge list
				splitter.clear();  // Clear the splitter stringstream
				splitter.str(word);  // Load the word into the splitter stringstream
				splitter >> word >> weight;  // Extract the destination state and transition weight
				
				// Create a new edge node
				newEdge = new edge;
				newEdge->destination = word;
				newEdge->weight = weight;
				
				// Attach the new node to the list
				if (corpus[index] == nullptr)
				{
					tail = newEdge;
					corpus[index] = newEdge;
				}
				else
				{
					tail->next = newEdge;
					tail = newEdge;
				}
			}
		}
	}
	file.close();  // Close the file
}

// Destructor implementation
markovList::~markovList()
{
	// Release dynamically allocated memory for linked lists
	for (pair<string, edge*> entry : corpus)
	{
		edge* current = entry.second;
		while (current != nullptr)
		{
			edge* next = current->next;
			delete current;
			current = next;
		}
	}
}
		
// Generate method implementation
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();  // Initialize an iterator to find a random node in the next line
	advance(it, rand() % corpusSize);  // This grabs a random node from your corpus as a starting point
	string result = it->first;  // Initialize the result with the starting state
	
	// Generate the Markov chain of the specified length
	for (int i = 0; i < length; i++)
	{
		float roll = (float)rand() / RAND_MAX;  // Generate a random float between 0 and 1
		float cumulativeWeight = 0.0;  // Cumulative weight for probabilistic state transition
		
		edge* current = it->second;  // Get the linked list of transitions for the current state
		while (current != nullptr)
		{
			cumulativeWeight += current->weight;  // Add the transition weight to the cumulative weight
			
			// Check if the randomly generated value falls within the cumulative weight
			if (roll < cumulativeWeight)
			{
				result += " " + current->destination;  // Append the selected state to the result
				it = corpus.find(current->destination);  // Move to the next state
				break;  // Exit the loop after selecting the next state
			}
			current = current->next;  // Move to the next edge in the linked list
		}
	}

	return result;  // Return the generated Markov chain as a string
}

#endif  // End of MARKOVLIST_H
