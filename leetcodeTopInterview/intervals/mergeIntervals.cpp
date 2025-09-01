#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    for (auto &interval : intervals)
    {

        if (merged.empty() || merged.back()[1] < interval[0])
            merged.push_back(interval);
        else
            merged.back()[1] = max(merged.back()[1], interval[1]);
    }
    return merged;
}

int main()
{

    vector<vector<int>> intervals = {{1, 4}, {4, 5}};

    vector<vector<int>> ans = merge(intervals);

    cout << "[";
    for (auto &i : ans)
    {
        cout << "[" << i[0] << "," << i[1] << "]";
    }
    cout << "]" << endl;

    return 0;
}