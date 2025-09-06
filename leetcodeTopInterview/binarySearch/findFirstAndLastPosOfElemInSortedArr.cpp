#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, first = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return first;
}

int findLast(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, last = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}

int main()
{

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}