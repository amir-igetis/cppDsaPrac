#include <bits/stdc++.h>
using namespace std;

int leastIntervalI(vector<char> &tasks, int n)
{
    unordered_map<char, int> mp;
    for (char task : tasks)
        mp[task]++;

    priority_queue<int> maxHeap;
    for (auto &entry : mp)
        maxHeap.push(entry.second);

    int intervals = 0;
    while (!maxHeap.empty())
    {
        int time = 0;
        vector<int> cooldown;
        for (int i = 0; i <= n; i++)
        {
            if (!maxHeap.empty())
            {
                cooldown.push_back(maxHeap.top() - 1);
                maxHeap.pop();
                time++;
            }
        }

        for (int count : cooldown)
        {
            if (count > 0)
                maxHeap.push(count);
        }

        intervals += maxHeap.empty() ? time : (n + 1);
    }
    return intervals;
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastIntervalI(tasks, n) << endl;

    return 0;
}