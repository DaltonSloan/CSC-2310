#include <iostream>
#include <string>
using namespace std;

int n;
int* arr = new int[n];  // Dynamically allocate an integer array of size 'n'

// Linear Search Function
// The function takes an array, its size, and the key to search for.
int Linear(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)  // Loop through the entire array
    {
        if (arr[i] == key)  // Check if current element matches the key
        {
            return i;  // Return the index at which the key is found
        }
    }
    return -1;  // Return -1 if key is not found in the array
}

// Binary Search Function
// Precondition: Array must be sorted.
// The function takes a sorted array, its size, and the key to search for.
// Also, it takes two indices, 'r' and 'l', to define the part of the array to search.
int Binary(int* arr, int l, int r, int key)
{
    if (l <= r)  // Check if the array section is valid
    {
        int mid = (l + r) / 2;  // Calculate the middle index
        
        if (key == arr[mid])  // Check if key is found at the middle index
        {
            return mid;  // Return the index where the key is found
        }

        if (key < arr[mid])  // Check if key should be in the left section
        {
            return Binary(arr, l, mid - 1, key);  // Search the left section
        }
        else  // Otherwise, search the right section
        {
            return Binary(arr, mid + 1, r, key);
        }
    }

    return -1;  // Return -1 if the key is not found
}

// Bubble Sort Function
// This function sorts an array using bubble sort algorithm.
void bubble(int *arr,int size)
{
    for (int j = 0; j < size; j++)  // Outer loop: Repeat the process 'size' times
    {
        for (int i = 0; i < size-1; i++)  // Inner loop: Compare adjacent elements
        {
            if (arr[i] > arr[i+1])  // Swap if the current element is greater than the next element
            {
                int temp = arr[i];  
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

// Selection Sort Function
// This function sorts an array using selection sort algorithm.
void selection(int *arr,int size)
{
    int min;  // Declare variable to hold index of minimum element
    for (int j = 0; j < size-1; j++)  // Outer loop: Until size-1 elements are sorted
    {
        min = j;  // Assume the first element is the smallest
        
        for (int i = j+1; i < size; i++)  // Inner loop: Find the minimum element in the unsorted section
        {
            if (arr[i] < arr[min])
            {
                min = i;  // Update the index of the minimum element
            }
        }
        
        // Swap the found minimum element with the first element of unsorted section
        int temp = arr[j];
        arr[j] = arr[min];
        arr[min] = temp;
    }
}

// Insertion Sort Function
// This function sorts an array using insertion sort algorithm.
void insertion(int *arr,int size)
{
    int key, j;  // Declare variables for key element and index
    
    for (int i = 1; i < size; i++)  // Loop starts from 1, as the first element is considered sorted
    {
        key = arr[i];  // Select the element to be inserted
        j = i - 1;  // Initialize j as the last index of the sorted section
        
        while (j >= 0 && arr[j] > key)  // Find the correct position for the key
        {
            arr[j + 1] = arr[j];  // Shift elements to make space for the key
            j = j - 1;  // Move backwards through the sorted section
        }
        
        arr[j + 1] = key;  // Insert the key into its correct position
    }
}

