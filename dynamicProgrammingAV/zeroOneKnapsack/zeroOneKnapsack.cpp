#include <bits/stdc++.h>
using namespace std;

// using recursion
int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] <= w)
    {
        return max(
            val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
            knapsack(wt, val, w, n - 1));
    }
    else
    {
        return knapsack(wt, val, w, n - 1);
    }
}

// using memoization
int knapsackMemo(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &t)
{
    if (n == 0 || w == 0)
        return 0;

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
    {
        t[n][w] = max(val[n - 1] + knapsackMemo(wt, val, w - wt[n - 1], n - 1, t),
                      knapsackMemo(wt, val, w, n - 1, t));
    }
    else
    {
        t[n][w] = knapsackMemo(wt, val, w, n - 1, t);
    }

    return t[n][w];
}

int knapsackI(vector<int> &wt, vector<int> &val, int w, int n)
{
    // Initialize memo table with -1
    vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));

    return knapsackMemo(wt, val, w, n, t);
}

// using top down DP
int knapsackII(vector<int> &wt, vector<int> &val, int w, int n)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]],
                              t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}

int main()
{

    vector<int> wt = {1, 2, 3};
    vector<int> val = {10, 20, 30};
    int w = 5;
    int n = wt.size();

    cout << knapsackII(wt, val, w, n) << endl;

    return 0;
}