#include <bits/stdc++.h>
using namespace std;

const int SIZE = 6; // fixed matrix dimension (6x6)

// Initialize adjacency matrix with 0
void clearMatrix(int matrix[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            matrix[row][col] = 0; // no edges initially
        }
    }
}

// Add an undirected edge between two nodes
void connectNodes(int matrix[][SIZE], int nodeA, int nodeB)
{
    matrix[nodeA][nodeB] = 1; // edge A -> B
    matrix[nodeB][nodeA] = 1; // edge B -> A (undirected)
}

// Print adjacency matrix
void displayMatrix(int matrix[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++) // fixed inner loop condition
        {
            cout << matrix[row][col] << " ";
        }
        cout << "\n"; // move to next row
    }
}

int main()
{
    int matrix[SIZE][SIZE]; // adjacency matrix

    clearMatrix(matrix); // initialize all values to 0

    // build graph edges
    connectNodes(matrix, 0, 3);
    connectNodes(matrix, 0, 4);
    connectNodes(matrix, 1, 4);
    connectNodes(matrix, 2, 5);
    connectNodes(matrix, 2, 3);

    displayMatrix(matrix); // print final graph

    return 0;
}
