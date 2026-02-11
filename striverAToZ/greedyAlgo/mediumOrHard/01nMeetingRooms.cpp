#include <bits/stdc++.h>
using namespace std;

//  tc O(n logn) + O(n) & sc O(n)
vector<int> maxMeetings(vector<int> &start, vector<int> &end)
{
    vector<tuple<int, int, int>> meetings;
    for (int i = 0; i < start.size(); i++)
    {
        meetings.push_back({end[i], start[i], i + 1});
    }
    sort(meetings.begin(), meetings.end());
    vector<int> res;
    int lastEnd = -1;
    for (auto &m : meetings)
    {
        int e = get<0>(m);
        int s = get<1>(m);
        int idx = get<2>(m);
        if (s > lastEnd)
        {
            res.push_back(idx);
            lastEnd = e;
        }
    }
    return res;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> ans = maxMeetings(start, end);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}