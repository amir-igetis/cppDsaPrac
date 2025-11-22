#include <bits/stdc++.h>
using namespace std;

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
         {
            if (a[1] != b[1])
            return a[1] < b[1];

            return a[0] > b[0]; });

    int a = -1, b = -1;
    int count = 0;

    for (auto &in : intervals)
    {
        int start = in[0], end = in[1];

        bool hasA = (a >= start && a <= end);
        bool hasB = (b >= start && b <= end);

        if (hasA && hasB)
        {
            continue;
        }
        else if (hasA)
        {
            count++;
            b = a;
            a = end;
        }
        else
        {
            count += 2;
            b = end - 1;
            a = end;
        }
    }
    return count;
}

int main()
{

    vector<vector<int>> intervals = {{1, 3}, {3, 7}, {8, 9}};
    cout << intersectionSizeTwo(intervals) << endl;

    return 0;
}