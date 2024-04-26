#include <iostream>
using namespace std;

void displayArray(int*, int);
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	// Display the array
	displayArray(myArr, 5);
	
	// Sort the array
	MergeSort(myArr, 0, 4);
	
	// Display the array again
	displayArray(myArr, 5);
	
	return 0;
}

void MergeSort(int* arr, int beg, int end) {
   int mid;
   
   if (beg < end) {
		mid = (beg + end) / 2;
		MergeSort(arr, beg, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, beg, mid, end);
   }
}

void Merge(int* arr, int beg, int mid, int end) {
   int mergedSize = end - beg + 1;
   int mergePos = 0;
   int leftPos = beg;
   int rightPos = mid + 1;
   int* mergedNumbers = new int[mergedSize];
   
   while (leftPos <= mid && rightPos <= end) {
      if (arr[leftPos] < arr[rightPos]) {
         mergedNumbers[mergePos] = arr[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = arr[rightPos];
         ++rightPos;
      }
      ++mergePos;
   }
   
   while (leftPos <= mid) {
      mergedNumbers[mergePos] = arr[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   while (rightPos <= end) {
      mergedNumbers[mergePos] = arr[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      arr[beg + mergePos] = mergedNumbers[mergePos];
   }
   
   delete [] mergedNumbers;
}

void displayArray(int *arr, int size)
{
	cout << "\n--------------------The array:  ";
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "--------------------\n";
}
