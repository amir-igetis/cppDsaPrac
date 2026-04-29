#include <bits/stdc++.h>
using namespace std;

// recursion

int helperI(vector<int> &nums, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (nums[n - 1] <= sum)
    {
        return helperI(nums, n - 1, sum - nums[n - 1]) +
               helperI(nums, n - 1, sum);
    }
    else
    {
        return helperI(nums, n - 1, sum);
    }
}

int countOfSubsetSumII(vector<int> &nums, int sum)
{
    return helperI(nums, nums.size(), sum);
}

// memoization
int helper(vector<int> &nums, int sum, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (nums[n - 1] <= sum)
        dp[n][sum] = helper(nums, sum - nums[n - 1], n - 1, dp) +
                     helper(nums, sum, n - 1, dp);
    else
        dp[n][sum] = helper(nums, sum, n - 1, dp);
}

int countOfSubsetSumI(vector<int> &nums, int sum)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return helper(nums, sum, n, dp);
}

// bottom up
int countofSubsetSum(vector<int> &nums, int sum)
{

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] +
                           dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int sum = 10;

    // cout << countofSubsetSum(nums, sum) << endl;

    cout << countOfSubsetSumII(nums, sum) << endl;

    return 0;
}