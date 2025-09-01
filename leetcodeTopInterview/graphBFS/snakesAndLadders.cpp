#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming + BFS (Precompute Next Moves)
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> flatten(n * n + 1);
    int index = 1;
    bool leftToRight = true;

    for (int row = n - 1; row >= 0; row--)
    {
        if (leftToRight)
        {
            for (int col = 0; col < n; col++)
            {
                flatten[index++] = board[row][col];
            }
        }
        else
        {
            for (int col = n - 1; col >= 0; col--)
            {
                flatten[index++] = board[row][col];
            }
        }
        leftToRight = !leftToRight;
    }

    queue<vector<int>> q;
    vector<bool> visited(n * n + 1);
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();
        int pos = curr[0];
        int moves = curr[1];

        for (int dice = 1; dice <= 6; dice++)
        {
            int nextPos = pos + dice;
            if (nextPos > n * n)
                break;

            if (flatten[nextPos] != -1)
                nextPos = flatten[nextPos];

            if (nextPos == n * n)
                return moves + 1;

            if (!visited[nextPos])
            {
                visited[nextPos] = true;
                q.push({nextPos, moves + 1});
            }
        }
    }
    return -1;
}

// BFS (Shortest Path in Unweighted Graph)

pair<int, int> getPos(int square, int n)
{
    int row = (square - 1) / n;
    int col = (square - 1) % n;

    if (row % 2 == 1)
        col = n - 1 - col;

    row = n - 1 - row;

    return {row, col};
}

int snakesAndLaddersI(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> visited(n * n + 1, 0);

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;

    while (!q.empty())
    {
        int square = q.front().first;
        int moves = q.front().second;
        q.pop();

        if (square == n * n)
            return moves;

        for (int dice = 1; dice <= 6; dice++)
        {
            int next = square + dice;
            if (next > n * n)
                break;

            pair<int, int> pos = getPos(next, n);
            int row = pos.first;
            int col = pos.second;

            if (board[row][col] != -1)
                next = board[row][col];

            if (!visited[next])
            {
                visited[next] = 1;
                q.push({next, moves + 1});
            }
        }
    }
    return -1;
}

int main()
{

    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};

    cout << snakesAndLaddersI(board) << endl;

    return 0;
}