#include <bits/stdc++.h>
using namespace std;

bool isValidSudokuI(vector<vector<char>> &board)
{
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<vector<unordered_set<char>>> boxes(3, vector<unordered_set<char>>(3));

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char val = board[r][c];
            if (val == '.')
                continue;

            // Check row
            if (rows[r].count(val))
                return false;
            rows[r].insert(val);

            // Check column
            if (cols[c].count(val))
                return false;
            cols[c].insert(val);

            // Check 3x3 box using row/3, col/3 indexing
            if (boxes[r / 3][c / 3].count(val))
                return false;
            boxes[r / 3][c / 3].insert(val);
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char val = board[r][c];
            if (val == '.')
                continue;

            if (rows[r].count(val))
                return false;
            rows[r].insert(val);

            if (cols[c].count(val))
                return false;
            cols[c].insert(val);

            int boxIdx = (r / 3) * 3 + (c / 3);
            if (boxes[boxIdx].count(val))
                return false;

            boxes[boxIdx].insert(val);
        }
    }
    return true;
}

int main()
{

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    //  int ans = isValidSudoku(board);

    // cout << ans << endl;

    cout << isValidSudokuI(board) << endl;

    return 0;
}