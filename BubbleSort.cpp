#include <bits/stdc++.h>
using namespace std;

void performBubbleSort(int numbers[], int size) // Sorts the array using Bubble Sort technique
{
    for (int pass = 0; pass < size; pass++) // Number of passes through the array
    {
        for (int current = 0; current < size - pass - 1; current++) // Compare adjacent elements
        {
            if (numbers[current] > numbers[current + 1]) // If elements are in wrong order
            {
                swap(numbers[current], numbers[current + 1]); // Swap them to correct order
            }
        }
    }
}

int main()
{
    int totalSize; // Stores size of the array
    cin >> totalSize;

    int numbers[totalSize]; // Array to hold input values

    for (int index = 0; index < totalSize; index++) // Read array elements
    {
        cin >> numbers[index];
    }

    performBubbleSort(numbers, totalSize); // Sort the array

    for (int index = 0; index < totalSize; index++) // Print sorted array
    {
        cout << numbers[index] << " ";
    }

    return 0;
}
