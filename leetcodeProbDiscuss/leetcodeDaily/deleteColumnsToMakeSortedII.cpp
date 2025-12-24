#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &strs)
{
    int n = strs.size();
    int w = strs[0].length();
    vector<bool> sorted(n - 1, false);
    int deletions = 0;

    for (int col = 0; col < w; col++)
    {
        bool deleteCol = false;

        // FIX 1: compare i with i+1
        for (int i = 0; i < n - 1; i++)
        {
            if (!sorted[i] && strs[i][col] > strs[i + 1][col])
            {
                deleteCol = true;
                break;
            }
        }

        if (deleteCol)
        {
            deletions++;
            continue;
        }

        // FIX 2: mark sorted only when <
        for (int i = 0; i < n - 1; i++)
        {
            if (!sorted[i] && strs[i][col] < strs[i + 1][col])
                sorted[i] = true;
        }
    }
    return deletions;
}

// greedy approach leetcode
bool isSorted(const vector<string> &strs)
{
    for (int i = 0; i < (int)strs.size() - 1; i++)
    {
        if (strs[i] > strs[i + 1])
            return false;
    }
    return true;
}

int minDeletionSizeI(vector<string> &strs)
{
    int n = strs.size();
    int w = strs[0].size();
    int ans = 0;

    // Initialize with empty strings
    vector<string> curr(n, "");

    for (int j = 0; j < w; j++)
    {
        vector<string> curr2 = curr;

        for (int i = 0; i < n; i++)
        {
            curr2[i].push_back(strs[i][j]);
        }

        if (isSorted(curr2))
        {
            curr = curr2;
        }
        else
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<string> strs = {"ca", "bb", "ac"};
    cout << minDeletionSizeI(strs) << endl; // OUTPUT: 1
    return 0;
}
