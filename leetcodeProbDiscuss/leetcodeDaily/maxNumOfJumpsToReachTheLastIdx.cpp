#include <bits/stdc++.h>
using namespace std;

int dfs(int i, vector<int> &nums, int target, vector<int> &memo)
{
    int n = nums.size();
    if (i == n - 1)
        return 0;
    if (memo[i] != INT_MIN)
        return memo[i];
    int res = INT_MIN;
    for (int j = i + 1; j < n; j++)
    {
        if (abs(nums[i] - nums[j]) <= target)
            res = max(res, dfs(j, nums, target, memo) + 1);
    }
    return memo[i] = res;
}

// memoization search tc O(n^2) & sc O(n)
int maximumJumps(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> memo(n, INT_MIN);
    int ans = dfs(0, nums, target, memo);
    return ans < 0 ? -1 : ans;
}

// Dynamic Programming tc O(n^2) & sc O(n)
int maximumJumpsI(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(n, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(nums[j] - nums[i]) <= target)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp[n - 1] < 0 ? -1 : dp[n - 1];
}

int main()
{
    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int target = 2;

    cout << maximumJumpsI(nums, target) << endl;

    return 0;
}