#include <bits/stdc++.h>
using namespace std;

bool isIncreasing(vector<int> &nums, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] <= nums[i - 1])
            return false;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i + 2 * k <= n; i++)
    {
        if (isIncreasing(nums, i, i + k - 1) && isIncreasing(nums, i + k, i + 2 * k - 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int k = 3;
    cout << (hasIncreasingSubarrays(nums, k) ? "True" : "False") << endl;

    return 0;
}