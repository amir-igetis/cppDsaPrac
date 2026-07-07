#include <bits/stdc++.h>
using namespace std;

long long countMajoritySubarrays(vector<int> &nums, int target)
{
    int n = nums.size();
    // represents the occurrence count of prefix sums -n, -(n-1), ..., 0, 1, ..., n, with index offset by n.
    vector<int> pre(n * 2 + 1);
    pre[n] = 1;
    int cnt = n;
    long ans = 0;
    long presum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == target)
        {
            presum += pre[cnt];
            ++cnt;
            ++pre[cnt];
        }
        else
        {
            --cnt;
            presum -= pre[cnt];
            ++pre[cnt];
        }
        ans += presum;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;
    cout << countMajoritySubarrays(nums, target) << endl;

    return 0;
}