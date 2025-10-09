#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int> &rains)
{
    int n = rains.size();
    vector<int> ans(n, 1);
    unordered_map<int, int> lastRain;
    set<int> dryDays;

    for (int i = 0; i < n; i++)
    {
        if (rains[i] > 0)
        {
            int lake = rains[i];
            if (lastRain.count(lake))
            {
                auto it = dryDays.lower_bound(lastRain[lake]);
                if (it == dryDays.end())
                    return {};

                ans[*it] = lake;
                dryDays.erase(it);
            }
            lastRain[lake] = i;
            ans[i] = -1;
        }
        else
        {
            dryDays.insert(i);
        }
    }
    return ans;
}

// using priority queue
vector<int> avoidFloodI(vector<int> &rains)
{
    int n = rains.size();
    vector<int> ans(n, 1);

    unordered_map<int, queue<int>> futureRains;
    for (int i = 0; i < n; i++)
    {
        if (rains[i] > 0)
            futureRains[rains[i]].push(i);
    }

    unordered_set<int> full;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < n; i++)
    {
        if (rains[i] > 0)
        {
            int lake = rains[i];
            futureRains[lake].pop();

            if (full.count(lake))
                return {};

            full.insert(lake);
            ans[i] = -1;

            if (!futureRains[lake].empty())
                pq.push({futureRains[lake].front(), lake});
        }
        else
        {
            if (!pq.empty())
            {
                auto day = pq.top().first;
                auto lake = pq.top().second;
                pq.pop();
                ans[i] = lake;
                full.erase(lake);
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> rains = {1, 2, 0, 0, 2, 1};
    vector<int> ans = avoidFloodI(rains);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}