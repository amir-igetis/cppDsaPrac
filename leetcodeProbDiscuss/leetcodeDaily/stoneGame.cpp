#include <bits/stdc++.h>
using namespace std;

/// Time Complexity: O(N^2), where N is the number of piles.
/// Space Complexity: O(N^2), the space used storing the intermediate results of
/// each subgame.

// Dynamic Programming

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();

    // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]].
    // int[][] dp = new int[n + 2][n + 2];
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int size = 1; size <= n; ++size)
        for (int i = 0; i + size <= n; ++i)
        {
            int j = i + size - 1;
            int parity = (j + i + n) % 2; // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
            else
                dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
        }

    return dp[1][n] > 0;
}

bool stoneGameI(vector<int> &piles)
{
    int N = piles.size();

    // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
    int dp[N + 2][N + 2];
    memset(dp, 0, sizeof(dp));

    for (int size = 1; size <= N; ++size)
        for (int i = 0, j = size - 1; j < N; ++i, ++j)
        {
            int parity = (j + i + N) % 2; // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
            else
                dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
        }

    return dp[1][N] > 0;
}

/// tc and sc O(1)

// mathematical
bool stoneGameII(vector<int> &piles)
{
    return true;
}

int main()
{

    vector<int> piles = {5, 3, 4, 5};
    cout << (stoneGame(piles) ? "True" : "False") << endl;
    cout << (stoneGameI(piles) ? "True" : "False") << endl;
    cout << (stoneGameII(piles) ? "True" : "False") << endl;

    return 0;
}
