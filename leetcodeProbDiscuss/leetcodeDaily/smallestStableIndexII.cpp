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

// Prefix Maximum + Suffix Minimum

/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// The minimum suffix preprocessing and the forward traversal each require O(n) time.
///
/// Space complexity: O(n).
///
/// The space required for the array minValue.
int firstStableIndex(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> minValue(n);
    minValue[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        minValue[i] = min(minValue[i + 1], nums[i]);
    }

    int maxValue = 0;
    for (int i = 0; i < n; ++i)
    {
        maxValue = max(maxValue, nums[i]);
        if (maxValue - minValue[i] <= k)
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

    return 0;
}