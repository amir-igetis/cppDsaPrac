#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Step 1: Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

bool isEqual(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    for (int i = 0; i < 4; i++)
    {
        if (isEqual(mat, target))
            return true;
        rotate90(mat);
    }

    return false;
}

int main()
{

    vector<vector<int>> mat = {{0, 1}, {1, 1}}, target = {{1, 0}, {0, 1}};
    cout << (findRotation(mat, target) ? "True" : "False") << endl;

    return 0;
}