#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> res;
    if (nums1.empty() || nums2.empty() || k == 0)
        return res;

    // minHeap stores {sum, i, j}
    auto cmp = [](const vector<int> &a, const vector<int> &b)
    {
        return a[0] > b[0]; // min-heap by sum
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

    // Push first k pairs (nums1[i] + nums2[0])
    for (int i = 0; i < min((int)nums1.size(), k); i++)
    {
        minHeap.push({nums1[i] + nums2[0], i, 0});
    }

    while (k-- > 0 && !minHeap.empty())
    {
        auto top = minHeap.top();
        minHeap.pop();

        int i = top[1], j = top[2];
        res.push_back({nums1[i], nums2[j]});

        if (j + 1 < nums2.size())
        {
            minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
    }

    return res;
}

int main()
{

    vector<int> nums1 = {1, 1, 2}, nums2 = {1, 2, 3};
    int k = 2;

    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);

    for (auto &i : ans)
    {
        for (int j : i)
            cout << j << " ";

        cout << endl;
    }

    return 0;
}