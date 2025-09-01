#include <bits/stdc++.h>
using namespace std;

// giving TLE
long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();

    // Calculate original profit
    long long originalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        originalProfit += (long long)strategy[i] * prices[i];
    }

    long long maxProfitAchievable = originalProfit;

    // Try all possible starting positions for the k-length window
    for (int start = 0; start <= n - k; start++)
    {
        long long profitChange = 0;

        // Calculate profit change for this modification
        // First k/2 elements: change to 0 (hold)
        for (int i = start; i < start + k / 2; i++)
        {
            profitChange -= (long long)strategy[i] * prices[i]; // Remove original contribution
            // New contribution is 0 * prices[i] = 0, so no addition needed
        }

        // Last k/2 elements: change to 1 (sell)
        for (int i = start + k / 2; i < start + k; i++)
        {
            profitChange -= (long long)strategy[i] * prices[i]; // Remove original contribution
            profitChange += (long long)1 * prices[i];           // Add new contribution (1 * prices[i])
        }

        long long newProfit = originalProfit + profitChange;
        maxProfitAchievable = max(maxProfitAchievable, newProfit);
    }

    return maxProfitAchievable;
}

// accepted
long long maxProfitI(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();

    // Calculate original profit
    long long originalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        originalProfit += (long long)strategy[i] * prices[i];
    }

    // Create arrays for profit change if position i becomes hold(0) or sell(1)
    vector<long long> holdChange(n), sellChange(n);
    for (int i = 0; i < n; i++)
    {
        holdChange[i] = (0 - strategy[i]) * (long long)prices[i];
        sellChange[i] = (1 - strategy[i]) * (long long)prices[i];
    }

    // Create prefix sums for efficient range sum queries
    vector<long long> holdPrefix(n + 1, 0), sellPrefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        holdPrefix[i + 1] = holdPrefix[i] + holdChange[i];
        sellPrefix[i + 1] = sellPrefix[i] + sellChange[i];
    }

    long long maxProfitChange = 0; // Option to not modify at all

    // Try each possible starting position for the k-length window
    for (int start = 0; start <= n - k; start++)
    {
        // Sum of holdChange for first k/2 elements [start, start + k/2 - 1]
        long long holdSum = holdPrefix[start + k / 2] - holdPrefix[start];

        // Sum of sellChange for last k/2 elements [start + k/2, start + k - 1]
        long long sellSum = sellPrefix[start + k] - sellPrefix[start + k / 2];

        long long totalChange = holdSum + sellSum;
        maxProfitChange = max(maxProfitChange, totalChange);
    }

    return originalProfit + maxProfitChange;
}

int main()
{

    vector<int> prices = {4, 2, 8};

    vector<int> strategy = {-1, 0, 1};

    int k = 2;

    cout
        << maxProfit(prices, strategy, k) << endl;

    return 0;
}