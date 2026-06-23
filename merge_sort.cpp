#include <bits/stdc++.h>
using namespace std;

void mergeParts(int numbers[], int start, int middle, int end)
{
    int firstHalfSize = middle - start + 1; // Calculate the size of the first subarray
    int secondHalfSize = end - middle;      // Calculate the size of the second subarray

    int firstHalf[firstHalfSize];   // Temporary array for the left portion
    int secondHalf[secondHalfSize]; // Temporary array for the right portion

    for (int i = 0; i < firstHalfSize; i++)
    {
        firstHalf[i] = numbers[start + i]; // Copy elements from the original array into the first temporary array
    }

    for (int i = 0; i < secondHalfSize; i++)
    {
        secondHalf[i] = numbers[middle + 1 + i]; // Copy elements from the original array into the second temporary array
    }

    int firstPointer = 0;  // Tracks the current position in the first subarray
    int secondPointer = 0; // Tracks the current position in the second subarray
    int mergedIndex;       // Position where the next sorted element will be placed

    for (mergedIndex = start; firstPointer < firstHalfSize && secondPointer < secondHalfSize; mergedIndex++)
    {
        // Compare elements from both temporary arrays and place the smaller one into the original array
        if (firstHalf[firstPointer] < secondHalf[secondPointer])
        {
            numbers[mergedIndex] = firstHalf[firstPointer];
            firstPointer++;
        }
        else
        {
            numbers[mergedIndex] = secondHalf[secondPointer];
            secondPointer++;
        }
    }

    // Copy any remaining elements from the first temporary array
    while (firstPointer < firstHalfSize)
    {
        numbers[mergedIndex] = firstHalf[firstPointer];
        firstPointer++;
        mergedIndex++;
    }

    // Copy any remaining elements from the second temporary array
    while (secondPointer < secondHalfSize)
    {
        numbers[mergedIndex] = secondHalf[secondPointer];
        secondPointer++;
        mergedIndex++;
    }
}

void divideArray(int numbers[], int start, int end)
{
    // Stop dividing when the subarray contains only one element
    if (start >= end)
    {
        return;
    }

    int middle = start + (end - start) / 2; // Find the middle index of the current subarray

    divideArray(numbers, start, middle);      // Recursively divide the left half
    divideArray(numbers, middle + 1, end);    // Recursively divide the right half
    mergeParts(numbers, start, middle, end);  // Merge the two sorted halves
}

int main()
{
    int totalElements; // Stores the number of elements in the array
    cin >> totalElements;

    int numbers[totalElements]; // Array to hold user input values

    for (int i = 0; i < totalElements; i++)
    {
        cin >> numbers[i]; // Read each array element
    }

    divideArray(numbers, 0, totalElements - 1); // Start the merge sort process

    for (int i = 0; i < totalElements; i++)
    {
        cout << numbers[i] << " "; // Print the sorted array
    }

    return 0;
}
