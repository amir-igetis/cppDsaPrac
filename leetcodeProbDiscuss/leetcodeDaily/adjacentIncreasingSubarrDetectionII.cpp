#include <bits/stdc++.h>
using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;

    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    int maxK = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int k = min(left[i], right[i + 1]);
        maxK = max(maxK, k);
    }

    return maxK;
}

int main()
{
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    cout << maxIncreasingSubarrays(nums) << endl;

    return 0;
}