#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> path(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            break;
        }
        else
        {
            path[i][0] = 1;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (obstacleGrid[0][j] == 1)
        {
            break;
        }
        else
        {
            path[0][j] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
                path[i][j] = 0;
            else
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }

    return path[n - 1][m - 1];
}

int main()
{

    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}