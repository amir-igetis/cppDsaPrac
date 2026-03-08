#include <bits/stdc++.h>
using namespace std;

int checkRow(vector<vector<int>> &mat, int i)
{
    int index = -1;
    for (int j = 0; j < mat[0].size(); j++)
    {
        if (mat[i][j] == 1)
        {
            if (index >= 0)
                return -1;
            else
                index = j;
        }
    }
    return index;
}

bool checkColumn(vector<vector<int>> mat, int i, int index)
{
    for (int j = 0; j < mat.size(); j++)
    {
        if (mat[j][index] == 1 & j != i)
            return false;
    }
    return true;
}

//    tc O(m * n) & sc O(1)
int numSpecial(vector<vector<int>> &mat)
{
    int specials = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        int index = checkRow(mat, i);
        if (index >= 0 && checkColumn(mat, i, index))
            specials++;
    }
    return specials;
}

// another solution
int numSpecialI(vector<vector<int>> &mat)
{
    vector<int> rows(mat.size()), cols(mat[0].size());
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j)
        {
            if (mat[i][j])
                ++rows[i], ++cols[j];
        }
    int res = 0;
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j)
            if (mat[i][j] && rows[i] == 1 && cols[j] == 1)
                ++res;
    return res;
}

// another solution
int numSpecialII(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> rowCount(m + 1, 0);
    vector<int> colCount(n + 1, 0);
    // pre compute the count of 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                rowCount[i] += 1;
                colCount[j] += 1;
            }
        }
    }
    // now traversing once again
    int total = 0;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (mat[row][col] == 1 && rowCount[row] <= 1 && colCount[col] <= 1)
            {
                total++;
            }
        }
    }
    return total;
}

int main()
{

    vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};

    cout << numSpecialII(mat) << endl;

    return 0;
}