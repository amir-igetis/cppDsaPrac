#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int subsequencePairCount(vector<int> &nums)
{
    int m = 0;
    for (auto &num : nums)
    {
        m = max(m, num);
    }

    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    dp[0][0] = 1;

    for (auto &num : nums)
    {
        vector<vector<int>> ndp(m + 1, vector<int>(m + 1));

        for (int j = 0; j <= m; j++)
        {
            int divisor1 = __gcd(j, num);
            for (int k = 0; k <= m; k++)
            {
                int val = dp[j][k];
                if (val == 0)
                {
                    continue;
                }
                int divisor2 = __gcd(k, num);
                ndp[j][k] = (ndp[j][k] + val) % MOD;
                ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
            }
        }
        dp = ndp;
    }

    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (ans + dp[j][j]) % MOD;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << subsequencePairCount(nums) << endl;
    return 0;
}