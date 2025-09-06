#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
            start = mid + 1;
        else
            end = mid;
    }

    return nums[start];
}

int main()
{

    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;

    return 0;
}