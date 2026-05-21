#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &arr, int idx, vector<bool> &vis)
{
    int n = arr.size();
    if (idx < 0 || idx >= n || vis[idx])
        return false;

    if (arr[idx] == 0)
        return true;

    vis[idx] = true;
    return dfs(arr, idx + arr[idx], vis) ||
           dfs(arr, idx - arr[idx], vis);
}

bool canReach(vector<int> &arr, int start)
{
    vector<bool> vis(arr.size(), false);

    return dfs(arr, start, vis);
}

int main()
{
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    cout << (canReach(arr, start) ? "True" : "False") << endl;

    return 0;
}