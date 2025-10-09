#include <bits/stdc++.h>
using namespace std;

// using dijkstra
int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = true;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int res = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int t = cur[0], r = cur[1], c = cur[2];
        res = max(res, t);
        if (r == n - 1 && c == n - 1)
            return res;

        for (auto &d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc])
                continue;
            vis[nr][nc] = true;
            pq.push({grid[nr][nc], nr, nc});
        }
    }
    return res;
}

// Binary Search + Bredth first search

int n;
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool canReach(vector<vector<int>> &grid, int t)
{
    if (grid[0][0] > t)
        return false;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        // auto [r, c] = q.front();
        q.pop();
        if (r == n - 1 && c == n - 1)
            return true;
        for (auto &d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc])
                continue;
            if (grid[nr][nc] <= t)
            {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return false;
}

int swimInWaterI(vector<vector<int>> &grid)
{
    n = grid.size();
    int low = max(grid[0][0], grid[n - 1][n - 1]);
    int high = n * n - 1;
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canReach(grid, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};

    cout << swimInWaterI(grid) << endl;

    return 0;
}