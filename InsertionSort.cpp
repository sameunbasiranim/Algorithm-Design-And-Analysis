#include <bits/stdc++.h>
using namespace std;

void performInsertionSort(int values[], int size) // Sorts the array using insertion sort logic
{
    int currentValue; // Holds the element currently being inserted into the sorted portion

    for (int i = 0; i < size; i++) // Traverse through all elements
    {
        currentValue = values[i]; // Store the element to be positioned correctly
        int previousIndex = i - 1; // Start checking from the previous element

        // Shift elements that are greater than currentValue one position ahead
        while (previousIndex >= 0 && values[previousIndex] > currentValue)
        {
            values[previousIndex + 1] = values[previousIndex]; // Move element one step right
            previousIndex--; // Move backward in the sorted portion
        }

        // Insert the current element into its correct position
        values[previousIndex + 1] = currentValue;
    }
}

int main()
{
    int totalSize; // Stores number of elements in the array
    cin >> totalSize;

    int values[totalSize]; // Array to store input numbers

    for (int index = 0; index < totalSize; index++) // Read array elements
    {
        cin >> values[index];
    }

    performInsertionSort(values, totalSize); // Sort the array

    for (int index = 0; index < totalSize; index++) // Print sorted array
    {
        cout << values[index] << " ";
    }

    return 0;
}
