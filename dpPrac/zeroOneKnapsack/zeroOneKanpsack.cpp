#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] <= w)
        return max(val[n - 1] +
                       knapsack(wt, val, w - wt[n - 1], n - 1),
                   knapsack(wt, val, w, n - 1));
    else if (wt[n - 1] > w)
        return knapsack(wt, val, w, n - 1);
}

// memoization

int solve(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> t)
{
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1)
        return t[n][W];

    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(
                   val[n - 1] + solve(wt, val, W - wt[n - 1], n - 1, t),
                   solve(wt, val, W, n - 1, t));
    }
    else
    {
        return t[n][W] = solve(wt, val, W, n - 1, t);
    }
}

int knapsackI(vector<int> &wt, vector<int> &val, int w, int n)
{
    // int t[n + 1][w + 1];
    // memset(t, -1, sizeof(t));

    vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));

    return solve(wt, val, w, n, t);
}

// top down
int knapsackII(vector<int> &wt, vector<int> &val, int W, int n)
{
    vector<vector<int>> t(n + 1, vector<int>(W + 1, 0));

    // build table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(
                    val[i - 1] + t[i - 1][j - wt[i - 1]],
                    t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][W];
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    cout << knapsackI(wt, val, W, wt.size()) << endl;

    return 0;
}