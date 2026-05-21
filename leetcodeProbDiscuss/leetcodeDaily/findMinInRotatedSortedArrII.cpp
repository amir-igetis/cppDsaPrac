#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return -1;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        while (nums[start] == nums[end] && start != end)
        {
            start++;
        }
        int mid = start + (end - start) / 2;
        if (mid > 0 && nums[mid] < nums[mid - 1])
        {
            return nums[mid];
        }
        else if (nums[start] <= nums[mid] && nums[mid] > nums[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> nums = {1, 3, 5};
    cout << findMin(nums) << endl;

    return 0;
}
