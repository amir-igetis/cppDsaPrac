#include <bits/stdc++.h>
using namespace std;

// DP (Memoization) tc O(n^3) sc O(n^2)
int maxStones(vector<int> &suffixSum, int maxTillNow, int currIndex,
              vector<vector<int>> &memo)
{
    if (currIndex + 2 * maxTillNow >= suffixSum.size())
        return suffixSum[currIndex];
    if (memo[currIndex][maxTillNow] > 0)
        return memo[currIndex][maxTillNow];
    int res = INT_MAX;

    for (int i = 1; i <= 2 * maxTillNow; ++i)
    {
        res = min(res, maxStones(suffixSum, max(i, maxTillNow),
                                 currIndex + i, memo));
    }
    memo[currIndex][maxTillNow] = suffixSum[currIndex] - res;
    return memo[currIndex][maxTillNow];
}

int stoneGameII(vector<int> &piles)
{
    vector<vector<int>> memo(piles.size(), vector<int>(piles.size()));
    vector<int> suffixSum = piles;
    for (int i = suffixSum.size() - 2; i >= 0; --i)
        suffixSum[i] += suffixSum[i + 1];
    return maxStones(suffixSum, 1, 0, memo);
}

// DP (Tabulation) tc O(n^3) sc O(n^2)
int stoneGameII_I(vector<int> &piles)
{
    int length = piles.size();
    vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));

    // Store suffix sum for all possible suffix
    vector<int> suffixSum(length + 1, 0);
    for (int i = length - 1; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + piles[i];
    }

    // Initialize the dp array.
    for (int i = 0; i <= length; i++)
    {
        dp[i][length] = suffixSum[i];
    }

    // Start from the last index to store the future state first.
    for (int index = length - 1; index >= 0; index--)
    {
        for (int maxTillNow = length - 1; maxTillNow >= 1; maxTillNow--)
        {
            for (int X = 1; X <= 2 * maxTillNow && index + X <= length;
                 X++)
            {
                dp[index][maxTillNow] = max(
                    dp[index][maxTillNow],
                    suffixSum[index] - dp[index + X][max(maxTillNow, X)]);
            }
        }
    }
    return dp[0][1];
}

int main(int argc, char const *argv[])
{
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << stoneGameII(piles) << endl;
    return 0;
}
