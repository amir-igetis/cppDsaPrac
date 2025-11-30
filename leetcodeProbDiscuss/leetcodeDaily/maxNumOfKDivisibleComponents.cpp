#include <bits/stdc++.h>
using namespace std;

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<vector<int>> adj(n);

    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int components = 0;

    function<int(int, int)> dfs = [&](int node, int parent) -> int
    {
        long long sum = values[node];

        for (int nei : adj[node])
        {
            if (nei == parent)
                continue;
            sum += dfs(nei, node);
        }

        if (sum % k == 0)
        {
            components++;
            return 0;
        }

        return sum % k;
    };

    dfs(0, -1);

    return components;
}

// leetcode soln

int dfs(int currentNode, int parentNode, vector<int> adjList[],
        vector<int> &nodeValues, int k, int &componentCount)
{
    // Step 1: Initialize sum for the current subtree
    int sum = 0;

    // Step 2: Traverse all neighbors
    for (auto neighborNode : adjList[currentNode])
    {
        if (neighborNode != parentNode)
        {
            // Recursive call to process the subtree rooted at the neighbor
            sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                       componentCount);
            sum %= k; // Ensure the sum stays within bounds
        }
    }

    // Step 3: Add the value of the current node to the sum
    sum += nodeValues[currentNode];

    // Step 4: Check if the sum is divisible by k
    sum %= k;
    if (sum == 0)
        componentCount++;

    // Step 5: Return the computed sum for the current subtree
    return sum;
}

int maxKDivisibleComponentsI(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<int> adjList[n];
    for (auto edge : edges)
    {
        int node1 = edge[0];
        int node2 = edge[1];
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    // Step 2: Initialize component count
    int componentCount = 0;

    // Step 3: Start DFS traversal from node 0
    dfs(0, -1, adjList, values, k, componentCount);

    // Step 4: Return the total number of components
    return componentCount;
}

int main()
{

    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};
    int k = 6, n = 5;

    cout << maxKDivisibleComponentsI(n, edges, values, n) << endl;

    return 0;
}