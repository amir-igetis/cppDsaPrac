#include <bits/stdc++.h>
using namespace std;

bool judgeCircle(string moves)
{
    int x = 0, y = 0;
    for (auto &move : moves)
    {
        if (move == 'U')
            y--;
        else if (move == 'D')
            y++;
        else if (move == 'L')
            x--;
        else if (move == 'R')
            x++;
    }
    return x == 0 && y == 0;
}

int main()
{
    string moves = "UD";

    cout << (judgeCircle(moves) ? "True" : "False") << endl;

    return 0;
}