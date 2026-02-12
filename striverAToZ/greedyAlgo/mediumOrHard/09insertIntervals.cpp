#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;

    // add intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    // merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    // add remaining intervals
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {10, 15}, {20, 30}};
    vector<int> newEvent = {5, 6};

    vector<vector<int>> result = insertInterval(intervals, newEvent);

    for (auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
