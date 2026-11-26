#include <bits/stdc++.h>
using namespace std;

// Enumeration

/// Let n be the length of nums, and M be its maximum element.
///
/// Time complexity: O(n^2logM).
///
/// There are O(n^2) subarrays. Computing the greatest common divisor and least common multiple for each takes O(logM) time, giving O(n^2logM) overall.
///
/// Space complexity: O(1).
///
/// Only a few auxiliary variables are used to maintain the running calculations.
class Solution
{
public:
    int maxLength(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long val = nums[j];
                prodVal = prodVal * val;
                gcdVal = __gcd(gcdVal, val);
                lcmVal = (lcmVal / __gcd(lcmVal, val)) * val;
                if (prodVal > gcdVal * lcmVal)
                {
                    break;
                }
                if (prodVal == gcdVal * lcmVal)
                {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};

// Sliding Window

/// Let n be the length of nums, and M be its maximum element.
///
/// Time complexity: O(nlogM).
///
/// Each endpoint of the sliding window traverses the array at most once. Computing the greatest common divisor each time an endpoint moves takes O(logM) time, so the total is O(nlogM).
///
/// Space complexity: O(1).
///
/// Only a few variables are used to maintain the sliding window state.
class SolutionI
{
public:
    int maxLength(vector<int> &nums)
    {
        int res = 2;
        int prodVal = 1;
        int n = nums.size();
        int start = 0, end = 0;

        while (end < n)
        {
            while (__gcd(prodVal, nums[end]) > 1)
            {
                prodVal /= nums[start];
                start++;
            }
            prodVal *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
    cout << Solution().maxLength(nums) << endl;
    cout << SolutionI().maxLength(nums) << endl;

    return 0;
}