#include <bits/stdc++.h>
using namespace std;

// Adds an undirected edge between two vertices
void insertEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v); // connect u -> v
    graph[v].push_back(u); // connect v -> u (undirected graph)
}

// Displays adjacency list of the graph
void showGraph(const vector<int> graph[], int vertices)
{
    for (int vertex = 0; vertex < vertices; vertex++) // iterate through all vertices
    {
        cout << "\nVertex " << vertex << ":"; // print current vertex label

        for (int neighbor : graph[vertex]) // iterate through neighbors
        {
            cout << " -> " << neighbor; // show connection
        }

        cout << "\n"; // new line after each vertex
    }
}

int main()
{
    int vertices = 5; // total number of vertices in graph

    vector<int> graph[vertices]; // adjacency list structure

    // build graph connections
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 0, 3);
    insertEdge(graph, 1, 2);

    // display graph
    showGraph(graph, vertices);

    return 0;
}
