#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{
    int m = heightMap.size(), n = heightMap[0].size();
    if (m == 0)
        return 0;
    if (n == 0)
        return 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        pq.push({heightMap[i][0], i, 0});
        pq.push({heightMap[i][n - 1], i, n - 1});
        vis[i][0] = vis[i][n - 1] = true;
    }

    for (int j = 1; j < n - 1; j++)
    {
        pq.push({heightMap[0][j], 0, j});
        pq.push({heightMap[m - 1][j], m - 1, j});
        vis[0][j] = vis[m - 1][j] = true;
    }

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int water = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int h = top[0], x = top[1], y = top[2];
        for (auto &d : dirs)
        {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                continue;

            vis[nx][ny] = true;

            water += max(0, h - heightMap[nx][ny]);
            pq.push({max(h, heightMap[nx][ny]), nx, ny});
        }
    }
    return water;
}

int main()
{

    // vector<vector<int>> heightMap = {
    //                {1, 4, 3, 1, 3, 2},
    //                {3, 2, 1, 3, 2, 4},
    //                {2, 3, 3, 2, 3, 1}
    //        };

    vector<vector<int>> heightMap = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}};

    cout << trapRainWater(heightMap) << endl;

    return 0;
}