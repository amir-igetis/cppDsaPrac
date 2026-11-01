#include <bits/stdc++.h>
using namespace std;

// construction
/// Let m and n be the number of rows and columns in the grid, respectively.
/// Time complexity: O(mn).
/// Constructing each cell in the grid takes O(1) time, so the overall time complexity is O(mn).
/// Space complexity: O(n).
/// A temporary string of length n is used to construct each row, requiring O(n) auxiliary space (excluding the output grid).

vector<string> createGrid(int m, int n)
{
    vector<string> grid(m);
    grid[0] = string(n, '.');
    string row = string(n - 1, '#') + '.';
    for (int i = 1; i < m; i++)
    {
        grid[i] = row;
    }
    return grid;
}

int main()
{
    int m = 2, n = 3;
    vector<string> grid = createGrid(m, n);
    for (const string &row : grid)
    {
        cout << row << " ";
    }
    cout << endl;

    return 0;
}