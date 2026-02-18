#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &nums, int pos)
{
    if (pos >= nums.size() - 1)
        return 0;
    if (nums[pos] == 0)
        return INT_MAX;
    int minStep = INT_MAX;
    for (int jump = 1; jump <= nums[pos]; jump++)
    {
        int subRes = minJumps(nums, pos + jump);
        if (subRes != INT_MAX)
            minStep = min(minStep, 1 + subRes);
    }
    return minStep;
}

// main func tc O(2 ^n) & sc O(n)
// brute force
int jump(vector<int> &nums)
{
    return minJumps(nums, 0);
}

// better approach tc O(n^2) & o(n)
int jumpI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= nums[i] && i + j < n; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    return dp[n - 1];
}

// optimal O(n) & sc O(1)
int jumpII(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;
    int jumps = 0, currEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}

int main()
{

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jumpII(nums) << endl;

    return 0;
}