#include <bits/stdc++.h>
using namespace std;

bool canPartitionGrid(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    long long total = 0;
    for (auto &row : grid)
    {
        for (auto &val : row)
            total += val;
    }

    if (total % 2 != 0)
        return false;

    long long target = total / 2;

    long long rowSum = 0;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
            rowSum += grid[i][j];

        if (rowSum == target)
            return true;
    }

    long long colSum = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
            colSum += grid[i][j];

        if (colSum == target)
            return true;
    }

    return false;
}

int main()
{

    vector<vector<int>> grid = {{1, 4}, {2, 3}};
    cout << (canPartitionGrid(grid) ? "True" : "False") << endl;

    return 0;
}