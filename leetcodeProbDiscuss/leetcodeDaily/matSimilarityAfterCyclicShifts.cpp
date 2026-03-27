#include <bits/stdc++.h>
using namespace std;

bool areSimilar(vector<vector<int>> &mat, int k)
{
    int m = mat.size(), n = mat[0].size();
    k = k % n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != mat[i][(j + k) % n])
                return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 4;

    cout << (areSimilar(mat, k) ? "True" : "False") << endl;

    return 0;
}