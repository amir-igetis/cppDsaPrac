#include <bits/stdc++.h>
using namespace std;

// DP

/// Let n be the length of costs.
///
/// Time complexity: O(n).
///
/// We iterate through the array of length n once, performing a constant number of comparisons and additions at each step.
///
/// Space complexity: O(1).
///
/// Only three rolling variables (a, b, and c) are used to track the dynamic programming states, requiring constant extra memory.
int climbStairs(int n, vector<int> &costs)
{
    int a = 0,
        b = 0,
        c = 0;
    for (int i = 0; i < n; ++i)
    {
        int nxt = min(min(a + 9, b + 4), c + 1) + costs[i];
        a = b;
        b = c;
        c = nxt;
    }
    return c;
}

int main()
{

    int n = 4;
    vector<int> costs = {1, 2, 3, 4};
    cout << climbStairs(n, costs) << endl;

    return 0;
}
