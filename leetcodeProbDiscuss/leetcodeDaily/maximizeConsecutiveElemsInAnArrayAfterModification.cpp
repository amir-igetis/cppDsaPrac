#include <bits/stdc++.h>
using namespace std;

int maxSelectedElements(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> dp;
    int ans = 0;
    for (int x : nums)
    {
        dp[x + 1] = max(dp[x + 1], dp[x] + 1);
        dp[x] = max(dp[x], dp[x - 1] + 1);
        ans = max(ans, max(dp[x], dp[x + 1]));
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 5, 1, 1};

    cout << maxSelectedElements(nums) << endl; // Output: 4
    return 0;
}