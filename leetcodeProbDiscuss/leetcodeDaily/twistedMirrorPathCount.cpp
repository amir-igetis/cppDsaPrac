#include <bits/stdc++.h>
using namespace std;

// DP
int uniquePaths(vector<vector<int>> &grid)
{
    constexpr int MOD = 1'000'000'007;

    int m = grid.size();
    int n = grid[0].size();

    // f[i][j][0]: enter (i, j) by moving down
    // f[i][j][1]: enter (i, j) by moving right
    vector<vector<array<long long, 2>>> f(
        m, vector<array<long long, 2>>(n, {0, 0}));

    f[0][0][0] = 1;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i > 0)
            {
                if (grid[i - 1][j] == 0)
                {
                    f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % MOD;
                }
                else
                {
                    f[i][j][0] = f[i - 1][j][1];
                }
            }

            if (j > 0)
            {
                if (grid[i][j - 1] == 0)
                {
                    f[i][j][1] = (f[i][j - 1][0] + f[i][j - 1][1]) % MOD;
                }
                else
                {
                    f[i][j][1] = f[i][j - 1][0];
                }
            }
        }
    }

    return (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD;
}

// Rolling Array

/// Let m and n be the numbers of rows and columns in the grid, respectively.
///
/// Time complexity: O(mn).
///
/// There are m×n cells, each maintaining 2 arrival states. Every state transition involves a constant number of operations (O(1)), leading to an overall time complexity of O(mn).
///
/// Space complexity: O(mn) for the standard 3D dynamic programming approach, or O(n) if using the rolling array optimization.
///
/// The standard dynamic programming table f stores two states for each cell, requiring O(mn) auxiliary space. The rolling array optimization maintains only an n×2 array across row iterations, reducing auxiliary space to O(n)
int uniquePathsI(vector<vector<int>> &grid)
{
    const int MOD = 1'000'000'007;
    int m = grid.size(), n = grid[0].size();

    vector<array<long long, 2>> f(n, {0, 0});
    f[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                if (grid[i - 1][j] == 0)
                {
                    f[j][0] = (f[j][0] + f[j][1]) % MOD;
                }
                else
                {
                    f[j][0] = f[j][1];
                }
            }

            if (j > 0)
            {
                if (grid[i][j - 1] == 0)
                {
                    f[j][1] = (f[j - 1][0] + f[j - 1][1]) % MOD;
                }
                else
                {
                    f[j][1] = f[j - 1][0];
                }
            }
        }
    }

    return (f[n - 1][0] + f[n - 1][1]) % MOD;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    cout << uniquePaths(grid) << endl;
    cout << uniquePathsI(grid) << endl;

    return 0;
}