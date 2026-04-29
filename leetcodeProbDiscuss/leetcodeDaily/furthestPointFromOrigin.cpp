#include <bits/stdc++.h>
using namespace std;

int furthestDistanceFromOrigin(string moves)
{
    int L = 0, R = 0, B = 0;
    for (auto &ch : moves)
    {
        if (ch == 'L')
            L++;
        else if (ch == 'R')
            R++;
        else
            B++;
    }

    return abs(L - R) + B;
}

int main()
{
    string moves = "L_RL__R";
    cout << furthestDistanceFromOrigin(moves) << endl;
}
