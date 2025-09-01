#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> zeroRows(rows);
    vector<bool> zeroCols(cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (zeroRows[i] || zeroCols[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    vector<vector<int>> ans = matrix;

    setZeroes(ans);

    for (vector<int> i : ans)
    {
        for (int c : i)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}