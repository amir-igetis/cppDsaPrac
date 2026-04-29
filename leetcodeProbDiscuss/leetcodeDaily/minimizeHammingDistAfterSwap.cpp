#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rankArr;

// Find with path compression
int findParent(int x)
{
    if (parent[x] != x)
    {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

// Union by rank
void Union(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if (px == py)
        return;

    if (rankArr[px] < rankArr[py])
    {
        swap(px, py);
    }

    parent[py] = px;

    if (rankArr[px] == rankArr[py])
    {
        rankArr[px]++;
    }
}

int minimumHammingDistance(vector<int> &source, vector<int> &target,
                           vector<vector<int>> &allowedSwaps)
{
    int n = source.size();

    // Proper reset (IMPORTANT FIX)
    parent.assign(n, 0);
    rankArr.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // Build DSU
    for (auto &p : allowedSwaps)
    {
        Union(p[0], p[1]);
    }

    // Map: root -> {value -> count}
    unordered_map<int, unordered_map<int, int>> sets;

    for (int i = 0; i < n; i++)
    {
        int root = findParent(i);
        sets[root][source[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int root = findParent(i);

        if (sets[root][target[i]] > 0)
        {
            sets[root][target[i]]--;
        }
        else
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};

    cout << minimumHammingDistance(source, target, allowedSwaps) << endl;

    return 0;
}