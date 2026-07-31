#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int max = 0, secondMax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            secondMax = max;
            max = nums[i];
        }
        else if (nums[i] > secondMax)
        {
            secondMax = nums[i];
        }
    }
    return (max - 1) * (secondMax - 1);
}

int main()
{
    vector<int> nums = {3, 4, 5, 2};
    cout << maxProduct(nums) << endl;

    return 0;
}