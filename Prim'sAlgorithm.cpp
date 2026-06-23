#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int, int>; // stores (neighbor node, weight)

// Function to construct adjacency list of the graph
vector<vector<Edge>> createAdjList(int nodes, int edges)
{
    vector<vector<Edge>> graph(nodes); // adjacency list

    for (int i = 0; i < edges; i++)
    {
        int source, destination, cost;
        cin >> source >> destination >> cost; // read one edge

        graph[source].push_back({destination, cost}); // add edge u -> v
        graph[destination].push_back({source, cost}); // add edge v -> u (undirected graph)
    }

    return graph; // return built graph
}

// Function to display MST result
void displayMST(const vector<int> &parentNode, const vector<int> &minEdgeWeight)
{
    int totalCost = 0; // stores total weight of MST

    for (int node = 1; node < (int)parentNode.size(); node++)
    {
        cout << parentNode[node] << " -> " << node
             << " : " << minEdgeWeight[node] << '\n';

        totalCost += minEdgeWeight[node]; // accumulate cost
    }

    cout << "Total weight = " << totalCost << '\n';
}

// Prim’s Algorithm implementation
void runPrim(int nodes, vector<vector<Edge>> &graph,
             vector<int> &parentNode, vector<int> &minEdgeWeight)
{
    vector<bool> visited(nodes, false); // track nodes already included in MST

    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap; // (weight, node)

    minEdgeWeight[0] = 0;      // start from node 0
    minHeap.push({0, 0});      // push starting node into heap

    while (!minHeap.empty())
    {
        int currentNode = minHeap.top().second; // get node with smallest key
        minHeap.pop();                          // remove it from heap

        if (visited[currentNode])
            continue; // skip if already processed

        visited[currentNode] = true; // include node in MST

        for (auto [adjNode, weight] : graph[currentNode])
        {
            if (!visited[adjNode] && weight < minEdgeWeight[adjNode])
            {
                minEdgeWeight[adjNode] = weight;   // update best known edge
                parentNode[adjNode] = currentNode; // set parent
                minHeap.push({weight, adjNode});   // push updated entry
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<Edge>> graph = createAdjList(nodes, edges);

    vector<int> parentNode(nodes, -1);      // stores MST parent of each node
    vector<int> minEdgeWeight(nodes, INT_MAX); // stores minimum edge weight

    runPrim(nodes, graph, parentNode, minEdgeWeight); // compute MST
    displayMST(parentNode, minEdgeWeight);            // print MST result

    return 0;
}
