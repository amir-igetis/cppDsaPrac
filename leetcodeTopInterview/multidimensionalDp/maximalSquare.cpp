#include <bits/stdc++.h>
using namespace std;

// using recursion
int solve(vector<vector<char>> &matrix, int i, int j, int m, int n, int &maxSide)
{
    if (i >= m || j >= n)
        return 0;

    int right = solve(matrix, i, j + 1, m, n, maxSide);
    int down = solve(matrix, i + 1, j, m, n, maxSide);
    int diagonal = solve(matrix, i + 1, j + 1, m, n, maxSide);

    int curr = 0;
    if (matrix[i][j] == '1')
    {
        curr = 1 + min({right, down, diagonal});
        maxSide = max(maxSide, curr); // update max
    }

    return curr;
}

int maximalSquareI(vector<vector<char>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int maxSide = 0;
    solve(matrix, 0, 0, m, n, maxSide);
    return maxSide * maxSide;
}

// using recursion with memo

int solve(vector<vector<char>> &matrix, int i, int j, int m, int n,
          vector<vector<int>> &dp, int &maxSide)
{
    if (i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solve(matrix, i, j + 1, m, n, dp, maxSide);
    int down = solve(matrix, i + 1, j, m, n, dp, maxSide);
    int diagonal = solve(matrix, i + 1, j + 1, m, n, dp, maxSide);

    int curr = 0;
    if (matrix[i][j] == '1')
    {
        curr = 1 + min({right, down, diagonal});
        maxSide = max(maxSide, curr); // update max
    }

    return dp[i][j] = curr;
}

int maximalSquareII(vector<vector<char>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxSide = 0;
    solve(matrix, 0, 0, m, n, dp, maxSide);
    return maxSide * maxSide;
}

// using Bottom up DP
int maximalSquareIII(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSide = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1; // first row/col → only 1 possible
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

// another DP approach

int maximalSquareI(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSide = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1; // first row/col just take the value itself
                }
                else
                {
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // top
                                       dp[i][j - 1],    // left
                                       dp[i - 1][j - 1] // top-left
                                   });
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide;
}

int main()
{

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1'}};

    cout << maximalSquareI(matrix) << endl;

    return 0;
}