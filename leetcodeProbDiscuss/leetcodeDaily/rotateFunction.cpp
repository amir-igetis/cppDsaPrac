#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int> &nums)
{
    int f = 0, n = nums.size();
    int numSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < n; i++)
        f += i * nums[i];

    int res = f;
    for (int i = n - 1; i > 0; i--)
    {
        f += numSum - n * nums[i];
        res = max(res, f);
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 3, 2, 6};
    cout << maxRotateFunction(nums) << endl;

    return 0;
}