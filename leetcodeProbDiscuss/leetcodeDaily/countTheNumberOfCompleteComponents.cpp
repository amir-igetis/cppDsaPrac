#include <bits/stdc++.h>
using namespace std;

/*
==========================================================
1. DSU (Union Find) Solution
Time: O((n + m) * alpha(n))
Space: O(n)
==========================================================
*/

class DSU
{
public:
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.assign(n, -1);
        sz.assign(n, 1);
    }

    int find(int x)
    {
        if (parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return;

        if (sz[pa] >= sz[pb])
        {
            parent[pb] = pa;
            sz[pa] += sz[pb];
        }
        else
        {
            parent[pa] = pb;
            sz[pb] += sz[pa];
        }
    }

    int size(int x) { return sz[x]; }
};

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    DSU dsu(n);

    for (auto &e : edges)
        dsu.unite(e[0], e[1]);

    unordered_map<int, int> edgeCnt;

    for (auto &e : edges)
        edgeCnt[dsu.find(e[0])]++;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            int nodes = dsu.size(i);
            int expectedEdges = nodes * (nodes - 1) / 2;

            if (edgeCnt[i] == expectedEdges)
                ans++;
        }
    }

    return ans;
}

/*
==========================================================
2. BFS Solution
Time: O(n + m)
Space: O(n + m)
==========================================================
*/

int countCompleteComponentsI(int n, vector<vector<int>> &edges)
{

    vector<vector<int>> graph(n);

    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<int> vis(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (vis[i])
            continue;

        queue<int> q;
        q.push(i);
        vis[i] = 1;

        vector<int> component;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            component.push_back(node);

            for (int nei : graph[node])
            {
                if (!vis[nei])
                {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        bool complete = true;

        for (int node : component)
        {
            if ((int)graph[node].size() != (int)component.size() - 1)
            {
                complete = false;
                break;
            }
        }

        if (complete)
            ans++;
    }

    return ans;
}

/*
==========================================================
3. DFS Solution
Time: O(n + m)
Space: O(n + m)
==========================================================
*/

void dfs(int node,
         vector<vector<int>> &graph,
         vector<int> &vis,
         int &vertices,
         int &degreeSum)
{

    vis[node] = 1;
    vertices++;
    degreeSum += graph[node].size();

    for (int nei : graph[node])
    {
        if (!vis[nei])
            dfs(nei, graph, vis, vertices, degreeSum);
    }
}

int countCompleteComponentsII(int n, vector<vector<int>> &edges)
{

    vector<vector<int>> graph(n);

    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<int> vis(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (vis[i])
            continue;

        int vertices = 0;
        int degreeSum = 0;

        dfs(i, graph, vis, vertices, degreeSum);

        if (vertices * (vertices - 1) == degreeSum)
            ans++;
    }

    return ans;
}

/*
==========================================================
4. Adjacency Pattern Solution
Time: O(n + m log n)
Space: O(n + m)
==========================================================
*/

int countCompleteComponentsIII(int n, vector<vector<int>> &edges)
{

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
        graph[i].push_back(i);

    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    map<vector<int>, int> freq;

    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        freq[graph[i]]++;
    }

    int ans = 0;

    for (auto &it : freq)
    {
        if ((int)it.first.size() == it.second)
            ans++;
    }

    return ans;
}

int main()
{

    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    cout << countCompleteComponents(n, edges) << endl;    // Output: 3
    cout << countCompleteComponentsI(n, edges) << endl;   // Output: 3
    cout << countCompleteComponentsII(n, edges) << endl;  // Output: 3
    cout << countCompleteComponentsIII(n, edges) << endl; // Output: 3

    return 0;
}
