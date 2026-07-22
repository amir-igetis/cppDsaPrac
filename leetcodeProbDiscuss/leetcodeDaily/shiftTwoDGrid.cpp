#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;

    k %= total;

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            // Current position in flattened array
            int currIndex = i * n + j;

            // Original position before shifting
            int oldIndex = (currIndex - k + total) % total;

            int oldRow = oldIndex / n;
            int oldCol = oldIndex % n;

            ans[i][j] = grid[oldRow][oldCol];
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 1;
    vector<vector<int>> result = shiftGrid(grid, k);
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}