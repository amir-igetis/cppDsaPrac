#include <bits/stdc++.h>
using namespace std;

// Greedy

/// Time complexity: O(1).
///
/// The algorithm involves only a constant number of arithmetic operations and comparisons.
///
/// Space complexity: O(1).
///
/// Only a constant number of variables are used

long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                      int need2)
{
    long long totalCost = 0;

    // Buying separately is cheaper; item 3 is unnecessary
    if (cost1 + cost2 <= costBoth)
    {
        totalCost = 1LL * cost1 * need1 + 1LL * cost2 * need2;
    }
    else
    {
        // Buy item 3 first until one requirement is fulfilled
        int cnt_3 = min(need1, need2);
        totalCost = 1LL * cnt_3 * costBoth;

        need1 -= cnt_3;
        need2 -= cnt_3;

        // Type 1 is still needed; choose the cheaper of items 1 and 3
        if (need1 > 0)
        {
            totalCost += 1LL * need1 * min(cost1, costBoth);
        }

        // Type 2 is still needed; choose the cheaper of items 2 and 3
        else if (need2 > 0)
        {
            totalCost += 1LL * need2 * min(cost2, costBoth);
        }
    }

    return totalCost;
}

int main()
{
    int cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2;
    cout << minimumCost(cost1, cost2, costBoth, need1, need2) << endl;

    return 0;
}