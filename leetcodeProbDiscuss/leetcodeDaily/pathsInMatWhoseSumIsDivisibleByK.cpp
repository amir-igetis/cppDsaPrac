#include <bits/stdc++.h>
using namespace std;

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();
    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n,
                                                       vector<int>(k, 0)));
    dp[0][0][grid[0][0] % k] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int r = 0; r < k; r++)
            {
                int currWays = dp[i][j][r];
                if (currWays == 0)
                    continue;

                if (i + 1 < m)
                {
                    int newR = (r + grid[i + 1][j]) % k;
                    dp[i + 1][j][newR] = (dp[i + 1][j][newR] + currWays) % MOD;
                }

                if (j + 1 < n)
                {
                    int newR = (r + grid[i][j + 1]) % k;
                    dp[i][j + 1][newR] = (dp[i][j + 1][newR] + currWays) % MOD;
                }
            }
        }
    }

    return dp[m - 1][n - 1][0];
}

int main()
{

    vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int k = 3;

    cout << numberOfPaths(grid, k) << endl;

    return 0;
}