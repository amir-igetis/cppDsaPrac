#include <bits/stdc++.h>
using namespace std;

bool canPartitionGrid(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    long long total = 0;
    for (auto &row : grid)
        for (int val : row)
            total += val;

    // Try horizontal cuts
    long long topSum = 0;
    unordered_map<int, int> topMap, bottomMap;

    // initialize bottom map
    for (auto &row : grid)
        for (int val : row)
            bottomMap[val]++;

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = grid[i][j];
            topSum += val;

            topMap[val]++;
            bottomMap[val]--;
            if (bottomMap[val] == 0)
                bottomMap.erase(val);
        }

        long long bottomSum = total - topSum;

        if (topSum == bottomSum)
            return true;

        long long diff = abs(topSum - bottomSum);

        // remove from larger part
        if (topSum > bottomSum)
        {
            if (topMap.count(diff))
                return true;
        }
        else
        {
            if (bottomMap.count(diff))
                return true;
        }
    }

    // Try vertical cuts
    long long leftSum = 0;
    unordered_map<int, int> leftMap, rightMap;

    // initialize right map
    for (auto &row : grid)
        for (int val : row)
            rightMap[val]++;

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < m; i++)
        {
            int val = grid[i][j];
            leftSum += val;

            leftMap[val]++;
            rightMap[val]--;
            if (rightMap[val] == 0)
                rightMap.erase(val);
        }

        long long rightSum = total - leftSum;

        if (leftSum == rightSum)
            return true;

        long long diff = abs(leftSum - rightSum);

        if (leftSum > rightSum)
        {
            if (leftMap.count(diff))
                return true;
        }
        else
        {
            if (rightMap.count(diff))
                return true;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> grid = {{1, 4}, {2, 3}};
    cout << (canPartitionGrid(grid) ? "True" : "False") << endl;
}