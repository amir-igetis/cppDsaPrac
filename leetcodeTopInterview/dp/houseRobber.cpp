#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int prev2 = 0, prev1 = 0;
    for (int num : nums)
    {
        int temp = max(prev1, num + prev2);
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}

int main()
{

    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;

    return 0;
}