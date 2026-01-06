#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    long long totalSum = 0;
    int minAbsVal = INT_MAX;
    int negativeCount = 0;

    for (auto &row : matrix)
    {
        for (int val : row)
        {
            totalSum += abs(val);
            if (val < 0)
            {
                negativeCount++;
            }
            minAbsVal = min(minAbsVal, abs(val));
        }
    }

    // Adjust if the count of negative numbers is odd
    if (negativeCount % 2 != 0)
    {
        totalSum -= 2 * minAbsVal;
    }

    return totalSum;
}

// previous soln
long long maxMatrixSumI(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    long totalSum = 0;
    int negativeCount = 0;
    int smallestAbsVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = matrix[i][j];
            totalSum += abs(val);
            if (val < 0)
                negativeCount++;
            smallestAbsVal = min(smallestAbsVal, abs(val));
        }
    }

    if (negativeCount % 2 == 1)
        totalSum -= 2 * smallestAbsVal;

    return totalSum;
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << maxMatrixSumI(matrix) << endl;

    return 0;
}