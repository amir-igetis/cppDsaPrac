#include <bits/stdc++.h>
using namespace std;

// traversal

/// Let n be the length of nums and m be the largest number in nums.
///
/// Time complexity: O(nlogm).
///
/// Calculating the digit sum by repeatedly removing the last digit takes O(logm) time.
///
/// Space complexity: O(1).
int smallestIndex(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int digitSum = 0;

        while (num > 0)
        {
            digitSum += num % 10;
            num /= 10;
        }

        if (digitSum == i)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 2};
    cout << smallestIndex(nums) << endl;

    return 0;
}