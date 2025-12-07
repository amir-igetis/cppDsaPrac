#include <bits/stdc++.h>
using namespace std;

int countCollisions(string directions)
{
    int n = directions.size();
    if (n == 1)
        return 0;
    int l = 0, r = n - 1;
    while (directions[l] == 'L')
        l++;
    while (directions[r] == 'R')
        r--;
    if (l >= r)
        return 0;
    int col = 0;
    for (; l <= r; l++)
    {
        col += directions[l] != 'S';
    }
    return col;
}

int main()
{

    string directions = "RLRSLL";
    cout << countCollisions(directions) << endl;

    return 0;
}