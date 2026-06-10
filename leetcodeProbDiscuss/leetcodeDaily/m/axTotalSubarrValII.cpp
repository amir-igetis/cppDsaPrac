#include <bits/stdc++.h>
using namespace std;

// sparse table + max heap tc O(nlogn+klogn) + sc O(nlogn)

long long maxTotalValue(vector<int> &nums, int k)
{
    int n = nums.size();
    int logn = 32 - __builtin_clz(n);
    vector<vector<int>> stMax(n, vector<int>(logn));
    vector<vector<int>> stMin(n, vector<int>(logn));
    for (int i = 0; i < n; i++)
    {
        stMax[i][0] = stMin[i][0] = nums[i];
    }
    for (int j = 1; j < logn; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            stMax[i][j] =
                max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] =
                min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto queryMax = [&](int l, int r)
    {
        int j = 31 - __builtin_clz(r - l + 1);
        return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
    };
    auto queryMin = [&](int l, int r)
    {
        int j = 31 - __builtin_clz(r - l + 1);
        return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
    };
    priority_queue<tuple<int, int, int>> pq;
    for (int l = 0; l < n; l++)
    {
        pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
    }
    long long ans = 0;
    while (k--)
    {
        tuple<int, int, int> cur = pq.top();
        pq.pop();

        int val = get<0>(cur);
        int l = get<1>(cur);
        int r = get<2>(cur);

        ans += val;

        if (r > l)
        {
            pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
        }
    }
    return ans;
}

// segment tree + max heap tc O((n + k)logn) & sc O(n)
class SegTree
{
    vector<int> maxv, minv;
    int n;

public:
    SegTree(vector<int> &nums)
    {
        n = nums.size();
        maxv.resize(n * 4);
        minv.resize(n * 4);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return maxv[node];
        }
        int m = (l + r) / 2, res = INT_MIN;
        if (ql <= m)
        {
            res = max(res, queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m)
        {
            res = max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    int queryMin(int node, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return minv[node];
        }
        int m = (l + r) / 2, res = INT_MAX;
        if (ql <= m)
        {
            res = min(res, queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m)
        {
            res = min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
};

long long maxTotalValue(vector<int> &nums, int k)
{
    int n = nums.size();
    SegTree seg(nums);
    priority_queue<tuple<int, int, int>> pq;
    for (int l = 0; l < n; l++)
    {
        pq.emplace(seg.queryMax(1, 0, n - 1, l, n - 1) -
                       seg.queryMin(1, 0, n - 1, l, n - 1),
                   l, n - 1);
    }
    long long ans = 0;
    while (k--)
    {
        tuple<int, int, int> cur = pq.top();
        pq.pop();

        int val = get<0>(cur);
        int l = get<1>(cur);
        int r = get<2>(cur);

        ans += val;

        if (r > l)
        {
            pq.emplace(
                seg.queryMax(1, 0, n - 1, l, r - 1) -
                    seg.queryMin(1, 0, n - 1, l, r - 1),
                l,
                r - 1);
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 3, 2};
    int k = 2;
    cout << maxTotalValue(nums, k) << endl;

    return 0;
}