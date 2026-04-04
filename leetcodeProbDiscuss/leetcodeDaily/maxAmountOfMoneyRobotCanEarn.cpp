#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &coins, vector<vector<vector<int>>> &memo, int i, int j, int k)
{
    int m = coins.size(), n = coins[0].size();

    if (i >= m || j >= n)
        return INT_MIN;

    int x = coins[i][j];

    // destination
    if (i == m - 1 && j == n - 1)
    {
        return (k > 0) ? max(0, x) : x;
    }

    if (memo[i][j][k] != INT_MIN)
        return memo[i][j][k];

    // not neutralize
    int res = max(
                  dfs(coins, memo, i + 1, j, k),
                  dfs(coins, memo, i, j + 1, k)) +
              x;

    // neutralize
    if (k > 0 && x < 0)
    {
        res = max(res,
                  max(
                      dfs(coins, memo, i + 1, j, k - 1),
                      dfs(coins, memo, i, j + 1, k - 1)));
    }

    return memo[i][j][k] = res;
}

// Memoization Search tc & sc O(M * N)

int maximumAmount(vector<vector<int>> &coins)
{
    int m = coins.size(), n = coins[0].size();
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

    return dfs(coins, memo, 0, 0, 2);
}

// Dynamic Programming tc O(M * N) & sc O(M * N)

int maximumAmountI(vector<vector<int>> &coins)
{
    int m = coins.size(), n = coins[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN / 2)));

    dp[0][0][0] = coins[0][0];
    for (int k = 1; k <= 2; k++)
    {
        dp[0][0][k] = max(coins[0][0], 0);
    }

    // first row
    for (int j = 1; j < n; j++)
    {
        dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
        for (int k = 1; k <= 2; k++)
        {
            dp[0][j][k] = max(
                dp[0][j - 1][k] + coins[0][j],
                dp[0][j - 1][k - 1] + max(coins[0][j], 0));
        }
    }

    // first column
    for (int i = 1; i < m; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
        for (int k = 1; k <= 2; k++)
        {
            dp[i][0][k] = max(
                dp[i - 1][0][k] + coins[i][0],
                dp[i - 1][0][k - 1] + max(coins[i][0], 0));
        }
    }

    // rest grid
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];

            for (int k = 1; k <= 2; k++)
            {
                dp[i][j][k] = max(
                    max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i][j],
                    max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
            }
        }
    }

    return dp[m - 1][n - 1][2];
}

// Dynamic Programming tc O(M * N) & sc O(n)

int maximumAmountII(vector<vector<int>> &coins)
{
    int n = coins[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN / 2));

    for (int i = 0; i < 3; i++)
    {
        dp[1][i] = 0;
    }

    for (auto &row : coins)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = row[j - 1];

            dp[j][2] = max(
                max(dp[j - 1][2] + x, dp[j][2] + x),
                max(dp[j - 1][1], dp[j][1]));

            dp[j][1] = max(
                max(dp[j - 1][1] + x, dp[j][1] + x),
                max(dp[j - 1][0], dp[j][0]));

            dp[j][0] = max(dp[j - 1][0], dp[j][0]) + x;
        }
    }

    return dp[n][2];
}

int main()
{

    vector<vector<int>> coins = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
    cout << maximumAmountI(coins) << endl;

    return 0;
}
