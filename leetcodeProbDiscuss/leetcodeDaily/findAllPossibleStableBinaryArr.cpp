#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        long long mod = 1e9 + 7;
        // dp0[i][j] = i zeros, j ones, ending in 0
        // dp1[i][j] = i zeros, j ones, ending in 1
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        // Base cases
        for (int i = 1; i <= min(zero, limit); ++i)
            dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j)
            dp1[0][j] = 1;

        for (int i = 1; i <= zero; ++i)
        {
            for (int j = 1; j <= one; ++j)
            {
                // To end in 0, we must have come from a state ending in 1
                for (int k = 1; k <= min(i, limit); ++k)
                {
                    dp0[i][j] = (dp0[i][j] + dp1[i - k][j]) % mod;
                }
                // To end in 1, we must have come from a state ending in 0
                for (int k = 1; k <= min(j, limit); ++k)
                {
                    dp1[i][j] = (dp1[i][j] + dp0[i][j - k]) % mod;
                }
            }
        }

        return (int)((dp0[zero][one] + dp1[zero][one]) % mod);
    }

    int numberOfStableArraysI(int zero, int one, int limit)
    {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1, 0));

        for (int i = 1; i <= min(zero, limit); ++i)
            dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j)
            dp1[0][j] = 1;

        for (int i = 1; i <= zero; ++i)
        {
            for (int j = 1; j <= one; ++j)
            {
                // Transition for dp0 (ending in 0)
                // New dp0[i][j] = dp0[i-1][j] + dp1[i-1][j] - dp1[i-limit-1][j]
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
                if (i > limit)
                {
                    // We subtract sequences that already had 'limit' zeros
                    // because adding another zero would violate the rule.
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + mod) % mod;
                }

                // Transition for dp1 (ending in 1)
                dp1[i][j] = (dp1[i][j - 1] + dp0[i][j - 1]) % mod;
                if (j > limit)
                {
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + mod) % mod;
                }
            }
        }

        return (int)((dp0[zero][one] + dp1[zero][one]) % mod);
    }
};

int main()
{
    int zero = 1, one = 1, limit = 2;
    Solution sol;
    cout << sol.numberOfStableArraysI(zero, one, limit) << endl;

    return 0;
}