#include <bits/stdc++.h>
using namespace std;

//    greedy (Difference Increasing) tc O(nlog n) and sc O(log n)
int minimumEffort(vector<vector<int>> &tasks)
{
    sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] - a[0] < b[1] - b[0]; });
    int ans = 0;
    for (auto task : tasks)
    {
        ans = max(ans + task[0], task[1]);
    }
    return ans;
}

//    Greedy (Difference Decreases) tc O(nlog n) and sc O(log n)
int minimumEffortI(vector<vector<int>> &tasks)
{
    sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] - a[0] > b[1] - b[0]; });
    int ans = 0;
    int remain = 0;
    for (auto task : tasks)
    {
        ans += remain > task[1] ? 0 : task[1] - remain;
        remain = max(task[1] - task[0], remain - task[0]);
    }
    return ans;
}

int main()
{

    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
    cout << minimumEffortI(tasks) << endl;

    return 0;
}