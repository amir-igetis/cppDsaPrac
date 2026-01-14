#include <bits/stdc++.h>
using namespace std;

// LCS-based approach
int minimumDeleteSum(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build LCS ASCII sum DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int sum1 = 0, sum2 = 0;
    for (char c : s1)
        sum1 += c;
    for (char c : s2)
        sum2 += c;

    return sum1 + sum2 - 2 * dp[n][m];
}

// Direct delete-cost DP
int minimumDeleteSumI(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(
                    dp[i - 1][j] + s1[i - 1],
                    dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "sea";
    string s2 = "eat";
    cout << minimumDeleteSumI(s1, s2) << endl;
    return 0;
}
