#include <bits/stdc++.h>
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>> &buildings)
{
    vector<int> maxRow(n + 1);
    vector<int> minRow(n + 1, n + 1);
    vector<int> maxCol(n + 1);
    vector<int> minCol(n + 1, n + 1);

    for (auto &b : buildings)
    {
        int x = b[0], y = b[1];
        maxRow[y] = max(maxRow[y], x);
        minRow[y] = min(minRow[y], x);
        maxCol[x] = max(maxCol[x], y);
        minCol[x] = min(minCol[x], y);
    }

    int res = 0;
    for (auto &b : buildings)
    {
        int x = b[0], y = b[1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x])
            res++;
    }

    return res;
}

int main()
{
    int n = 3;
    vector<vector<int>> buildings = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};

    cout << countCoveredBuildings(n, buildings) << endl;

    return 0;
}