#include <bits/stdc++.h>
using namespace std;

// greedy

/// Let n be the length of nums.
///
/// Time complexity: O(n).
///
/// We traverse the array twice: once to find the maximum and once to sum the differences.
///
/// Space complexity: O(1).
///
/// We need only a constant number of variables to store the maximum and the answer.
int minMoves(vector<int> &nums)
{
    int mx = nums[0];
    for (int x : nums)
    {
        mx = max(mx, x);
    }
    int ans = 0;
    for (auto &x : nums)
    {
        ans += mx - x;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 3};
    cout << minMoves(nums) << endl;

    return 0;
}