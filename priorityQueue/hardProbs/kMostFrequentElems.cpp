#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int num : nums)
        mp[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (const auto &pair : mp)
    {
        int num = pair.first;
        int frequency = pair.second;
        minHeap.push({frequency, num});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> res;
    while (!minHeap.empty())
    {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}

int main()
{

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}