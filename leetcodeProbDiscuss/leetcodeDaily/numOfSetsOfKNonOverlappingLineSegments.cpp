#include <bits/stdc++.h>
using namespace std;

// dp
/// Let n be the number of points and k be the target number of line segments.
///
/// Time complexity: O(nk).
///
/// There are O(nk) states, and each state takes O(1) time to compute.
///
/// Space complexity: O(n).
///
/// The rolling array dp and the prefix sums array prefixSums both require O(n) space.
const int MOD = 1000000007;
int numberOfSets(int n, int k)
{
    vector<int> dp(n), prefixSums(n + 1);
    for (int j = 0; j < n; j++)
    {
        dp[j] = 1;
        prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
    }
    for (int i = 1; i <= k; i++)
    {
        dp[0] = 0;
        for (int j = 1; j < n; j++)
        {
            dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
        }
        for (int j = 0; j < n; j++)
        {
            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }
    }
    return dp[n - 1];
}

// combinatorics
/// Let M=10^9 +7 be the modulus.
///
/// Time complexity: O(k+logM).
///
/// Computing the binomial coefficient takes O(k+logM) time.
///
/// Space complexity: O(1).
// const int MOD = 1000000007;

long long quickPow(long long a, long long e)
{
    long long result = 1;
    while (e > 0)
    {
        if (e & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return result;
}

int numberOfSetsI(int n, int k)
{
    int m = 2 * k;
    long long numerator = 1, denominator = 1;
    for (int i = 1; i <= m; i++)
    {
        numerator = numerator * (n + k - i) % MOD;
        denominator = denominator * i % MOD;
    }
    return numerator * quickPow(denominator, MOD - 2) % MOD;
}

int main()
{
    int n = 4, k = 2;
    cout << numberOfSets(n, k) << endl;
    cout << numberOfSetsI(n, k) << endl;

    return 0;
}