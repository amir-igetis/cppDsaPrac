#include <bits/stdc++.h>
using namespace std;

// brute force O(n^2) & sc O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    // for (int i = 0; i < n; )
    int i = 0;
    while (i < n)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        int j = i + 1;
        while (j < n && intervals[j][0] <= end)
        {
            end = max(end, intervals[j][i]);
            j++;
        }
        ans.push_back({start, end});
        i = j;
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);

    for (auto &i : result)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}