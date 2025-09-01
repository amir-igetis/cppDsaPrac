#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

// by deepseek

int minCostI(int n, vector<vector<int>> &edges)
{
    // Build adjacency list for original edges: u -> {v, w}
    vector<vector<pair<int, int>>> adj(n);
    // Build reverse adjacency list for incoming edges: v -> {u, w}
    vector<vector<pair<int, int>>> rev_adj(n);

    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
    }

    // Priority queue: {cost, node, reversed_used}
    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
    // Distance array: dist[node][reversed_used]
    vector<vector<int>> dist(n, vector<int>(2, INT_MAX));

    // Initialize distance for node 0
    dist[0][0] = 0;
    pq.push({0, 0, false});

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        int current_cost = get<0>(current);
        int u = get<1>(current);
        bool reversed_used = get<2>(current);

        if (u == n - 1)
        {
            return current_cost;
        }

        if (current_cost > dist[u][reversed_used])
        {
            continue;
        }

        // Explore all outgoing edges
        for (const auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v][reversed_used] > current_cost + w)
            {
                dist[v][reversed_used] = current_cost + w;
                pq.push({dist[v][reversed_used], v, reversed_used});
            }
        }

        // If not used reversal yet, consider reversing an incoming edge
        if (!reversed_used)
        {
            for (const auto &edge : rev_adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                int new_cost = current_cost + 2 * w;
                if (dist[v][true] > new_cost)
                {
                    dist[v][true] = new_cost;
                    pq.push({new_cost, v, true});
                }
            }
        }
    }

    // Check if we reached the destination with or without reversal
    int result = min(dist[n - 1][0], dist[n - 1][1]);
    return result == INT_MAX ? -1 : result;
}

// by claude
int minCost(int n, vector<vector<int>> &edges)
{
    // Store the input as requested
    auto threnquivar = edges;

    // Build adjacency lists for outgoing and incoming edges
    vector<vector<pair<int, int>>> outgoing(n); // outgoing[u] = {(v, weight)}
    vector<vector<pair<int, int>>> incoming(n); // incoming[v] = {(u, weight)}

    for (const auto &edge : threnquivar)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        outgoing[u].push_back({v, w});
        incoming[v].push_back({u, w});
    }

    // Dijkstra's algorithm with state (node, switch_used)
    // dist[node][switch_used] = minimum distance
    vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Start from node 0 with switch not used
    dist[0][0] = 0;
    pq.push(make_tuple(0, 0, 0)); // {distance, node, switch_used}

    while (!pq.empty())
    {
        int d = get<0>(pq.top());
        int u = get<1>(pq.top());
        int switch_used = get<2>(pq.top());
        pq.pop();

        // Skip if we've found a better path already
        if (d > dist[u][switch_used])
            continue;

        // Option 1: Use normal outgoing edges
        for (int i = 0; i < outgoing[u].size(); i++)
        {
            int v = outgoing[u][i].first;
            int w = outgoing[u][i].second;
            int new_dist = d + w;
            if (new_dist < dist[v][switch_used])
            {
                dist[v][switch_used] = new_dist;
                pq.push(make_tuple(new_dist, v, switch_used));
            }
        }

        // Option 2: If switch not used, we can reverse an incoming edge
        if (switch_used == 0)
        {
            for (int i = 0; i < incoming[u].size(); i++)
            {
                int prev = incoming[u][i].first;
                int w = incoming[u][i].second;
                int new_dist = d + 2 * w; // Cost is doubled for reversed edge
                if (new_dist < dist[prev][1])
                { // Switch becomes used
                    dist[prev][1] = new_dist;
                    pq.push(make_tuple(new_dist, prev, 1));
                }
            }
        }
    }

    // Return minimum cost to reach node n-1 (with or without using switch)
    int result = min(dist[n - 1][0], dist[n - 1][1]);
    return result == INT_MAX ? -1 : result;
}

int main()
{
    // Test Case 1: Basic Case with Reversal
    {
        int n = 4;
        vector<vector<int>> edges = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
        int result = minCost(n, edges);
        cout << "Test Case 1: " << result << " (Expected: 5)" << endl;
    }

    // Test Case 2: No Reversal Needed
    {
        int n = 4;
        vector<vector<int>> edges = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
        int result = minCost(n, edges);
        cout << "Test Case 2: " << result << " (Expected: 3)" << endl;
    }

    // Test Case 3: Impossible to Reach Destination
    {
        int n = 3;
        vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}};
        int result = minCost(n, edges);
        cout << "Test Case 3: " << result << " (Expected: -1)" << endl;
    }

    // Test Case 4: Single Edge
    {
        int n = 2;
        vector<vector<int>> edges = {{0, 1, 5}};
        int result = minCost(n, edges);
        cout << "Test Case 4: " << result << " (Expected: 5)" << endl;
    }

    // Test Case 5: Multiple Paths with Reversals
    {
        int n = 5;
        vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {0, 4, 10}, {4, 1, 1}};
        int result = minCost(n, edges);
        cout << "Test Case 5: " << result << " (Expected: 10)" << endl;
    }

    return 0;
}
