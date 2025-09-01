#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
        return;

    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int numIslands = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                numIslands++;
                dfs(grid, i, j);
            }
        }
    }
    return numIslands;
}

int numIslandsI(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;

    int numIsland = 0;
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                numIsland++;
                queue<vector<int>> q;
                q.push({i, j});
                grid[i][j] = '0';

                while (!q.empty())
                {
                    vector<int> point = q.front();
                    q.pop();
                    int x = point[0], y = point[1];

                    for (vector<int> dir : direc)
                    {
                        int newX = x + dir[0], newY = y + dir[1];
                        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1')
                        {
                            q.push({newX, newY});
                            grid[newX][newY] = '0';
                        }
                    }
                }
            }
        }
    }
    return numIsland;
}

int main()
{

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout << numIslandsI(grid) << endl;

    return 0;
}