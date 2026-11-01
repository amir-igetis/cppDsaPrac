#include <bits/stdc++.h>
using namespace std;

// Breadth First Search

/// Here, m and n are the number of rows and columns in the given grid.
///
/// Time complexity: O(m⋅n)
///
/// Initializing the visit array takes O(m⋅n) time.
/// We iterate over all the cells and find unvisited land cells to perform BFS traversal from those. This takes O(m⋅n) time.
/// Each queue operation in the BFS algorithm takes O(1) time, and a single node can be pushed once, leading to O(m⋅n) operations for m⋅n nodes. We iterate over all the neighbors of each node that is popped out of the queue. So for every node, we would iterate four times to iterate over the neighbors, resulting in O(4⋅m⋅n)=O(m⋅n) operations total for all the nodes.
/// Space complexity: O(m⋅n)
///
/// The visit array takes O(m⋅n) space.
/// The BFS queue takes O(m⋅n) space in the worst-case because each node is added once

class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit))
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool bfs(int x, int y, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visit)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty())
        {
            x = q.front().first;  // row nnumber
            y = q.front().second; // column number
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n)
                {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                }
                else if (grid[r][c] == 0 && !visit[r][c])
                {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};

// Depth First Search

/// Here, m and n are the number of rows and columns in the given grid.
///
/// Time complexity: O(m⋅n)
///
/// Initializing the visit array takes O(m⋅n) time.
/// We iterate over all the cells and find unvisited land cells to perform DFS traversal from those. This takes O(m⋅n) time.
/// The dfs function visits each node once, leading to O(m⋅n) operations for m⋅n nodes. We iterate over all the neighbors of each node that is popped out of the queue. So for every node, we would iterate four times to iterate over the neighbors, resulting in O(4⋅m⋅n)=O(m⋅n) operations total for all the nodes.
/// Space complexity: O(m⋅n)
///
/// The visit array takes O(m⋅n) space.
/// The recursion stack used by dfs can have no more than O(m⋅n) elements in the worst-case scenario. It would take up O(m⋅n) space in that case
class SolutionI
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit))
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool dfs(int x, int y, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visit)
    {
        if (x < 0 || x >= m || y < 0 || y >= n)
        {
            return false;
        }
        if (grid[x][y] == 1 || visit[x][y])
        {
            return true;
        }

        visit[x][y] = true;
        bool isClosed = true;
        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int r = x + dirx[i];
            int c = y + diry[i];
            if (!dfs(r, c, m, n, grid, visit))
            {
                isClosed = false;
            }
        }

        return isClosed;
    }
};

int main()
{

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}};
    Solution sol;
    SolutionI solI;
    cout << sol.closedIsland(grid) << endl;
    cout << solI.closedIsland(grid) << endl;

    return 0;
}