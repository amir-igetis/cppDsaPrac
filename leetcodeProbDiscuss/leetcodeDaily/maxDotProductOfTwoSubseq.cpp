#include <bits/stdc++.h>
using namespace std;

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int takeBoth = nums1[i - 1] * nums2[j - 1];
            if (dp[i - 1][j - 1] > 0)
            {
                takeBoth += dp[i - 1][j - 1];
            }

            dp[i][j] = max({takeBoth,
                            dp[i - 1][j],
                            dp[i][j - 1]});
        }
    }

    return dp[n][m];
}

int main()
{

    vector<int> nums1 = {2, 1, -1, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << maxDotProduct(nums1, nums2) << endl;
    return 0;
}