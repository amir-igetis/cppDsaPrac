#include <bits/stdc++.h>
using namespace std;

// using recursion

int helper(int ind, int buy, int cap, vector<int> &prices)
{
    if (ind == prices.size() || cap == 0)
        return 0;

    if (buy == 1)
    {
        // Choice: buy or skip
        int take = -prices[ind] + helper(ind + 1, 0, cap, prices);
        int skip = helper(ind + 1, 1, cap, prices);
        return max(take, skip);
    }
    else
    {
        // Choice: sell or skip
        int sell = prices[ind] + helper(ind + 1, 1, cap - 1, prices);
        int skip = helper(ind + 1, 0, cap, prices);
        return max(sell, skip);
    }
}

int maxProfitI(int k, vector<int> &prices)
{
    return helper(0, 1, k, prices);
}

// using recursion memoization
int helper(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (ind == prices.size() || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit = 0;
    if (buy)
    {
        // Two choices: Buy or Skip
        profit = max(
            -prices[ind] + helper(ind + 1, 0, cap, prices, dp), // Buy
            helper(ind + 1, 1, cap, prices, dp)                 // Skip
        );
    }
    else
    {
        // Two choices: Sell or Skip
        profit = max(
            prices[ind] + helper(ind + 1, 1, cap - 1, prices, dp), // Sell
            helper(ind + 1, 0, cap, prices, dp)                    // Skip
        );
    }

    return dp[ind][buy][cap] = profit;
}

int maxProfitII(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    return helper(0, 1, k, prices, dp);
}

// using top down DP
int maxProfit(int k, vector<int> &prices)
{
    int profit = 0, n = prices.size();
    vector<vector<int>> dp(k + 1, vector<int>(n));
    for (int i = 1; i <= k; i++)
    {
        int maxV = INT_MIN;
        for (int j = 1; j < prices.size(); j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (dp[i - 1][j - 1] - prices[j - 1] > maxV)
                maxV = dp[i - 1][j - 1] - prices[j - 1];

            dp[i][j] = max(dp[i][j], maxV + prices[j]);
        }
    }

    return dp[k][n - 1];
}

int main()
{

    int k = 2;
    vector<int> prices = {2, 4, 2};
    cout << maxProfit(k, prices) << endl;

    return 0;
}