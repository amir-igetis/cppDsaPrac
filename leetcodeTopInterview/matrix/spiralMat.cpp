#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;

    if (matrix.empty() || matrix[0].empty())
        return res;

    int rows = matrix.size(), cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse from Left to Right
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        top++;

        // Traverse from Top to Bottom
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        right--;

        if (top <= bottom)
        {
            // Traverse from Right to Left
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            // Traverse from Bottom to Top
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> ans = spiralOrder(matrix);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}