#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> projects(n);

    // Store (capital required, profit)
    for (int i = 0; i < n; i++)
        projects[i] = {capital[i], profits[i]};

    // Sort projects by required capital ascending
    sort(projects.begin(), projects.end());

    priority_queue<int> maxHeap; // Max-heap to store available profits
    int i = 0;

    while (k-- > 0)
    {
        // Add all projects whose capital requirement <= current w
        while (i < n && projects[i].first <= w)
        {
            maxHeap.push(projects[i].second);
            i++;
        }

        // If no project is available, break early
        if (maxHeap.empty())
            break;

        // Do the most profitable project
        w += maxHeap.top();
        maxHeap.pop();
    }

    return w;
}

int main()
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};

    cout << findMaximizedCapital(k, w, profits, capital) << endl; // Output: 4

    return 0;
}
