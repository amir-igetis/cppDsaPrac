#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm

/// Let n be the number of nodes, m be the length of edges, and k be the maximum allowed number of consecutive identical characters.
///
/// Time complexity: O(nk+mklog(mk)).
///
/// Building the adjacency list takes O(n+m) time. Initializing the dis array takes O(nk) time. There are at most nk distinct states, and traversing outgoing edges across all states results in at most mk transitions. Each priority queue push and pop operation takes O(log(mk)) time, leading to an overall time complexity of O(nk+mklog(mk)).
///
/// Space complexity: O(nk+mk).
///
/// The adjacency list requires O(n+m) space, the dis array requires O(nk) space, and the priority queue holds at most O(mk) elements. Thus, the total auxiliary space complexity is O(nk+mk)
int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
{
    vector<vector<pair<int, int>>> g(n);
    for (auto &e : edges)
    {
        g[e[0]].emplace_back(e[1], e[2]);
    }

    vector<vector<long long>> dis(n, vector<long long>(k + 1, INT_MAX));
    // {shortest path length, node index, number of consecutive identical
    // letters at the end}
    priority_queue<tuple<long long, int, int>,
                   vector<tuple<long long, int, int>>, greater<>>
        pq;

    dis[0][1] = 0;
    pq.emplace(0, 0, 1);

    while (!pq.empty())
    {
        tuple<long long, int, int> top_elem = pq.top();
        pq.pop();

        long long d = get<0>(top_elem);
        int x = get<1>(top_elem);
        int cnt = get<2>(top_elem);

        if (d > dis[x][cnt])
        {
            continue;
        }
        if (x == n - 1)
        {
            return d;
        }

        for (auto &edge : g[x])
        {
            int y = edge.first;
            int w = edge.second;

            int new_cnt = labels[x] == labels[y] ? cnt + 1 : 1;
            if (new_cnt > k)
            {
                continue;
            }

            long long nd = d + w;
            if (nd < dis[y][new_cnt])
            {
                dis[y][new_cnt] = nd;
                pq.emplace(nd, y, new_cnt);
            }
        }
    }

    return -1;
}

int main()
{
    int n = 3, k = 1;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    string labels = "aab";
    cout << shortestPath(n, edges, labels, k) << endl;

    return 0;
}