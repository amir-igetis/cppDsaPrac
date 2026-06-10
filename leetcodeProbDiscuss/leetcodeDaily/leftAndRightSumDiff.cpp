#include <bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = leftSum;
        leftSum += nums[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = abs(rightSum - ans[i]);
        rightSum += nums[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {10, 4, 8, 3};
    vector<int> ans = leftRightDifference(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}