#include <bits/stdc++.h>
using namespace std;

//    hash table + binary tree tc O(m + m log n) sc O(n)

vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    unordered_map<int, vector<int>> numsPos;

    // store positions
    for (int i = 0; i < n; i++)
    {
        numsPos[nums[i]].push_back(i);
    }

    // process each value group
    for (auto it = numsPos.begin(); it != numsPos.end(); ++it)
    {
        vector<int> &pos = it->second;

        int first = pos[0];

        // make circular
        pos.insert(pos.begin(), pos.back() - n);
        pos.push_back(first + n);
    }

    int m = queries.size();

    for (int i = 0; i < m; i++)
    {
        int idx = queries[i];
        int val = nums[idx];

        vector<int> &pos = numsPos[val];

        // only one occurrence → no valid answer
        if (pos.size() == 3)
        {
            queries[i] = -1;
            continue;
        }

        int p = lower_bound(pos.begin(), pos.end(), idx) - pos.begin();

        queries[i] = min(
            pos[p + 1] - pos[p],
            pos[p] - pos[p - 1]);
    }

    return queries;
}

//    Preprocessing Nearest Left and Right Positions + Hash Table tc O(n + m) sc O(n)

vector<int> solveQueriesI(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    vector<int> left(n, -1), right(n, 2 * n);
    unordered_map<int, int> pos;

    // LEFT nearest
    for (int i = -n; i < n; i++)
    {
        int idx = (i + n) % n;

        if (i >= 0 && pos.count(nums[idx]))
        {
            left[idx] = pos[nums[idx]];
        }

        pos[nums[idx]] = i;
    }

    pos.clear();

    // RIGHT nearest
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;

        if (i < n && pos.count(nums[idx]))
        {
            right[idx] = pos[nums[idx]];
        }

        pos[nums[idx]] = i;
    }

    int m = queries.size();

    for (int i = 0; i < m; i++)
    {
        int x = queries[i];

        if (left[x] == -1 && right[x] == 2 * n)
        {
            queries[i] = -1;
        }
        else
        {
            queries[i] = min(x - left[x], right[x] - x);
        }
    }

    return queries;
}

int main()
{
    vector<int> nums = {1, 3, 1, 4, 1, 3, 2}, queries = {0, 3, 5};
    vector<int> ans = solveQueriesI(nums, queries);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}