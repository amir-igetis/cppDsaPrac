#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> f;

int dfs(const vector<int> &stoneValue, int left, int right)
{
    if (left == right)
    {
        return 0;
    }
    if (f[left][right])
    {
        return f[left][right];
    }

    int sum = accumulate(stoneValue.begin() + left,
                         stoneValue.begin() + right + 1, 0);
    int suml = 0;
    for (int i = left; i < right; ++i)
    {
        suml += stoneValue[i];
        int sumr = sum - suml;
        if (suml < sumr)
        {
            f[left][right] =
                max(f[left][right], dfs(stoneValue, left, i) + suml);
        }
        else if (suml > sumr)
        {
            f[left][right] =
                max(f[left][right], dfs(stoneValue, i + 1, right) + sumr);
        }
        else
        {
            f[left][right] =
                max(f[left][right], max(dfs(stoneValue, left, i),
                                        dfs(stoneValue, i + 1, right)) +
                                        suml);
        }
    }
    return f[left][right];
}

// DP
/// Let n be the length of the array stoneValue.
///
/// Time complexity: O(n^3)
///
/// Space complexity: O(n^2)
/// The O(n^2) space is required to store all DP states.
int stoneGameV(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    f.assign(n, vector<int>(n));
    return dfs(stoneValue, 0, n - 1);
}

// DP Optimized
/// Let n be the length of the array stoneValue.
///
/// Time complexity: O(n^3)
///
/// Space complexity: O(n^2)
/// The O(n^2) space is required to store the DP states and the auxiliary arrays
// maxl and maxr.

vector<vector<int>> fI;
vector<vector<int>> maxl, maxr;

int stoneGameV_I(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    fI.assign(n, vector<int>(n));
    maxl.assign(n, vector<int>(n));
    maxr.assign(n, vector<int>(n));
    for (int left = n - 1; left >= 0; --left)
    {
        maxl[left][left] = maxr[left][left] = stoneValue[left];
        int sum = stoneValue[left], suml = 0;
        for (int right = left + 1, i = left - 1; right < n; ++right)
        {
            sum += stoneValue[right];
            while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= sum)
            {
                suml += stoneValue[i + 1];
                ++i;
            }
            if (left <= i)
            {
                fI[left][right] = max(fI[left][right], maxl[left][i]);
            }
            if (i + 1 < right)
            {
                fI[left][right] = max(fI[left][right], maxr[i + 2][right]);
            }
            if (suml * 2 == sum)
            {
                fI[left][right] = max(fI[left][right], maxr[i + 1][right]);
            }
            maxl[left][right] =
                max(maxl[left][right - 1], sum + fI[left][right]);
            maxr[left][right] =
                max(maxr[left + 1][right], sum + fI[left][right]);
        }
    }
    return fI[0][n - 1];
}

int main()
{
    vector<int> stoneValue = {6, 2, 3, 4, 5, 5};
    cout << stoneGameV(stoneValue) << endl;   // Output: 18
    cout << stoneGameV_I(stoneValue) << endl; // Output: 18

    return 0;
}