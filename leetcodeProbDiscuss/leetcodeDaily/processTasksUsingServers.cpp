#include <bits/stdc++.h>
using namespace std;

// Priority Queue

/// Let m and n be the lengths of servers and tasks, respectively.
///
/// Time complexity: O((m+n)logm) or O(m+nlogm).
///
/// Putting all servers into idle takes O(mlogm) or O(m) time, depending on the API used.
///
/// Iterating through the tasks takes O(n) time. Each task is assigned exactly one server. This assignment moves the server from idle to busy, and at some future time, when the task finishes, the server moves back from busy to idle. Therefore, each task incurs O(1) amortized priority queue operations. Since each priority queue operation takes O(logm) time, processing all tasks takes O(nlogm) time, leading to a total time complexity of O((m+n)logm) (or O(m+nlogm) if a linear-time heapify is supported).
///
/// Space complexity: O(m).
///
/// This is the space required by the priority queues busy and idle (excluding the O(n) space for the return array)

class Solution
{
private:
    using PLI = pair<long long, int>;
    using PII = pair<int, int>;

public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int m = servers.size();
        int n = tasks.size();

        // Busy servers, stored as pairs (t, idx)
        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        // Idle servers, stored as pairs (w, idx)
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        for (int i = 0; i < m; ++i)
        {
            idle.emplace(servers[i], i);
        }

        long long ts = 0;
        // Move servers with t<=ts from priority queue busy to priority queue
        // idle one by one
        auto release = [&]()
        {
            while (!busy.empty() && busy.top().first <= ts)
            {
                int idx = busy.top().second; // Replaced structured binding
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty())
            {
                ts = busy.top().first;
                release();
            }
            int idx = idle.top().second; // Replaced structured binding
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> servers = {3, 3, 2}, tasks = {1, 2, 3, 2, 1, 2};
    Solution solution;
    vector<int> ans = solution.assignTasks(servers, tasks);
    cout << "[";
    for (size_t i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << "]";

    return 0;
}