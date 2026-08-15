#include <bits/stdc++.h>
using namespace std;

// Simulation + Prefix Sum
/// Time complexity: O(n).
///
//// Finding the longest ordered prefix takes O(n) time, and finding the first value that does not appear in nums takes O(n) time in the worst case.
///
/// Space complexity: O(n).
///
/// The hash set requires O(n) auxiliary space.
int missingInteger(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> num_set(nums.begin(), nums.end());
    int total = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            total += nums[i];
        }
        else
        {
            break;
        }
    }

    while (num_set.count(total))
    {
        total += 1;
    }

    return total;
}

// Simulation + Series Sum Formula
/// Time complexity: O(n).
///
/// Finding the longest ordered prefix takes O(n) time, and finding the first value that does not appear in nums takes O(n) time in the worst case.
///
/// Space complexity: O(n).
///
/// The hash set requires O(n) auxiliary space.
int missingIntegerI(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> num_set(nums.begin(), nums.end());
    int prefix_len = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            prefix_len += 1;
        }
        else
        {
            break;
        }
    }

    int total = (nums[prefix_len - 1] + nums[0]) * prefix_len / 2;
    while (num_set.count(total))
    {
        total += 1;
    }

    return total;
}

int main()
{
    vector<int> nums = {1, 2, 3, 8, 9};
    cout << missingInteger(nums) << endl;
    cout << missingIntegerI(nums) << endl;

    return 0;
}