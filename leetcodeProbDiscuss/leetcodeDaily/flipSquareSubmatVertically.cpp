#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k >> 1; j++)
        {
            swap(grid[x + j][y + i], grid[x + k - j - 1][y + i]);
        }
    }
    return grid;
}

int main()
{

    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int x = 1, y = 0, k = 3;
    vector<vector<int>> ans = reverseSubmatrix(grid, x, y, k);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";

        cout << endl;
    }

    return 0;
}