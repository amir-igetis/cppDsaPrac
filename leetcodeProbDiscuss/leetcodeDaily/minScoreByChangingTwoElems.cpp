#include <bits/stdc++.h>
using namespace std;

// Sorting and Greedy

/// Let n be the length of the input array nums.
///
/// Time complexity: O(nlogn).
///
/// Sorting the array takes O(nlogn) time.
///
/// Space complexity: O(logn) or O(n).
///
/// The auxiliary space depends on the sorting implementation of the language (e.g., O(logn) for recursive call stacks in C++ or Java, or O(n) for temporary arrays in Python's Timsort).
int minimizeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return min(
        min(nums[n - 3] - nums[0], nums[n - 2] - nums[1]),
        nums[n - 1] - nums[2]);
}

// One Pass

/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// We traverse the array once, and each update involves at most a constant number of comparisons and assignments.
///
/// Space complexity: O(1).
///
/// We only use six variables to maintain the three smallest and three largest elements.
int minimizeSumI(vector<int> &nums)
{
    int mn1 = INT_MAX,
        mn2 = INT_MAX,
        mn3 = INT_MAX;
    int mx1 = INT_MIN,
        mx2 = INT_MIN,
        mx3 = INT_MIN;

    for (int x : nums)
    {
        if (x < mn1)
        {
            mn3 = mn2;
            mn2 = mn1;
            mn1 = x;
        }
        else if (x < mn2)
        {
            mn3 = mn2;
            mn2 = x;
        }
        else if (x < mn3)
        {
            mn3 = x;
        }

        if (x > mx1)
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = x;
        }
        else if (x > mx2)
        {
            mx3 = mx2;
            mx2 = x;
        }
        else if (x > mx3)
        {
            mx3 = x;
        }
    }

    return min(mx1 - mn3, min(mx2 - mn2, mx3 - mn1));
}

int main()
{
    vector<int> nums = {1, 4, 7, 8, 5};
    cout << minimizeSum(nums) << endl;
    cout << minimizeSumI(nums) << endl;

    return 0;
}