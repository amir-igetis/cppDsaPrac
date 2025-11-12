#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (auto &s : strs)
    {
        int zeros = 0, ones = 0;
        for (auto &ch : s)
        {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }
        for (int i = m; i >= zeros; i--)
        {
            for (int j = n; j >= ones; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}

int main()
{

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    cout << findMaxForm(strs, m, n) << endl;

    return 0;
}