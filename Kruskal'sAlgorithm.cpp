#include <bits/stdc++.h>
using namespace std;

class EdgeInfo
{
public:
    int fromNode, toNode, weight; // stores an edge (u, v, w)
};

const int MAX_NODES = 1000; // maximum supported nodes

int parentDSU[MAX_NODES];   // DSU parent array
vector<EdgeInfo> edgeList;  // stores all graph edges
vector<EdgeInfo> mstEdges;  // stores selected MST edges

// Initialize DSU structure
void initializeDSU(int nodes)
{
    for (int node = 1; node <= nodes; node++)
    {
        parentDSU[node] = node; // each node starts as its own parent
    }
}

// Find representative parent with path compression
int findParent(int node)
{
    if (parentDSU[node] == node)
        return node;

    return parentDSU[node] = findParent(parentDSU[node]);
}

// Union two sets, return false if already connected
bool unionNodes(int nodeA, int nodeB)
{
    nodeA = findParent(nodeA);
    nodeB = findParent(nodeB);

    if (nodeA == nodeB)
        return false;

    parentDSU[nodeA] = nodeB; // merge sets
    return true;
}

// Read graph input
void inputGraph(int &nodes, int &edges)
{
    cin >> nodes >> edges;
    edgeList.resize(edges);

    for (int i = 0; i < edges; i++)
    {
        cin >> edgeList[i].fromNode >> edgeList[i].toNode >> edgeList[i].weight;
    }
}

// Print MST result
void showMST(int totalWeight)
{
    cout << "MST total weight: " << totalWeight << '\n';
    cout << "Edges in MST:\n";

    for (auto &edge : mstEdges)
    {
        cout << edge.fromNode << " -- " << edge.toNode
             << " (weight " << edge.weight << ")\n";
    }
}

// Comparator for sorting edges by weight
bool compareEdges(const EdgeInfo &a, const EdgeInfo &b)
{
    return a.weight < b.weight;
}

// Kruskal's algorithm implementation
int runKruskal(int nodes)
{
    sort(edgeList.begin(), edgeList.end(), compareEdges);

    initializeDSU(nodes);

    int totalWeight = 0;
    mstEdges.clear();

    for (auto edge : edgeList)
    {
        if (unionNodes(edge.fromNode, edge.toNode))
        {
            totalWeight += edge.weight;
            mstEdges.push_back(edge);
        }
    }

    return totalWeight;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges;

    inputGraph(nodes, edges);

    int resultWeight = runKruskal(nodes);

    showMST(resultWeight);

    return 0;
}
