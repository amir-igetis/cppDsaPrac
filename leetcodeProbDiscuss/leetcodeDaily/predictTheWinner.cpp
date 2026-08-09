#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursion + Memoization

int maxDiff(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
        return dp[i][j] = nums[i];

    return dp[i][j] = max(
               nums[i] - maxDiff(i + 1, j, nums, dp),
               nums[j] - maxDiff(i, j - 1, nums, dp));
}

bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    // If number of elements is even, Player 1 can always win.
    if ((n & 1) == 0)
        return true;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return maxDiff(0, n - 1, nums, dp) >= 0;
}

// Bottom-Up DP (Space Optimized)
bool predictTheWinnerI(vector<int> &nums)
{
    int n = nums.size();

    if ((n & 1) == 0)
        return true;

    vector<int> dp(n);

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            dp[j] = max(
                nums[i] - dp[j],
                nums[j] - dp[j - 1]);
        }
    }

    return dp[n - 1] >= 0;
}

int main()
{
    vector<int> nums = {1, 5, 2};

    cout << (predictTheWinner(nums) ? "True" : "False") << endl;
    cout << (predictTheWinnerI(nums) ? "True" : "False") << endl;

    return 0;
}