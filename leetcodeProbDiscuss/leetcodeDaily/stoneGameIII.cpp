#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &stoneValue, vector<int> &dp)
{
    int n = stoneValue.size();

    if (i >= n)
        return 0;

    if (dp[i] != INT_MIN)
        return dp[i];

    int sum = 0;
    int best = INT_MIN;

    for (int k = 0; k < 3 && i + k < n; k++)
    {
        sum += stoneValue[i + k];
        best = max(best, sum - solve(i + k + 1, stoneValue, dp));
    }

    return dp[i] = best;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();

    vector<int> dp(n, INT_MIN);

    int diff = solve(0, stoneValue, dp);

    if (diff > 0)
        return "Alice";
    if (diff < 0)
        return "Bob";
    return "Tie";
}

// bottom up

string stoneGameIII_I(vector<int> &stoneValue)
{

    int n = stoneValue.size();

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {

        int sum = 0;
        dp[i] = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++)
        {

            sum += stoneValue[i + k];

            dp[i] = max(dp[i], sum - dp[i + k + 1]);
        }
    }

    if (dp[0] > 0)
        return "Alice";
    if (dp[0] < 0)
        return "Bob";

    return "Tie";
}

// space optimized

string stoneGameIII_II(vector<int> &stoneValue)
{

    int n = stoneValue.size();

    vector<int> dp(4, 0);

    for (int i = n - 1; i >= 0; i--)
    {

        int sum = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++)
        {

            sum += stoneValue[i + k];

            best = max(best, sum - dp[(i + k + 1) % 4]);
        }

        dp[i % 4] = best;
    }

    if (dp[0] > 0)
        return "Alice";
    if (dp[0] < 0)
        return "Bob";

    return "Tie";
}

int main()
{

    vector<int> stoneValue = {1, 2, 3, 7};
    cout << stoneGameIII(stoneValue) << endl;
    cout << stoneGameIII_I(stoneValue) << endl;
    cout << stoneGameIII_II(stoneValue) << endl;

    return 0;
}
