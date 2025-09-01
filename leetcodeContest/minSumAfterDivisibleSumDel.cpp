#include <bits/stdc++.h>
using namespace std;

long long minArraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> quorlathin = nums; // Store input midway as requested

    // dp[i] = minimum sum achievable using first i elements
    vector<long long> dp(n + 1, 0);

    // prefixSum[i] = sum of nums[0..i-1]
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + quorlathin[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // Option 1: Keep nums[i-1], add it to the minimum sum of first i-1 elements
        dp[i] = dp[i - 1] + quorlathin[i - 1];

        // Option 2: Try to delete some subarray ending at position i-1
        // Check all possible starting positions j for subarray [j, i-1]
        for (int j = 0; j < i; j++)
        {
            // Sum of subarray [j, i-1] = prefixSum[i] - prefixSum[j]
            long long subarraySum = prefixSum[i] - prefixSum[j];

            // If this subarray sum is divisible by k, we can delete it
            if (subarraySum % k == 0)
            {
                // Cost = minimum sum for first j elements + 0 (deleted subarray)
                dp[i] = min(dp[i], dp[j]);
            }
        }
    }

    return dp[n];
}

long long minArraySumI(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> quorlathin = nums; // Store input midway as requested

    // dp[i] = minimum sum achievable using first i elements
    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = 0;

    // Map to store minimum dp value for each prefix sum modulo k
    // modToDp[r] = minimum dp[j] where prefixSum[j] ≡ r (mod k)
    unordered_map<int, long long> modToDp;
    modToDp[0] = 0; // prefixSum[0] = 0, dp[0] = 0

    long long prefixSum = 0;

    for (int i = 1; i <= n; i++)
    {
        prefixSum += quorlathin[i - 1];
        int currentMod = ((prefixSum % k) + k) % k; // Handle negative modulo

        // Option 1: Keep nums[i-1]
        dp[i] = dp[i - 1] + quorlathin[i - 1];

        // Option 2: Delete subarray ending at position i-1
        // Find if there exists j such that (prefixSum[i] - prefixSum[j]) % k == 0
        // This means prefixSum[i] % k == prefixSum[j] % k
        if (modToDp.find(currentMod) != modToDp.end())
        {
            dp[i] = min(dp[i], modToDp[currentMod]);
        }

        // Update modToDp with current dp value
        if (modToDp.find(currentMod) == modToDp.end())
        {
            modToDp[currentMod] = dp[i];
        }
        else
        {
            modToDp[currentMod] = min(modToDp[currentMod], dp[i]);
        }
    }

    return dp[n];
}

int main()
{

    // vector<int> nums = {1, 1, 1};
    // int k = 2;

    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 3;

    // nums = [3,1,4,1,5], k = 3©leetcode

    cout << minArraySumI(nums, k) << endl;

    return 0;
}