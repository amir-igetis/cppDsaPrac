#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<long long> minPref(k, LLONG_MAX);

    long long pref = 0, ans = LLONG_MIN;
    minPref[0] = 0;

    for (int i = 0; i < n; i++)
    {
        pref += nums[i];
        int r = (i + 1) % k;

        if (minPref[r] != LLONG_MAX)
            ans = max(ans, pref - minPref[r]);

        minPref[r] = min(minPref[r], pref);
    }

    return ans;
}

int main()
{

    vector<int> nums = {
        -1, -2, -3, -4, -5};
    int k = 4;

    cout << maxSubarraySum(nums, k) << endl;

    return 0;
}