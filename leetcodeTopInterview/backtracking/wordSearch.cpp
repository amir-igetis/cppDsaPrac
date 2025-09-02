#include <bits/stdc++.h>
using namespace std;

bool backtrack(vector<vector<char>> &board, string word, int index, int row, int col)
{
    if (index == word.size())
        return true;

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
    {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '*';

    bool found = backtrack(board, word, index + 1, row + 1, col) ||
                 backtrack(board, word, index + 1, row - 1, col) ||
                 backtrack(board, word, index + 1, row, col + 1) ||
                 backtrack(board, word, index + 1, row, col - 1);

    board[row][col] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (backtrack(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}

int main()
{

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";
    cout << (exist(board, word) ? "True" : "False") << endl;

    return 0;
}