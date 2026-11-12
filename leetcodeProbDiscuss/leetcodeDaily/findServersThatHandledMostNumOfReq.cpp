#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Striver's standard template style for Segment Trees
    struct SGTree
    {
        vector<int> seg;

        SGTree(int n)
        {
            // Standard 4*n allocation for Segment Tree
            seg.resize(4 * n + 1, 0);
        }

        // Point update: updates the release time of a specific server
        void update(int ind, int low, int high, int i, int val)
        {
            if (low == high)
            {
                seg[ind] = val;
                return;
            }
            int mid = low + (high - low) / 2;
            if (i <= mid)
            {
                update(2 * ind + 1, low, mid, i, val);
            }
            else
            {
                update(2 * ind + 2, mid + 1, high, i, val);
            }
            // Store the minimum available time in the range
            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        }

        // Binary search on Segment Tree to find the earliest server ID available <= val
        int query(int ind, int low, int high, int l, int r, int val)
        {
            // Out of range or no server in this segment is free by 'val' (arrival time)
            if (r < low || high < l || seg[ind] > val)
            {
                return -1;
            }

            // Reached the exact server (leaf node)
            if (low == high)
            {
                return low;
            }

            int mid = low + (high - low) / 2;

            // Always try to traverse the left child first to guarantee the smallest index
            int left = query(2 * ind + 1, low, mid, l, r, val);
            if (left != -1)
            {
                return left;
            }

            // If no server was found on the left, search the right child
            return query(2 * ind + 2, mid + 1, high, l, r, val);
        }
    };

public:
    // Time: O(N log K), Space: O(K)
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        vector<int> requestsHandled(k, 0);

        // set stores available server IDs for fast O(log k) lookups
        set<int> availableServers;
        for (int i = 0; i < k; ++i)
        {
            availableServers.insert(i);
        }

        // priority_queue stores {freeTime, serverId}, ordered by freeTime ascending (min-heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;

        int maxRequests = 0;

        for (int i = 0; i < (int)arrival.size(); ++i)
        {
            int arrivalTime = arrival[i];
            int loadTime = load[i];

            // Free up servers that have finished their tasks by the current arrival time
            while (!busyServers.empty() && busyServers.top().first <= arrivalTime)
            {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            // If no servers are available, drop the request
            if (availableServers.empty())
            {
                continue;
            }

            // Find the assigned server using wrap-around logic
            int targetServer = i % k;
            auto it = availableServers.lower_bound(targetServer);

            // Wrap around to the beginning if no server is available at or after targetServer
            if (it == availableServers.end())
            {
                it = availableServers.begin();
            }

            int assignedServer = *it;

            // Mark the assigned server as busy
            availableServers.erase(it);
            busyServers.push({arrivalTime + loadTime, assignedServer});

            // Update counts and track the maximum
            requestsHandled[assignedServer]++;
            maxRequests = max(maxRequests, requestsHandled[assignedServer]);
        }

        // Collect all servers that handled the maximum number of requests
        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            if (requestsHandled[i] == maxRequests)
            {
                result.push_back(i);
            }
        }

        return result;
    }

    // Time: O(N log K), Space: O(K) using Segment Tree
    vector<int> busiestServersI(int k, vector<int> &arrival, vector<int> &load)
    {
        SGTree sg(k);
        vector<int> requests(k, 0);
        int maxReq = 0;

        for (int i = 0; i < (int)arrival.size(); ++i)
        {
            int arr = arrival[i];
            int time = load[i];
            int target = i % k;

            // Query 1: Try to find a server in the range [target, k - 1]
            int serverId = sg.query(0, 0, k - 1, target, k - 1, arr);

            // Query 2: Wrap around and search the range [0, target - 1]
            if (serverId == -1 && target > 0)
            {
                serverId = sg.query(0, 0, k - 1, 0, target - 1, arr);
            }

            // If a server is found, process the load and update the Segment Tree
            if (serverId != -1)
            {
                requests[serverId]++;
                maxReq = max(maxReq, requests[serverId]);

                // Update the server's next available time
                sg.update(0, 0, k - 1, serverId, arr + time);
            }
        }

        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            if (requests[i] == maxReq)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};
    int k = 3;

    vector<int> result = solution.busiestServers(k, arrival, load);
    vector<int> resultI = solution.busiestServersI(k, arrival, load);

    for (int server : result)
    {
        cout << server << " ";
    }
    cout << endl;
    for (int server : resultI)
    {
        cout << server << " ";
    }
    cout << endl;

    return 0;
}