#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];   // Adjacency list representation of the graph
bool visited[1005];        // Tracks whether a node has been visited

// Depth First Search traversal
void depthFirstSearch(int node)
{
    cout << node << " ";        // Process current node
    visited[node] = true;       // Mark node as visited

    // Explore all adjacent nodes
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor]) // If neighbor is not visited yet
        {
            depthFirstSearch(neighbor); // Visit it recursively
        }
    }
}

int main()
{
    int nodes, edges;              // Number of nodes and edges in the graph
    cin >> nodes >> edges;

    // Read edges and build adjacency list
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v); // Add edge u -> v
        graph[v].push_back(u); // Add edge v -> u (undirected graph)
    }

    // Initialize visited array to false
    memset(visited, false, sizeof(visited));

    // Start DFS from node 0
    depthFirstSearch(0);

    return 0;
}
