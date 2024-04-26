#include <iostream>
#include <algorithm>  // Include this for the 'swap' function
using namespace std;

void bubbleSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);


int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    cout << "Bubble Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    int arr2[] = {12, 11, 13, 5, 6};
    mergeSort(arr2, 0, n - 1);
    cout << "\nMerge Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";

    int arr3[] = {12, 11, 13, 5, 6};
    insertionSort(arr3, n);
    cout << "\nInsertion Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";

    int arr4[] = {12, 11, 13, 5, 6};
    selectionSort(arr4, n);
    cout << "\nSelection Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr4[i] << " ";

    return 0;
}

// Function to perform the Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;  // Flag to optimize the algorithm

    // Iterate through all elements of the array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Compare adjacent elements and swap them if they are in the wrong order
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping happened in the inner loop, the array is sorted
        if (!swapped) break;
    }
}

// Function to merge two halves into a sorted array
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // Calculate the size of the first half
    int n2 = r - m;      // Calculate the size of the second half

    int L[n1], R[n2];    // Temporary arrays to hold the two halves

    // Copy data to the temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    // Merge the temp arrays back into the original array arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform the Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;  // Base case: if the array has one or zero elements, it's already sorted

    int m = l + (r - l) / 2;  // Calculate the middle index of the array

    // Recursively sort the first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
}

// Function to perform the Insertion Sort
void insertionSort(int arr[], int n) {
    // Iterate through all elements of the array
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Store the current element to be compared
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform the Selection Sort
void selectionSort(int arr[], int n) {
    // Iterate through all elements of the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the current position is the smallest

        // Iterate the rest of the array
        for (int j = i + 1; j < n; j++) {
            // Update minIndex if the element at j is lower than it
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[minIndex], arr[i]);
    }
}