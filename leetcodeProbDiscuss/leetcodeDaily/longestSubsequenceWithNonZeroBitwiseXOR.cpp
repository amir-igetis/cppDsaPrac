#include <bits/stdc++.h>
using namespace std;

// classification Discussion
/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// Space complexity: O(1).
int longestSubsequence(vector<int> &nums)
{
    int n = nums.size();
    int totalXor = 0;
    bool allZero = true;

    for (int x : nums)
    {
        totalXor ^= x;
        if (x > 0)
        {
            allZero = false;
        }
    }

    if (totalXor > 0)
    {
        return n;
    }

    return allZero ? 0 : n - 1;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << longestSubsequence(nums) << endl; // Output: 3
    return 0;
}