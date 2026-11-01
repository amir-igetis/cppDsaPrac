#include <bits/stdc++.h>
using namespace std;

// DP

/// Let m and n be the numbers of rows and columns in grid, respectively, and V be the number of possible XOR values.
///
/// Time complexity: O(m⋅n⋅V).
///
/// The outer two loops of the dynamic programming traversal take O(m⋅n) time. For each cell, we iterate over the V possible XOR values, taking O(V) time for the state transitions.
///
/// Space complexity: O(n⋅V).
///
/// There are O(m⋅n⋅V) states. With the rolling array optimization, dp only needs to maintain the states for one row, requiring O(n⋅V) space.
int minCost(vector<vector<int>> &grid)
{
    const int m = grid.size();
    const int n = grid[0].size();

    vector<array<bool, 1024>> dp(n);
    array<bool, 1024> next{};

    dp[0][grid[0][0]] = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            const int value = grid[i][j];
            next.fill(false);

            for (int k = 0; k < 1024; k++)
            {
                if (dp[j][k] || (j > 0 && dp[j - 1][k]))
                {
                    next[k ^ value] = true;
                }
            }

            dp[j] = next;
        }
    }

    for (int k = 0; k < 1024; k++)
    {
        if (dp[n - 1][k])
        {
            return k;
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    cout << minCost(grid) << endl;

    return 0;
}