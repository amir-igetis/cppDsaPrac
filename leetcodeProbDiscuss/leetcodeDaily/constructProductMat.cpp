#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    const int mod = 12345;

    int size = n * m;
    vector<int> arr(size);

    // flatten grid
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[idx++] = grid[i][j] % mod;
        }
    }

    // prefix product
    vector<int> prefix(size);
    prefix[0] = 1;
    for (int i = 1; i < size; i++)
    {
        prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
    }

    // suffix product
    vector<int> suffix(size);
    suffix[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--)
    {
        suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
    }

    // build result matrix
    vector<vector<int>> res(n, vector<int>(m));
    idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = (prefix[idx] * suffix[idx]) % mod;
            idx++;
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<vector<int>> ans = constructProductMatrix(grid);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}