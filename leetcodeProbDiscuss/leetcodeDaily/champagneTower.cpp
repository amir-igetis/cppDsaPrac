#include <bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<double> currRow(1, poured);
    for (int i = 0; i <= query_row; i++)
    {
        vector<double> nextRow(i + 2);
        for (int j = 0; j <= i; j++)
        {
            if (currRow[j] > 1)
            {
                double overflow = (currRow[j] - 1) / 2.0;
                nextRow[j] += overflow;
                nextRow[j + 1] += overflow;
                currRow[j] = 1;
            }
        }
        if (i != query_row)
            currRow = nextRow;
    }
    return min(1.0, currRow[query_glass]);
}

// another solution
double champagneTowerI(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));

    dp[0][0] = poured;

    for (int i = 0; i < query_row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (dp[i][j] > 1.0)
            {
                double flow = (dp[i][j] - 1.0) / 2.0;
                dp[i + 1][j] += flow;
                dp[i + 1][j + 1] += flow;
            }
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}

int main()
{
    int poured = 1, query_row = 1, query_glass = 1;
    cout << champagneTowerI(poured, query_row, query_glass) << endl;

    return 0;
}