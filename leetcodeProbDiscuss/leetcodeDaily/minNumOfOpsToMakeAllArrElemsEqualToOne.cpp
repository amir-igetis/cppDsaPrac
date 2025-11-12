#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int ones = 0;

    for (int num : nums)
    {
        if (num == 1)
            ones++;
    }

    if (ones > 0)
        return n - ones;

    int minLen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int g = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            g = gcd(g, nums[j]);
            if (g == 1)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }

    if (minLen == INT_MAX)
        return -1;

    return (minLen - 1) + (n - 1);
}

int main()
{

    vector<int> nums = {2, 10, 6, 14};
    cout << minOperations(nums) << endl;

    return 0;
}