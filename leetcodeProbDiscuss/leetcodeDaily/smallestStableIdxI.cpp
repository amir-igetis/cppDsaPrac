#include <bits/stdc++.h>
using namespace std;

int firstStableIndexI(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], nums[i]);

    vector<int> suffix(n);
    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = min(suffix[i + 1], nums[i]);

    for (int i = 0; i < n; i++)
    {
        long instability = (long)prefix[i] - suffix[i];
        if (instability <= k)
            return i;
    }
    return -1;
}

// enumeration

/// Let n be the length of the array nums.
///
/// Time complexity: O(n^2).
///
/// When enumerating each index, it takes O(n) time to compute the prefix maximum and suffix minimum values.
///
/// Space complexity: O(1).
int firstStableIndex(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int maxValue = nums[i], minValue = nums[i];
        for (int j = 0; j < i; ++j)
        {
            maxValue = max(maxValue, nums[j]);
        }
        for (int j = i + 1; j < n; ++j)
        {
            minValue = min(minValue, nums[j]);
        }
        if (maxValue - minValue <= k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;
    cout << firstStableIndex(nums, k) << endl;
    cout << firstStableIndexI(nums, k) << endl;

    return 0;
}