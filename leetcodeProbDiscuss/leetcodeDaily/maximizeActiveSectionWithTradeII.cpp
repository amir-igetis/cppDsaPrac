#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> seg;

    void build(int p, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2, l, mid, arr);
        build(p * 2 + 1, mid + 1, r, arr);

        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }

    int query(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return seg[p];

        int mid = (l + r) / 2;
        int ans = 0;

        if (L <= mid)
            ans = max(ans, query(p * 2, l, mid, L, R));

        if (R > mid)
            ans = max(ans, query(p * 2 + 1, mid + 1, r, L, R));

        return ans;
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        seg.assign(4 * n, 0);

        if (n)
            build(1, 0, n - 1, arr);
    }

    int query(int l, int r)
    {
        if (l > r || n == 0)
            return 0;

        return query(1, 0, n - 1, l, r);
    }
};

int lowerBound(vector<int> &v, int target)
{
    int l = 0;
    int r = v.size();

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (v[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int upperBound(vector<int> &v, int target)
{
    int l = 0;
    int r = v.size();

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (v[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

// binary search + segment tree tc O(n+qlogn) and sc O(n)

vector<int> maxActiveSectionsAfterTrade(string s,
                                        vector<vector<int>> &queries)
{

    int n = s.size();

    int cnt1 = 0;
    for (char c : s)
        if (c == '1')
            cnt1++;

    vector<int> zeroBlocks;
    vector<int> blockLeft;
    vector<int> blockRight;

    int i = 0;

    while (i < n)
    {

        int st = i;

        while (i < n && s[i] == s[st])
            i++;

        if (s[st] == '0')
        {
            zeroBlocks.push_back(i - st);
            blockLeft.push_back(st);
            blockRight.push_back(i - 1);
        }
    }

    int m = zeroBlocks.size();

    if (m < 2)
    {
        return vector<int>(queries.size(), cnt1);
    }

    vector<int> tmpSum;

    for (int i = 0; i < m - 1; i++)
        tmpSum.push_back(zeroBlocks[i] + zeroBlocks[i + 1]);

    SegmentTree seg(tmpSum);

    vector<int> ans;

    for (auto &q : queries)
    {

        int l = q[0];
        int r = q[1];

        int idx = lowerBound(blockRight, l);
        int jdx = upperBound(blockLeft, r) - 1;

        if (idx > m - 1 || jdx < 0 || idx >= jdx)
        {
            ans.push_back(cnt1);
            continue;
        }

        int firstLen =
            blockRight[idx] - max(blockLeft[idx], l) + 1;

        int lastLen =
            min(blockRight[jdx], r) - blockLeft[jdx] + 1;

        if (idx + 1 == jdx)
        {
            ans.push_back(cnt1 + firstLen + lastLen);
            continue;
        }

        int val1 = firstLen + zeroBlocks[idx + 1];
        int val2 = zeroBlocks[jdx - 1] + lastLen;
        int val3 = seg.query(idx + 1, jdx - 2);

        int bestGain = max({val1, val2, val3});

        ans.push_back(cnt1 + bestGain);
    }

    return ans;
}

// binary search + sparse table tc O((n+q)logn) and sc O(nlogn)

class SparseTable
{
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &data)
    {
        st.push_back(data);

        int len = 1;
        int N = data.size();

        while (2 * len <= N + 1)
        {
            vector<int> cur;
            vector<int> &pre = st.back();

            for (int i = 0; i + 2 * len - 1 < N; i++)
            {
                cur.push_back(max(pre[i], pre[i + len]));
            }

            st.push_back(cur);
            len <<= 1;
        }
    }

    int query(int L, int R)
    {
        if (L > R)
            return 0;

        int len = R - L + 1;
        int lg = 31 - __builtin_clz(len);

        return max(st[lg][L],
                   st[lg][R - (1 << lg) + 1]);
    }
};

int lowerBoundI(vector<int> &v, int target)
{
    int l = 0, r = v.size();

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (v[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int upperBoundI(vector<int> &v, int target)
{
    int l = 0, r = v.size();

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (v[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

vector<int> maxActiveSectionsAfterTradeI(
    string s,
    vector<vector<int>> &queries)
{

    int n = s.size();

    int cnt1 = 0;
    for (char c : s)
        if (c == '1')
            cnt1++;

    vector<int> zeroBlocks;
    vector<int> blockLeft;
    vector<int> blockRight;

    int i = 0;

    while (i < n)
    {

        int st = i;

        while (i < n && s[i] == s[st])
            i++;

        if (s[st] == '0')
        {
            zeroBlocks.push_back(i - st);
            blockLeft.push_back(st);
            blockRight.push_back(i - 1);
        }
    }

    int m = zeroBlocks.size();

    if (m < 2)
        return vector<int>(queries.size(), cnt1);

    vector<int> tmpSum;

    for (int i = 0; i < m - 1; i++)
        tmpSum.push_back(zeroBlocks[i] + zeroBlocks[i + 1]);

    SparseTable st(tmpSum);

    vector<int> ans;

    for (auto &q : queries)
    {

        int l = q[0];
        int r = q[1];

        int idx = lowerBoundI(blockRight, l);
        int jdx = upperBoundI(blockLeft, r) - 1;

        if (idx > m - 1 || jdx < 0 || idx >= jdx)
        {
            ans.push_back(cnt1);
            continue;
        }

        int firstLen =
            blockRight[idx] - max(blockLeft[idx], l) + 1;

        int lastLen =
            min(blockRight[jdx], r) - blockLeft[jdx] + 1;

        if (idx + 1 == jdx)
        {
            ans.push_back(cnt1 + firstLen + lastLen);
            continue;
        }

        int val1 = firstLen + zeroBlocks[idx + 1];
        int val2 = zeroBlocks[jdx - 1] + lastLen;
        int val3 = st.query(idx + 1, jdx - 2);

        int bestGain = max({val1, val2, val3});

        ans.push_back(cnt1 + bestGain);
    }

    return ans;
}

// mo algo tc O(qlogq + n root(n) + q root(n)) sc O(n)

vector<int> maxActiveSectionsAfterTradeII(string s,
                                          vector<vector<int>> &queries)
{
    int n = s.length(), m = queries.size();
    int cnt1 = count(s.begin(), s.end(), '1');
    // left[i]: represents the length of the continuous block ending at
    // position i, which is the same as s[i]
    vector<int> left(n, -1);
    // right[i]: represents the length of the continuous block starting at
    // position i with the same value as s[i]
    vector<int> right(n, -1);

    for (int i = 0; i < n; i++)
    {
        left[i] = (i > 0 && s[i - 1] == s[i]) ? left[i - 1] + 1 : 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = (i < n - 1 && s[i + 1] == s[i]) ? right[i + 1] + 1 : 1;
    }

    vector<int> ans(m, -1);
    int block_size = (int)sqrt(n);
    // query with length greater than block length
    vector<tuple<int, int, int, int>> longQueries;

    auto brute_force = [&](int l, int r) -> int
    {
        int i = l;
        int best = 0;
        int prev = INT_MIN;

        while (i <= r)
        {
            int start = i;
            while (i <= r && s[i] == s[start])
            {
                i++;
            }
            if (s[start] == '0')
            {
                int cur = i - start;
                best = (prev != INT_MIN && prev + cur > best) ? prev + cur
                                                              : best;
                prev = cur;
            }
        }
        return best;
    };

    for (int i = 0; i < m; i++)
    {
        int l = queries[i][0], r = queries[i][1];
        if (r - l + 1 > block_size)
        {
            longQueries.push_back({l / block_size, l, r, i});
        }
        else
        {
            // queries shorter than block length, brute-force calculation
            ans[i] = cnt1 + brute_force(l, r);
        }
    }

    // sort by the ID of the block where the left endpoint is located as the
    // first keyword, and by the right endpoint as the second keyword
    sort(longQueries.begin(), longQueries.end(),
         [](const tuple<int, int, int, int> &a,
            const tuple<int, int, int, int> &b)
         {
             if (get<0>(a) != get<0>(b))
                 return get<0>(a) < get<0>(b);
             return get<2>(a) < get<2>(b);
         });

    deque<int> subZeroBlocks;
    int L = 0, R = 0, bestGain = 0;

    for (int i = 0; i < longQueries.size(); i++)
    {
        int bid = get<0>(longQueries[i]);
        int l = get<1>(longQueries[i]);
        int r = get<2>(longQueries[i]);
        int qid = get<3>(longQueries[i]);

        if (i == 0 || bid > get<0>(longQueries[i - 1]))
        {
            // traverse to a new block, perform initialization operations
            L = (bid + 1) * block_size -
                1;                      // L is initialized as the right endpoint of the block
            R = (bid + 1) * block_size; // R is initialized to the left
                                        // endpoint of the next block
            subZeroBlocks.clear();
            bestGain = 0;
        }

        while (R <= r)
        {
            int sz = min(r - R + 1, right[R]);
            if (s[R] == '0')
            {
                if (!subZeroBlocks.empty() && s[R - 1] == '0')
                {
                    subZeroBlocks.back() += sz;
                }
                else
                {
                    subZeroBlocks.push_back(sz);
                }
                if (subZeroBlocks.size() >= 2)
                {
                    bestGain =
                        max(subZeroBlocks.back() +
                                subZeroBlocks[subZeroBlocks.size() - 2],
                            bestGain);
                }
            }
            R += sz;
        }

        // before moving the left endpoint L, backup the value of bestGain
        int tmp_bestGain = bestGain;
        // value of the first element of subZeroBlocks before moving the
        // left endpoint
        int tmp_firstValue =
            subZeroBlocks.empty() ? -1 : subZeroBlocks.front();
        // the number of digits added from the left during the process of
        // recording the movement of the left endpoint L
        int cnt = 0;

        while (L >= l)
        {
            int sz = min(L - l + 1, left[L]);
            if (s[L] == '0')
            {
                if (!subZeroBlocks.empty() && s[L + 1] == '0')
                {
                    subZeroBlocks.front() += sz;
                }
                else
                {
                    subZeroBlocks.push_front(sz);
                    cnt++;
                }
                if (subZeroBlocks.size() >= 2)
                {
                    bestGain =
                        max(subZeroBlocks[0] + subZeroBlocks[1], bestGain);
                }
            }
            L -= sz;
        }

        // answering inquiries
        ans[qid] = bestGain + cnt1;
        // restore left endpoint L
        L = (bid + 1) * block_size - 1;
        // restore bestGain
        bestGain = tmp_bestGain;
        // restore subZeroBlocks
        for (int j = 0; j < cnt; j++)
        {
            subZeroBlocks.pop_front();
        }
        if (tmp_firstValue != -1)
        {
            subZeroBlocks[0] = tmp_firstValue;
        }
    }
    return ans;
}

int main()
{

    string s = "1000100";

    vector<vector<int>> queries = {
        {1, 5},
        {0, 6},
        {0, 4}};

    vector<int> ans = maxActiveSectionsAfterTrade(s, queries);

    for (int x : ans)
        cout << x << " ";

    cout << endl;
}