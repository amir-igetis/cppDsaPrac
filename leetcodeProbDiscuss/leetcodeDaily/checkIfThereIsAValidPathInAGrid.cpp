#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dirs = {
    {},
    {{0, -1}, {0, 1}},  // 1: left, right
    {{-1, 0}, {1, 0}},  // 2: up, down
    {{0, -1}, {1, 0}},  // 3: left, down
    {{0, 1}, {1, 0}},   // 4: right, down
    {{0, -1}, {-1, 0}}, // 5: left, up
    {{0, 1}, {-1, 0}}   // 6: right, up
};

bool hasValidPath(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        // auto [x, y] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1)
            return true;

        for (auto &d : dirs[grid[x][y]])
        {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                continue;

            // reverse connection check
            for (auto &back : dirs[grid[nx][ny]])
            {
                if (nx + back[0] == x && ny + back[1] == y)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    break;
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
    cout << (hasValidPath(grid) ? "True" : "False") << endl;

    return 0;
}