#include <bits/stdc++.h>
using namespace std;

int countValidSelectionsI(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    vector<int> left(n), right(n);

    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + nums[i - 1];
        right[n - i - 1] = right[n - i] + nums[n - i];
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            continue;
        if (left[i] == right[i])
            res += 2;
        else if (abs(left[i] - right[i]) == 1)
            res += 1;
    }

    return res;
}

// optimized soln
int countValidSelections(vector<int> &nums)
{
    int len = nums.size(), count = 0, left = 0, right = 0;
    for (auto &i : nums)
    {
        right += i;
    }

    for (int i = 0; i < len; i++)
    {
        left += nums[i];
        right -= nums[i];
        if (nums[i] != 0)
            continue;

        if (left == right)
            count += 2;

        if (abs(left - right) == 1)
            count++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 0, 2, 0, 3};
    cout << countValidSelections(nums) << endl;

    return 0;
}