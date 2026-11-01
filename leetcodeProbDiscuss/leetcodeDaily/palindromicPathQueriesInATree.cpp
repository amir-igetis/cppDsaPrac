#include <bits/stdc++.h>
using namespace std;

//  Binary Indexed Tree + Lowest Common Ancestor

/// Let n be the number of nodes, and q be the number of operations.
///
/// Time complexity: O((n+q)logn).
///
/// The DFS traversal takes O(n) time, and preprocessing the binary lifting table takes O(nlogn) time. Initializing the binary indexed tree requires n range XOR updates and takes O(nlogn) time. Each update operation requires one range XOR update, while each query operation requires one lowest common ancestor query and two binary indexed tree queries. Both types of operations take O(logn) time.
///
/// Space complexity: O(nlogn).
///
/// The binary lifting table requires O(nlogn) space. The adjacency list, DFS order, node depths, and binary indexed tree each require O(n) space. The recursive DFS call stack requires O(n) space in the worst case. The space required for the return value is excluded from the space complexity analysis.

class BIT
{
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x) { return x & -x; }

    void update(int x, int v)
    {
        while (x <= n)
        {
            tree[x] ^= v;
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int ret = 0;
        while (x)
        {
            ret ^= tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void updateRange(int l, int r, int v)
    {
        update(l, v);
        update(r + 1, v);
    }
};

class Solution
{
public:
    vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s,
                                vector<string> &queries)
    {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int LOG = 32 - __builtin_clz(n);
        vector<vector<int>> fa(n, vector<int>(LOG));
        vector<int> dep(n), l(n), r(n);
        int timer = 0;

        auto dfs = [&](auto &&dfs, int u, int p) -> void
        {
            l[u] = ++timer;
            fa[u][0] = p;
            for (int v : g[u])
            {
                if (v == p)
                {
                    continue;
                }
                dep[v] = dep[u] + 1;
                dfs(dfs, v, u);
            }
            r[u] = timer;
        };
        dfs(dfs, 0, 0);

        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }

        auto lca = [&](int u, int v)
        {
            if (dep[u] < dep[v])
            {
                swap(u, v);
            }
            int diff = dep[u] - dep[v];
            for (int i = 0; i < LOG; ++i)
            {
                if ((diff >> i) & 1)
                {
                    u = fa[u][i];
                }
            }
            if (u == v)
            {
                return u;
            }
            for (int i = LOG - 1; i >= 0; --i)
            {
                if (fa[u][i] != fa[v][i])
                {
                    u = fa[u][i];
                    v = fa[v][i];
                }
            }
            return fa[u][0];
        };

        BIT bit(n + 1);
        for (int i = 0; i < n; ++i)
        {
            bit.updateRange(l[i], r[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (string &q : queries)
        {
            stringstream ss(q);
            string op;
            ss >> op;
            if (op == "update")
            {
                int u;
                char c;
                ss >> u >> c;
                bit.updateRange(l[u], r[u],
                                (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
                s[u] = c;
            }
            else
            {
                int u, v;
                ss >> u >> v;
                int w = lca(u, v);
                int mask =
                    bit.query(l[u]) ^ bit.query(l[v]) ^ (1 << (s[w] - 'a'));
                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    string s = "aac";
    vector<string> queries = {"query 0 2", "update 1 b", "query 0 2"};
    Solution solution;
    vector<bool> result = solution.palindromePath(n, edges, s, queries);
    for (bool res : result)
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}