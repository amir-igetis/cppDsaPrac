#include <bits/stdc++.h>
using namespace std;

// brute force tc O(2 ^ n * n log n) & sc O(n)
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    int maxValid = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<vector<int>> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                subset.push_back(intervals[i]);
        }
        sort(subset.begin(), subset.end());
        bool valid = true;
        for (int i = 1; i < subset.size(); i++)
        {
            if (subset[i][0] < subset[i - 1][1])
            {
                valid = false;
                break;
            }
        }
        if (valid)
            maxValid = max(maxValid, (int)subset.size());
    }
    return n - maxValid;
}

int main()
{

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}