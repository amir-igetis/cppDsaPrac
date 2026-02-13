#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &coin, int rem, vector<int> &dp)
{
    if (rem == 0)
        return 0;
    if (rem < 0)
        return -1;
    if (dp[rem] != -2)
        return dp[rem];
    int mini = INT_MAX;
    for (int i : coin)
    {
        int res = helper(coin, rem - i, dp);
        if (res >= 0 && res < mini)
            mini = 1 + res;
    }
    dp[rem] = (mini == INT_MAX) ? -1 : mini;
    return dp[rem];
}

// tc O(n * t) & sc O(n * t) + o(n)
int coinChange(vector<int> &coin, int amount)
{
    vector<int> dp(amount + 1, -2);
    return helper(coin, amount, dp);
}

// tabulation (dp) approach tc & sc O(n * t)
int coinChangeI(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{

    vector<int> coin = {1, 2, 5};
    int amount = 11;
    cout << coinChangeI(coin, amount) << endl;

    return 0;
}