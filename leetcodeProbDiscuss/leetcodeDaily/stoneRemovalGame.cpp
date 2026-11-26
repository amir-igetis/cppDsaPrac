#include <bits/stdc++.h>
using namespace std;

// Simulation

/// Let n be the initial number of stones.
///
/// Time complexity: O(1).
///
/// Since n≤50 and the first 8 moves require 10+9+⋯+3=52 stones, the loop executes at most 7 times.
///
/// Space complexity: O(1).
///
/// Only a few extra variables are used.
bool canAliceWin(int n)
{
    int take = 10,
        k = 0;
    while (n >= take)
    {
        n -= take;
        take--;
        k++;
    }
    return k % 2 == 1;
}

// Math

/// Time complexity: O(1).
///
/// Only a constant number of arithmetic operations and one square root operation are needed.
///
/// Space complexity: O(1).
///
/// Only a few extra variables are used.
bool canAliceWinI(int n)
{
    int k = (21 - sqrt(441 - 8 * n)) / 2;
    return k % 2 == 1;
}

int main()
{
    int n = 12;
    cout << canAliceWin(n) << endl;
    cout << canAliceWinI(n) << endl;

    return 0;
}
