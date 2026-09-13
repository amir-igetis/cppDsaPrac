#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------
// Solution 1: 2D DP - Forward
// --------------------------------------------------

int numDistinct(string s, string t)
{

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            if (s[i - 1] == t[j - 1])
            {

                dp[i][j] =
                    dp[i - 1][j - 1] +
                    dp[i - 1][j];
            }
            else
            {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

// --------------------------------------------------
// Solution 2: 2D DP - Reverse
// --------------------------------------------------

/// Time Complexity: O(mn)
/// where m and n are the lengths of strings s and t, respectively. The 2D array dp has m+1 rows and n+1 columns, and each element in dp needs to be calculated.
/// Space Complexity: O(mn)
/// where m and n are the lengths of strings s and t, respectively. A 2D array dp with m+1 rows and n+1 columns is created.

int numDistinctI(string s, string t)
{

    int m = s.length();
    int n = t.length();

    if (m < n)
    {
        return 0;
    }

    vector<vector<int>> dp(
        m + 1,
        vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][n] = 1;
    }

    for (int i = m - 1; i >= 0; i--)
    {

        char sChar = s[i];

        for (int j = n - 1; j >= 0; j--)
        {

            char tChar = t[j];

            if (sChar == tChar)
            {

                dp[i][j] =
                    dp[i + 1][j + 1] +
                    dp[i + 1][j];
            }
            else
            {

                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return dp[0][0];
}

// --------------------------------------------------
// Solution 3: Space Optimized DP
// --------------------------------------------------

int numDistinctII(string s, string t)
{

    int m = s.length();
    int n = t.length();

    if (m < n)
    {
        return 0;
    }

    vector<int> dp(n + 1, 0);

    dp[n] = 1;

    for (int i = m - 1; i >= 0; i--)
    {

        char sChar = s[i];

        for (int j = 0; j < n; j++)
        {

            char tChar = t[j];

            if (sChar == tChar)
            {

                dp[j] =
                    dp[j + 1] +
                    dp[j];
            }
        }
    }

    return dp[0];
}

int main()
{

    string s = "rabbbit";
    string t = "rabbit";

    cout << "Solution 1: "
         << numDistinct(s, t)
         << endl;

    cout << "Solution 2: "
         << numDistinctI(s, t)
         << endl;

    cout << "Solution 3: "
         << numDistinctII(s, t)
         << endl;

    return 0;
}