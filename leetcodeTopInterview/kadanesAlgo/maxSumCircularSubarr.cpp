
#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &nums, bool findMax)
{
    int currSum = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (findMax)
            currSum = max(nums[i], currSum + nums[i]);
        else
            currSum = min(nums[i], currSum + nums[i]);

        res = findMax ? max(res, currSum) : min(res, currSum);
    }

    return res;
}

int maxSubarraySumCircular(vector<int> &nums)
{
    int totSum = 0;
    int maxkadane = kadane(nums, true);
    int minkadane = kadane(nums, false);

    for (int num : nums)
        totSum += num;
    if (totSum == minkadane)
        return maxkadane;

    return max(maxkadane, totSum - minkadane);
}

int main()
{
    vector<int> nums = {1, -2, 3, -2};

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}