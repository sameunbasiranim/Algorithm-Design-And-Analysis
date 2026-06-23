#include <bits/stdc++.h>
using namespace std;

int findLastOccurrence(int totalElements, int numbers[], int targetValue)
{
    int start = 0;                 // Starting position of the search range
    int end = totalElements - 1;   // Ending position of the search range

    int resultIndex = -1; // Stores the last found position of the target value

    while (start <= end)
    {
        int middle = (start + end) / 2; // Determine the middle position

        if (numbers[middle] == targetValue)
        {
            resultIndex = middle; // Save the current matching index
            start = middle + 1;   // Continue searching on the right side
        }
        else if (numbers[middle] > targetValue)
        {
            end = middle - 1; // Discard the right half of the search range
        }
        else
        {
            start = middle + 1; // Move to the right half of the array
        }
    }

    return resultIndex; // Return the last occurrence index
}

int main()
{
    int totalElements; // Stores the size of the array
    cin >> totalElements;

    int numbers[totalElements]; // Array for storing input values

    for (int position = 0; position < totalElements; position++)
    {
        cin >> numbers[position]; // Read each element of the array
    }

    int targetValue; // Value whose last occurrence will be searched
    cin >> targetValue;

    int foundPosition = findLastOccurrence(totalElements, numbers, targetValue); // Find the rightmost index

    if (foundPosition == -1)
    {
        cout << "Element Isn't Found\n"; // Displayed when the target value is absent
    }
    else
    {
        cout << "The index of " << targetValue << " is " << foundPosition; // Display the last occurrence index
    }

    return 0;
}
