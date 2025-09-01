#include <bits/stdc++.h>
using namespace std;

// using dfs

void dfs(vector<vector<char>> &board, int i, int j)
{
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
        return;

    board[i][j] = '#'; // mark as safe

    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>> &board)
{
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();

    // mark border-connected 'O's
    for (int i = 0; i < m; i++)
    {
        dfs(board, i, 0);
        dfs(board, i, n - 1);
    }
    for (int j = 0; j < n; j++)
    {
        dfs(board, 0, j);
        dfs(board, m - 1, j);
    }

    // flip
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}

// using bfs

void bfs(vector<vector<char>> &board, int i, int j)
{
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    board[i][j] = '#';

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        // auto [x, y] = q.front();
        // q.pop();
        // for (auto [dx, dy] : dirs)
        // {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O')
            {
                board[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }
}

void solveI(vector<vector<char>> &board)
{
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
            bfs(board, i, 0);
        if (board[i][n - 1] == 'O')
            bfs(board, i, n - 1);
    }
    for (int j = 0; j < n; j++)
    {
        if (board[0][j] == 'O')
            bfs(board, 0, j);
        if (board[m - 1][j] == 'O')
            bfs(board, m - 1, j);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}

// using Union Find (Disjoint Set)

int find(vector<int> &parent, int x)
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int px = find(parent, x), py = find(parent, y);
    if (px == py)
        return;
    if (rank[px] > rank[py])
        parent[py] = px;
    else if (rank[px] < rank[py])
        parent[px] = py;
    else
    {
        parent[py] = px;
        rank[px]++;
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();
    int dummy = m * n;
    vector<int> parent(m * n + 1), rank(m * n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    auto node = [&](int i, int j)
    { return i * n + j; };
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // union border 'O's with dummy
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    unite(parent, rank, node(i, j), dummy);
                }
                else
                {
                    // for (auto [dx, dy] : dirs)
                    // {

                    for (auto dir : dirs)
                    {
                        int dx = dir.first;
                        int dy = dir.second;
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O')
                        {
                            unite(parent, rank, node(i, j), node(ni, nj));
                        }
                    }
                }
            }
        }
    }

    // flip
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O' && find(parent, node(i, j)) != find(parent, dummy))
                board[i][j] = 'X';
        }
    }
}

int main()
{

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    solve(board);

    for (auto &i : board)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}