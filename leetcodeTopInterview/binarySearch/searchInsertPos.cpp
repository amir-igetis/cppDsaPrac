#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int main()
{

    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << searchInsert(nums, target) << endl;

    return 0;
}