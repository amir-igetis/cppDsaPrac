#include <bits/stdc++.h>
using namespace std;

bool isMagic(vector<vector<int>> &g, int r, int c)
{

    // 1️⃣ Center must be 5
    if (g[r + 1][c + 1] != 5)
        return false;

    // 2️⃣ Check numbers 1–9 exactly once
    vector<bool> seen(10);
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            int val = g[i][j];
            if (val < 1 || val > 9 || seen[val])
            {
                return false;
            }
            seen[val] = true;
        }
    }

    // 3️⃣ Check sums
    int sum = g[r][c] + g[r][c + 1] + g[r][c + 2];

    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2] != sum)
            return false;
    }

    // Columns
    for (int j = 0; j < 3; j++)
    {
        if (g[r][c + j] + g[r + 1][c + j] + g[r + 2][c + j] != sum)
            return false;
    }

    // Diagonals
    if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != sum)
        return false;

    if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != sum)
        return false;

    return true;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Traverse all possible 3x3 subgrids
    for (int i = 0; i <= rows - 3; i++)
    {
        for (int j = 0; j <= cols - 3; j++)
        {
            if (isMagic(grid, i, j))
            {
                count++;
            }
        }
    }
    return count;
}

// manual scan tc O(m.n) sc O(1)

bool isMagicSquare(vector<vector<int>> &grid, int row, int col)
{
    bool seen[10] = {false};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = grid[row + i][col + j];
            if (num < 1 || num > 9)
                return false;
            if (seen[num])
                return false;
            seen[num] = true;
        }
    }

    // Check if diagonal sums are the same
    int diagonal1 =
        grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
    int diagonal2 =
        grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

    if (diagonal1 != diagonal2)
        return false;

    // Check if all row sums are the same as the diagonal sums
    int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
    int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
               grid[row + 1][col + 2];
    int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
               grid[row + 2][col + 2];

    if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1))
    {
        return false;
    }

    // Check if all column sums are the same as the diagonal sums
    int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
    int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
               grid[row + 2][col + 1];
    int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
               grid[row + 2][col + 2];

    if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1))
    {
        return false;
    }

    return true;
}

int numMagicSquaresInsideII(vector<vector<int>> &grid)
{
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int row = 0; row + 2 < m; row++)
    {
        for (int col = 0; col + 2 < n; col++)
        {
            if (isMagicSquare(grid, row, col))
            {
                ans++;
            }
        }
    }
    return ans;
}

// check unique properties of Magic square tc O(m.n) sc O(1)
bool isMagicSquareI(vector<vector<int>> &grid, int row, int col)
{
    // The sequences are each repeated twice to account for
    // the different possible starting points of the sequence
    // in the magic square
    string sequence = "2943816729438167";
    string sequenceReversed = "7618349276183492";

    string border = "";
    // Flattened indices for bordering elements of 3x3 grid
    vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
    for (int i : borderIndices)
    {
        int num = grid[row + i / 3][col + (i % 3)];
        border += to_string(num);
    }

    // Make sure the sequence starts at one of the corners
    return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
            (sequence.find(border) != string::npos ||
             sequenceReversed.find(border) != string::npos));
}

int numMagicSquaresInsideI(vector<vector<int>> &grid)
{
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int row = 0; row + 2 < m; row++)
    {
        for (int col = 0; col + 2 < n; col++)
        {
            if (isMagicSquareI(grid, row, col))
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    cout << (numMagicSquaresInsideI(grid) ? "True" : "False") << endl;

    return 0;
}