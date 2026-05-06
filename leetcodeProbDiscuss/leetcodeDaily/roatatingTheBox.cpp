#include <bits/stdc++.h>
using namespace std;

// Row by Row (Brute Force)
vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m));

    // Create the transpose of the input grid in `result`
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = box[j][i];
        }
    }

    // Reverse each row in the transpose grid to complete the 90° rotation
    for (int i = 0; i < n; i++)
    {
        reverse(result[i].begin(), result[i].end());
    }

    // Apply gravity to let stones fall to the lowest possible empty cell in
    // each column
    for (int j = 0; j < m; j++)
    {
        // Process each cell in column `j` from bottom to top
        for (int i = n - 1; i >= 0; i--)
        {
            if (result[i][j] == '.')
            { // Found an empty cell; check if a
              // stone can fall into it
                int nextRowWithStone = -1;

                // Look for a stone directly above the empty cell
                // `result[i][j]`
                for (int k = i - 1; k >= 0; k--)
                {
                    if (result[k][j] == '*')
                        break; // Obstacle blocks any stones above
                    if (result[k][j] ==
                        '#')
                    { // Stone found with no obstacles in between
                        nextRowWithStone = k;
                        break;
                    }
                }

                // If a stone was found above, let it fall into the empty
                // cell `result[i][j]`
                if (nextRowWithStone != -1)
                {
                    result[nextRowWithStone][j] = '.';
                    result[i][j] = '#';
                }
            }
        }
    }
    return result;
}

// Row by Row (Optimized)
vector<vector<char>> rotateTheBoxI(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m));

    // Create the transpose of the input grid in `result`
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = box[j][i];
        }
    }

    // Reverse each row in the transpose grid to complete the 90° rotation
    for (int i = 0; i < n; i++)
    {
        reverse(result[i].begin(), result[i].end());
    }

    // Apply gravity to let stones fall to the lowest possible empty cell in
    // each column
    for (int j = 0; j < m; j++)
    {
        int lowestRowWithEmptyCell = n - 1;
        // Process each cell in column `j` from bottom to top
        for (int i = n - 1; i >= 0; i--)
        {
            // Found a stone - let it fall to the lowest empty cell
            if (result[i][j] == '#')
            {
                result[i][j] = '.';
                result[lowestRowWithEmptyCell][j] = '#';
                lowestRowWithEmptyCell--;
            }
            // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
            // directly above it
            if (result[i][j] == '*')
            {
                lowestRowWithEmptyCell = i - 1;
            }
        }
    }
    return result;
}

// Combine rotation and gravity operations

vector<vector<char>> rotateTheBoxII(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m, '.'));

    // Apply gravity to let stones fall to the lowest possible empty cell in
    // each column
    for (int i = 0; i < m; i++)
    {
        int lowestRowWithEmptyCell = n - 1;
        // Process each cell in row `i` in reversed order
        for (int j = n - 1; j >= 0; j--)
        {
            // Found a stone - let it fall to the lowest empty cell
            if (box[i][j] == '#')
            {
                // Place it in the correct position in the rotated grid
                result[lowestRowWithEmptyCell][m - i - 1] = '#';
                // (Optional - already initialized to '.') result[j][m - i -
                // 1] = '.';
                lowestRowWithEmptyCell--;
            }
            // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
            // directly above it
            if (box[i][j] == '*')
            {
                // Place the obstacle in the correct position in the rotated
                // grid
                result[j][m - i - 1] = '*';
                lowestRowWithEmptyCell = j - 1;
            }
        }
    }
    return result;
}

int main()
{

    vector<vector<char>> boxGrid = {{'#', '.', '#'}};
    vector<vector<char>> ans = rotateTheBox(boxGrid);
    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}