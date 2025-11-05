#include <bits/stdc++.h>
using namespace std;

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<int>> grid(m, vector<int>(n));
    for (auto &i : walls)
    {
        grid[i[0]][i[1]] = -1;
    }

    for (auto &j : guards)
    {
        grid[j[0]][j[1]] = -2;
    }

    for (auto &j : guards)
    {
        int x = j[0], y = j[1];
        //            upside
        for (int i = x - 1; i >= 0; i--)
        {
            if (grid[i][y] == -1 || grid[i][y] == -2)
                break;
            grid[i][y] = 1;
        }
        //            down
        for (int i = x + 1; i < m; i++)
        {
            if (grid[i][y] == -1 || grid[i][y] == -2)
                break;
            grid[i][y] = 1;
        }
        //            right
        for (int k = y - 1; k >= 0; k--)
        {
            if (grid[x][k] == -1 || grid[x][k] == -2)
                break;
            grid[x][k] = 1;
        }
        //            left
        for (int k = y + 1; k < n; k++)
        {
            if (grid[x][k] == -1 || grid[x][k] == -2)
                break;
            grid[x][k] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                count++;
        }
    }
    return count;
}

int main()
{

    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}}, walls = {{0, 1}, {2, 2}, {1, 4}};

    cout << countUnguarded(m, n, guards, walls) << endl;

    return 0;
}