#include <bits/stdc++.h>
using namespace std;

// dp

/// Let n be the length of the array nums.
///
/// Time complexity: O(nk).
///
/// For each of the n elements in nums, we iterate through all k possible remainders to perform the state transition.
///
/// Space complexity: O(k).
///
/// The rolling array dp (and ndp) requires O(k) auxiliary space.
vector<long long> resultArray(vector<int> nums, int k)
{
    int n = nums.size();
    vector<long long> result(k, 0);
    vector<long long> dp(k, 0); // Initial state: no elements have been processed, so no non-empty subarray exists.

    for (int i = 0; i < n; i++)
    {
        vector<long long> ndp(k, 0); // Current-layer state (rolling array).
        ndp[nums[i] % k]++;
        for (int r = 0; r < k; r++)
        {
            ndp[(int)(((long)r * nums[i]) % k)] += dp[r];
        }
        dp = ndp; // Update the state.
        // Accumulate the answer.
        for (int r = 0; r < k; r++)
        {
            result[r] += dp[r];
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    vector<long long> result = resultArray(nums, k);
    for (long long val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
