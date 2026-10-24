#include <bits/stdc++.h>
using namespace std;

// Traverse and Compute the Bitwise AND

/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// We only need to traverse the array once, performing constant-time checks and bitwise operations for each element.
///
/// Space complexity: O(1).
///
/// Only a constant amount of extra space is used.

class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == i)
                continue;
            res &= nums[i];
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    vector<int> nums = {0, 3, 2, 1};
    Solution sol;
    cout << sol.sortPermutation(nums) << endl;

    return 0;
}