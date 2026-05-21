#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return 0;

    unordered_map<int, vector<int>> mp;

    // Store indices for each value
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }

    queue<int> q;
    vector<bool> visited(n, false);

    q.push(0);
    visited[0] = true;

    int steps = 0;

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int idx = q.front();
            q.pop();

            // Reached last index
            if (idx == n - 1)
                return steps;

            // Jump to idx - 1
            if (idx - 1 >= 0 && !visited[idx - 1])
            {
                visited[idx - 1] = true;
                q.push(idx - 1);
            }

            // Jump to idx + 1
            if (idx + 1 < n && !visited[idx + 1])
            {
                visited[idx + 1] = true;
                q.push(idx + 1);
            }

            // Jump to same value indices
            for (int nextIdx : mp[arr[idx]])
            {
                if (!visited[nextIdx])
                {
                    visited[nextIdx] = true;
                    q.push(nextIdx);
                }
            }

            // Clear to avoid repeated processing
            mp[arr[idx]].clear();
        }

        steps++;
    }

    return -1;
}

int main()
{
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << minJumps(arr) << endl;

    return 0;
}