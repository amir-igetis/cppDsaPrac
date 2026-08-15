#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int> &dp)
{

    // No stones -> current player loses
    if (n == 0)
        return false;

    if (dp[n] != -1)
        return dp[n];

    // Try every possible square number
    for (int i = 1; i * i <= n; i++)
    {

        int stones = i * i;

        // If opponent reaches a losing state,
        // current player wins.
        if (!solve(n - stones, dp))
        {
            return dp[n] = true;
        }
    }

    // No winning move exists
    return dp[n] = false;
}

bool winnerSquareGame(int n)
{

    vector<int> dp(n + 1, -1);

    return solve(n, dp);
}

bool winnerSquareGameI(int n)
{

    vector<bool> dp(n + 1, false);

    // dp[0] = false
    // No stones -> player cannot move -> loses

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j * j <= i; j++)
        {

            int square = j * j;

            // If we can move to a losing state,
            // current state is winning.
            if (!dp[i - square])
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{

    int n = 7;

    cout << (winnerSquareGame(n) ? "true" : "false") << endl;

    cout << (winnerSquareGameI(n) ? "true" : "false") << endl;

    return 0;
}
