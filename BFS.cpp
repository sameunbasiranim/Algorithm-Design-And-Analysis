#include <bits/stdc++.h>
using namespace std;

vector<int> graphAdj[1005];  // Stores adjacency list representation of graph
bool isVisited[1005];        // Tracks whether a node has been visited already

// Breadth First Search traversal
void bfsTraversal(int startNode)
{
    queue<int> q;                 // Queue to manage BFS order
    q.push(startNode);            // Start from the given node
    isVisited[startNode] = true;  // Mark starting node as visited

    while (!q.empty())
    {
        int currentNode = q.front(); // Get front node from queue
        q.pop();                     // Remove it from queue

        cout << currentNode << " "; // Process current node

        // Visit all adjacent nodes
        for (int neighbor : graphAdj[currentNode])
        {
            if (!isVisited[neighbor]) // If node is not visited
            {
                q.push(neighbor);        // Add to queue for future processing
                isVisited[neighbor] = true; // Mark as visited immediately
            }
        }
    }
}

int main()
{
    int nodes, edges;                 // Number of nodes and edges
    cin >> nodes >> edges;

    // Build the graph
    for (int i = 0; i < edges; i++)
    {
        int u, v;                     // Two connected nodes
        cin >> u >> v;

        graphAdj[u].push_back(v); // Add edge u -> v
        graphAdj[v].push_back(u); // Add edge v -> u (undirected graph)
    }

    // Initialize visited array
    memset(isVisited, false, sizeof(isVisited));

    // Start BFS from node 0
    bfsTraversal(0);

    return 0;
}
