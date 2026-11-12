#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Brute Force
    // Let m be the number of rows and n be the number of columns in the grid.
    // Time complexity: O(m*n*(m+n))
    // Space complexity: O(1)
    int countServers(vector<vector<int>> &grid)
    {
        int numRows = grid.size();
        int numCols = numRows > 0 ? grid[0].size() : 0;
        int communicableServersCount = 0;

        // Traverse through the grid
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < numCols; ++col)
            {
                if (grid[row][col] == 1)
                {
                    bool canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < numCols; ++otherCol)
                    {
                        if (otherCol != col && grid[row][otherCol] == 1)
                        {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment communicableServersCount
                    if (canCommunicate)
                    {
                        communicableServersCount++;
                    }
                    else
                    {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < numRows; ++otherRow)
                        {
                            if (otherRow != row && grid[otherRow][col] == 1)
                            {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment communicableServersCount
                        if (canCommunicate)
                        {
                            communicableServersCount++;
                        }
                    }
                }
            }
        }

        return communicableServersCount;
    }

    // Track Using Two Arrays
    // Time complexity: O(m*n)
    // Space complexity: O(m+n)
    int countServersI(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        vector<int> rowCounts(grid[0].size(), 0);
        vector<int> colCounts(grid.size(), 0);

        // Count servers in each row and each column
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    rowCounts[col]++;
                    colCounts[row]++;
                }
            }
        }

        int communicableServersCount = 0;

        // Count servers that can communicate (in the same row or column)
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    if (rowCounts[col] > 1 || colCounts[row] > 1)
                    {
                        communicableServersCount++;
                    }
                }
            }
        }

        return communicableServersCount;
    }

    // Server Grouping
    // Time complexity: O(m*n)
    // Space complexity: O(m+n)
    int countServersII(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int communicableServersCount = 0;
        vector<int> colCount(grid[0].size(), 0);
        vector<int> lastServerInRow(grid.size(), -1);

        // First pass to count servers in each row and column
        for (int row = 0; row < grid.size(); row++)
        {
            int serverCountInRow = 0;
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1)
            {
                communicableServersCount += serverCountInRow;
                lastServerInRow[row] = -1;
            }
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < grid.size(); row++)
        {
            if (lastServerInRow[row] != -1 && colCount[lastServerInRow[row]] > 1)
            {
                communicableServersCount++;
            }
        }

        return communicableServersCount;
    }

    // Space Optimized
    // Time complexity: O(m*n)
    // Space complexity: O(1)
    int countServersIII(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size(), cols = grid[0].size();
        int communicableServersCount = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex)
        {
            int rowCounts = 0;
            int serverColumnIndex = -1;

            // Count the number of servers in the current row and record the first server's column index.
            for (int colIndex = 0; colIndex < cols; ++colIndex)
            {
                if (grid[rowIndex][colIndex] == 1)
                {
                    if (rowCounts == 0)
                    {
                        serverColumnIndex = colIndex;
                    }
                    rowCounts++;
                }
            }

            // If more than one server in the row, it can communicate
            bool canCommunicate = (rowCounts != 1);

            // If there's only one server in the row, check if there's a server
            // in the same column in another row.
            if (!canCommunicate && serverColumnIndex != -1)
            {
                for (int i = 0; i < rows; ++i)
                {
                    if (i != rowIndex && grid[i][serverColumnIndex] == 1)
                    {
                        canCommunicate = true;
                        break;
                    }
                }
            }

            // If the server can communicate, add rowCounts to the result.
            if (canCommunicate)
            {
                communicableServersCount += rowCounts;
            }
        }

        return communicableServersCount;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};

    // Instantiate the class to call the non-static methods
    Solution solution;

    cout << solution.countServers(grid) << endl;
    cout << solution.countServersI(grid) << endl;
    cout << solution.countServersII(grid) << endl;
    cout << solution.countServersIII(grid) << endl;

    return 0;
}