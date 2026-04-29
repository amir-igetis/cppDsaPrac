#include <bits/stdc++.h>
using namespace std;

using vll = std::vector<long long>;

long long maximumScore(vector<vector<int>> &grid)
{
    int n = grid[0].size();
    if (n == 1)
    {
        return 0;
    }

    vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
    vector<vll> prevMax(n + 1, vll(n + 1, 0));
    vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
    vector<vll> colSum(n, vll(n + 1, 0));

    for (int c = 0; c < n; c++)
    {
        for (int r = 1; r <= n; r++)
        {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int currH = 0; currH <= n; currH++)
        {
            for (int prevH = 0; prevH <= n; prevH++)
            {
                if (currH <= prevH)
                {
                    long long extraScore =
                        colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] =
                        std::max(dp[i][currH][prevH],
                                 prevSuffixMax[prevH][0] + extraScore);
                }
                else
                {
                    long long extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] = std::max(
                        {dp[i][currH][prevH], prevSuffixMax[prevH][currH],
                         prevMax[prevH][currH] + extraScore});
                }
            }
        }

        for (int currH = 0; currH <= n; currH++)
        {
            prevMax[currH][0] = dp[i][currH][0];
            for (int prevH = 1; prevH <= n; prevH++)
            {
                long long penalty =
                    (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH])
                                    : 0;
                prevMax[currH][prevH] =
                    std::max(prevMax[currH][prevH - 1],
                             dp[i][currH][prevH] - penalty);
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for (int prevH = n - 1; prevH >= 0; prevH--)
            {
                prevSuffixMax[currH][prevH] = std::max(
                    prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
            }
        }
    }

    long long ans = 0;
    for (int k = 0; k <= n; k++)
    {
        ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
    }

    return ans;
}

long long maximumScoreI(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<long long> dpW(n + 1), dpWo(n + 1), ndpW(n + 1), ndpWo(n + 1), cSum(n + 1), ncSum(n + 1);

    for (int i = 0; i < n; i++)
    {
        cSum[i + 1] = cSum[i] + grid[i][0];
    }

    long long dpWm = 0, ndpWm;

    for (int j = 1; j < n; j++)
    {
        ndpWm = 0;

        for (int i = 0; i < n; i++)
        {
            ncSum[i + 1] = ncSum[i] + grid[i][j];
        }

        for (int i = 0; i <= n; i++)
        {
            long long woA = dpWm, wA = 0;

            for (int k = 0; k <= i; k++)
            {
                long long x = dpWo[k] + cSum[i] - cSum[k];
                wA = max(wA, x);
                woA = max(woA, x);
            }

            for (int k = i + 1; k <= n; k++)
            {
                wA = max(wA, dpW[k] + ncSum[k] - ncSum[i]);
            }
            ndpW[i] = wA;
            ndpWo[i] = woA;
            if (ndpWm < wA)
                ndpWm = wA;
        }
        swap(dpW, ndpW);
        swap(dpWo, ndpWo);
        swap(ncSum, cSum);
        dpWm = ndpWm;
    }
    return *max_element(dpW.begin(), dpW.end());
}

int main()
{

    vector<vector<int>> grid = {{0, 0, 0, 0, 0},
                                {0, 0, 3, 0, 0},
                                {0, 1, 0, 0, 0},
                                {5, 0, 0, 3, 0},
                                {0, 0, 0, 0, 2}};

    cout << maximumScore(grid) << endl;

    return 0;
}