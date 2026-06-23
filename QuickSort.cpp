#include <bits/stdc++.h>
using namespace std;

int placePivot(int numbers[], int start, int end) // Receives the array and the current range to partition
{
    int pivotValue = numbers[end]; // Select the last element as the pivot

    int smallerIndex, currentIndex;

    for (smallerIndex = start - 1, currentIndex = start; currentIndex < end; currentIndex++)
    {
        // Move elements smaller than the pivot to the left side
        if (numbers[currentIndex] < pivotValue)
        {
            smallerIndex++;
            swap(numbers[smallerIndex], numbers[currentIndex]);
        }
    }

    // Put the pivot in its correct sorted position
    swap(numbers[end], numbers[smallerIndex + 1]);

    return smallerIndex + 1; // Return the pivot's final index
}

void sortQuickly(int numbers[], int start, int end) // Recursively sorts the array using Quick Sort
{
    if (start >= end)
    {
        return; // Stop recursion when the range contains zero or one element
    }

    int pivotPosition = placePivot(numbers, start, end); // Partition the array around the pivot

    sortQuickly(numbers, start, pivotPosition - 1); // Sort elements on the left of the pivot
    sortQuickly(numbers, pivotPosition + 1, end);   // Sort elements on the right of the pivot
}

int main()
{
    int totalElements; // Stores the size of the array
    cin >> totalElements;

    int numbers[totalElements]; // Array for storing user input

    for (int index = 0; index < totalElements; index++)
    {
        cin >> numbers[index]; // Read each element of the array
    }

    sortQuickly(numbers, 0, totalElements - 1); // Start the Quick Sort process

    for (int index = 0; index < totalElements; index++)
    {
        cout << numbers[index] << " "; // Display the sorted array
    }

    return 0;
}
