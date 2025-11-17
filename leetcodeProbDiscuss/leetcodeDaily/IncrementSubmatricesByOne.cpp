#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

    for (auto &q : queries)
    {
        int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

        diff[r1][c1] += 1;
        if (c2 + 1 < n)
            diff[r1][c2 + 1] -= 1;
        if (r2 + 1 < n)
            diff[r2 + 1][c1] -= 1;
        if (r2 + 1 < n && c2 + 1 < n)
            diff[r2 + 1][c2 + 1] += 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            diff[i][j] += diff[i][j - 1];
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
            diff[i][j] += diff[i - 1][j];
    }

    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            res[i][j] = diff[i][j];
    }

    return res;
}

int main()
{
    int n = 3;
    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};

    vector<vector<int>> ans = rangeAddQueries(n, queries);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}