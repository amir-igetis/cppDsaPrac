#include <bits/stdc++.h>
using namespace std;

// greedy tc O(n) and sc O(1)
long long maxTotalValue(vector<int> &nums, int k)
{
    int m1 = INT_MAX, m2 = INT_MIN;
    for (int x : nums)
    {
        m1 = min(m1, x);
        m2 = max(m2, x);
    }
    return (long long)(m2 - m1) * k;
}

int main()
{
    vector<int> nums = {1, 3, 2};
    int k = 2;
    cout << maxTotalValue(nums, k) << endl;
}