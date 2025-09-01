#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
        return 0;

    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int arrows = 1;
    long long lastEnd = points[0][1];

    for (auto &ballon : points)
    {
        if (ballon[0] > lastEnd)
        {
            arrows++;
            lastEnd = ballon[1];
        }
    }
    return arrows;
}

int main()
{

    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}