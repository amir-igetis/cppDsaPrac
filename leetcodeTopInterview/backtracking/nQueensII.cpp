#include <bits/stdc++.h>
using namespace std;

int backtrack(int row, int n, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2)
{
    if (row == n)
        return 1;
    int count = 0;

    for (int c = 0; c < n; c++)
    {
        if (col[c] || diag1[row + c] || diag2[row - c + n])
            continue;

        col[c] = diag1[row + c] = diag2[row - c + n] = true;
        count += backtrack(row + 1, n, col, diag1, diag2);
        col[c] = diag1[row + c] = diag2[row - c + n] = false; // backtrack
    }
    return count;
}

int totalNQueens(int n)
{
    vector<bool> col(n, false), diag1(2 * n, false), diag2(2 * n, false);
    return backtrack(0, n, col, diag1, diag2);
}

int main()
{

    int n = 4;
    cout << totalNQueens(n) << endl;

    return 0;
}