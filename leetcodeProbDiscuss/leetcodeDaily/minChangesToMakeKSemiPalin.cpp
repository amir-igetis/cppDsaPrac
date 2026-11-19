#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

/// Time O(n^3): the block comparisons over all pieces and divisors add up to at most about n^3/10 letters, and each of the k rounds tries at most (n−2k+1)^2 pairs of a cut and an end.
///
/// Space O(n^2 logn) for the cached peel values.

int minimumChanges(string s, int k)
{
    int n = s.size(), inf = INT_MAX / 2;
    auto peel = [&](int i, int j, int d) { // s[i:j] in blocks of d: the outer pair of blocks, then the inside
        int changes = 0;
        for (; j - i > d; i += d, j -= d)
            for (int t = 0; t < d; ++t)
                changes += s[i + t] != s[j - d + t];
        return changes;
    };

    // Fix 1: Add explicit template arguments <vector<int>> and <int>
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, inf)); // cost[i][j]: changes to make s[i:j] a semi-palindrome
    for (int d = 1; 2 * d <= n; ++d)
        for (int length = 2 * d; length <= n; length += d) // every length that d divides, with d < length
            for (int i = 0, j = length; j <= n; ++i, ++j)
                cost[i][j] = min(cost[i][j], peel(i, j, d));

    // Fix 2: Add explicit template arguments <int>
    vector<int> best(n + 1, inf); // best[j]: the fewest changes for s[:j] cut into the pieces placed so far
    best[0] = 0;

    // Fix 3: Replace C++20 ranges/views with a standard loop for broad compiler compatibility
    auto extend = [&](int j) { // the newest piece s[i:j] starts at an old cut i and gets at least 2 letters
        int min_changes = inf;
        for (int i = 0; i < j - 1; ++i)
        {
            min_changes = min(min_changes, best[i] + cost[i][j]);
        }
        return min_changes;
    };

    for (int pieces = 1; pieces < k; ++pieces)
    {                                                            // every piece but the last
        vector<int> next(n + 1, inf);                            // Fix 4: explicit template arguments
        for (int j = 2 * pieces; j <= n - 2 * (k - pieces); ++j) // 2 letters for each piece, placed or still to come
            next[j] = extend(j);
        swap(best, next);
    }
    return extend(n); // the last piece ends at n
}

int main()
{
    string s = "abcac";
    int k = 2;
    cout << minimumChanges(s, k) << endl;

    return 0;
}