#include <bits/stdc++.h>
using namespace std;

// check this stuff

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int liveNeighbors = 0;

            for (auto &dir : dirs)
            {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    liveNeighbors += board[ni][nj] & 1;
                }
            }

            // Apply the Game of Life rules using 2 bits:
            if (board[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3))
            {
                board[i][j] = 3; // 11: live → live
            }
            else if (board[i][j] == 0 && liveNeighbors == 3)
            {
                board[i][j] = 2; // 10: dead → live
            }
        }
    }

    // Final pass: keep only the 2nd bit (next state)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] >>= 1;
        }
    }
}

int main()
{

    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};

    vector<vector<int>> ans = board;

    gameOfLife(ans);

    for (vector<int> i : ans)
    {
        for (int c : i)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}