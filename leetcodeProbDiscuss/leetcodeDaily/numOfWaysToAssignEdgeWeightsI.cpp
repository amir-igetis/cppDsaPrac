#include <bits/stdc++.h>
using namespace std;

static constexpr int mod = 1e9 + 7;
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
        {
            res = 1ll * res * x % mod;
        }
        x = 1ll * x * x % mod;
    }
    return res;
}
int dfs(vector<vector<int>> &g, int x, int f)
{
    int max_dep = 0;
    for (auto &y : g[x])
    {
        if (y == f)
        {
            continue;
        }
        max_dep = max(max_dep, dfs(g, y, x) + 1);
    }
    return max_dep;
}

// Depth-First Search + Mathematics tc & sc O(n)
int assignEdgeWeights(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector<int>> g(n + 1);
    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int max_dep = dfs(g, 1, 0);
    return qpow(2, max_dep - 1);
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    cout << assignEdgeWeights(edges) << endl;

    return 0;
}