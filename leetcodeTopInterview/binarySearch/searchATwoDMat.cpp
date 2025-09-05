#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0, right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int midVal = matrix[mid / n][mid % n];

        if (midVal == target)
            return true;
        else if (midVal < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    cout << (searchMatrix(matrix, target) ? "True" : "False") << endl;

    return 0;
}