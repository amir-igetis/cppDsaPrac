#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int left = 0, right = n - 1;
        int firstNeg = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (grid[i][mid] < 0)
            {
                firstNeg = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        count += (n - firstNeg);
    }
    return count;
}

int countNegativesI(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int row = 0, col = n - 1, count = 0;
    while (row < m && col >= 0)
    {
        if (grid[row][col] < 0)
        {
            count += (m - row);
            col--;
        }
        else
        {
            row++;
        }
    }
    return count;
}

int main()
{

    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}};

    cout << countNegativesI(grid) << endl;

    return 0;
}