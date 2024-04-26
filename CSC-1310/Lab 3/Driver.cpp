/*
	Title: Lab 3
	Author: Dalton W. Sloan
	Date: 26 September 2023
	Purpose: Sorting Algorithms
*/
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quicksort(wordArray, 0, numWords - 1);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

// This function performs the Insertion Sort algorithm on an array of wordCount objects.
// The array is sorted in ascending order based on the count value of each wordCount object.
void insertionSort(wordCount *wordArray, int numWords)
{
    int i, j;  // Loop counters
    wordCount key;  // Temporary object to hold the value that we're currently comparing

    // Loop from the second element to the last element
    for (i = 1; i < numWords; i++) {
        key = wordArray[i];  // Store the current element in key
        j = i - 1;  // Initialize j with the previous index

        // While loop for shifting the elements
        // If the element is greater than key, then move it one position up
        while (j >= 0 && wordArray[j].count > key.count) {
            wordArray[j + 1] = wordArray[j];
            j = j - 1;
        }

        // Place key into its correct position
        wordArray[j + 1] = key;
    }
}

// This function performs the Bubble Sort algorithm on an array of wordCount objects.
// The array is sorted in descending order based on the count value of each wordCount object.
void bubbleSortReverse(wordCount *wordArray, int numWords)
{
    // Loop over each element
    for (int i = 0; i < numWords - 1; i++) {
        // Nested loop for adjacent element comparisons and swaps
        for (int j = 0; j < numWords - i - 1; j++) {
            if (wordArray[j].count < wordArray[j + 1].count) {
                // Swap the elements if they are in the wrong order
                swap(wordArray[j], wordArray[j + 1]);
            }
        }
    }
}

// This function performs the Quick Sort algorithm on an array of wordCount objects.
// The array is sorted in ascending order based on the count value of each wordCount object.
void quicksort(wordCount *wordArray, int low, int high)
{
    // Base condition: If 1 or zero elements, partition is already sorted
    if (low < high) {
        int piviot = partition(wordArray, low, high);  // Find the pivot element such that element smaller than pivot are on the left
                                                      // and elements greater than pivot are on the right
        quicksort(wordArray, low, piviot - 1);  // Recursively sort the elements before pivot
        quicksort(wordArray, piviot + 1, high);  // Recursively sort the elements after pivot
    }
}

// This function partitions the array and returns the index of the pivot element.
// The array is partitioned based on the count value of each wordCount object.
int partition(wordCount *wordArray, int low, int high)
{
    wordCount pivot = wordArray[high];  // Pivot is chosen as the last element
    int i = (low - 1);  // Initialize the index for smaller element

    // Loop to place elements smaller than pivot on the left
    // and greater than pivot on the right
    for (int j = low; j <= high - 1; j++) {
        if (wordArray[j].count <= pivot.count) {
            i++;  // Increment index of the smaller element
            // Swap the elements
            swap(wordArray[i], wordArray[j]);
        }
    }
    // Swap the pivot element with the element at (i+1) to place the pivot in its correct position
    swap(wordArray[i + 1], wordArray[high]);
    return (i + 1);  // Return the index of the pivot element
}
