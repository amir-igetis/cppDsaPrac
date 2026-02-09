#include <bits/stdc++.h>
using namespace std;

int helper(int i, vector<int> &nums)
{
    int sum = 0;
    int count = 0;
    for (int j = i + 1; j < nums.size(); j++)
    {
        sum += nums[j];
        count++;
    }
    return (int)sum / count;
}

int dominantIndices(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dominant(n);
    int i = 0;
    while (i < n - 1)
    {
        dominant[i] = helper(i, nums);
        i++;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > dominant[i])
            ans++;
    }
    return ans;
}

int main()
{

    vector<int> nums = {
        0};
    cout << dominantIndices(nums) << endl;

    return 0;
}