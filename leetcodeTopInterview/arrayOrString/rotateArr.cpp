#include <bits/stdc++.h>
using namespace std;

void reverseHelper(vector<int> &nums, int l, int r)
{
    while (l <= r)
    {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r--;
    }
}

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();

    reverseHelper(nums, 0, nums.size() - 1);
    reverseHelper(nums, 0, k - 1);
    reverseHelper(nums, k, nums.size() - 1);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}