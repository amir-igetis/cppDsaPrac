#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= target; j++)
        dp[0][j] = false;

    // fill DP
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] ||
                           dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

bool equalSumPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
    }
    if (sum % 2 != 0)
        return false;
    else if (sum % 2 == 0)
        return subsetSum(nums, sum / 2);
}

int main()
{

    vector<int> nums = {1, 5, 5, 7};
    cout << (equalSumPartition(nums) ? "True" : "False") << endl;

    return 0;
}