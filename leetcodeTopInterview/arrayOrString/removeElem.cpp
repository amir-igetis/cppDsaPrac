#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int newIdx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[newIdx] = nums[i];
            newIdx++;
        }
    }
    return newIdx;
}

int main()
{

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << removeElement(nums, val) << endl;
}