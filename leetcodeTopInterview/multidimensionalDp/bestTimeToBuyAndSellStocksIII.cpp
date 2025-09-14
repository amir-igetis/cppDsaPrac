#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    vector<vector<int>> dp(3, vector<int>(2, 0));

    for (int i = 0; i <= 2; i++)
        dp[i][1] = -1e9;

    for (int price : prices)
    {
        for (int i = 1; i <= 2; i++)
        {
            dp[i][0] = max(dp[i][0], dp[i][1] + price);
            dp[i][1] = max(dp[i][1], dp[i - 1][0] - price);
        }
    }

    return max({dp[0][0], dp[1][0], dp[2][0]});
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;

    return 0;
}