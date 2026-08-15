#include <bits/stdc++.h>
using namespace std;

// segment tree
/// Let n be the length of the string s, and let k be the number of queries.
///
/// Time complexity: O((n+k)logn).
///
/// Building the segment tree initially takes O(n) time. Each query performs a single-point update, which takes O(logn) time. Therefore, the total time complexity is O(n+klogn).
///
/// Space complexity: O(n).
///
/// The segment tree uses arrays of size O(n).
vector<int> longestRepeating(string s, string queryCharacters,
                             vector<int> &queryIndices)
{
    int n = s.size();
    vector<int> pre(4 * n), suf(4 * n), maxLen(4 * n);
    vector<char> leftChar(4 * n), rightChar(4 * n);

    auto pushUp = [&](int u, int l, int r)
    {
        int mid = (l + r) >> 1;
        int leftLen = mid - l + 1, rightLen = r - mid;
        int left = u << 1, right = u << 1 | 1;
        leftChar[u] = leftChar[left];
        rightChar[u] = rightChar[right];
        pre[u] = pre[left];
        if (pre[left] == leftLen && rightChar[left] == leftChar[right])
        {
            pre[u] = pre[left] + pre[right];
        }
        suf[u] = suf[right];
        if (suf[right] == rightLen && rightChar[left] == leftChar[right])
        {
            suf[u] = suf[right] + suf[left];
        }
        maxLen[u] = max(maxLen[left], maxLen[right]);
        if (rightChar[left] == leftChar[right])
        {
            maxLen[u] = max(maxLen[u], suf[left] + pre[right]);
        }
    };

    function<void(int, int, int)> build = [&](int u, int l, int r)
    {
        if (l == r)
        {
            pre[u] = 1;
            suf[u] = 1;
            maxLen[u] = 1;
            leftChar[u] = s[l];
            rightChar[u] = s[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushUp(u, l, r);
    };

    function<void(int, int, int, int, char)> update =
        [&](int u, int l, int r, int pos, char ch)
    {
        if (l == r)
        {
            leftChar[u] = ch;
            rightChar[u] = ch;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            update(u << 1, l, mid, pos, ch);
        }
        else
        {
            update(u << 1 | 1, mid + 1, r, pos, ch);
        }
        pushUp(u, l, r);
    };

    build(1, 0, n - 1);
    int k = queryIndices.size();
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans[i] = maxLen[1];
    }
    return ans;
}

// Ordered Set Simulating Interval Merging
/// Let n be the length of the string s, and let k be the number of queries.
///
/// Time complexity: O((n+k)logn).
///
/// Constructing the initial intervals requires O(n) time. For each query, we perform a constant number of searches, deletions, and insertions in the ordered sets, each taking O(logn) time. Therefore, the total time complexity is O(n+klogn).
///
/// Space complexity: O(n).
///
/// There can be at most n intervals, so the ordered sets require O(n) space.

vector<int> longestRepeatingI(string s, string queryCharacters,
                              vector<int> &queryIndices)
{
    int n = s.size();
    set<pair<int, int>> segs;
    multiset<int> lens;

    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == s[i])
        {
            j++;
        }
        segs.insert({i, j - 1});
        lens.insert(j - i);
        i = j;
    }

    int k = queryIndices.size();
    vector<int> ans(k);

    for (int q = 0; q < k; q++)
    {
        int pos = queryIndices[q];
        char ch = queryCharacters[q];

        if (s[pos] != ch)
        {
            auto it = segs.upper_bound({pos, INT_MAX});
            --it;
            int L = it->first, R = it->second;
            segs.erase(it);
            lens.erase(lens.find(R - L + 1));

            if (L <= pos - 1)
            {
                segs.insert({L, pos - 1});
                lens.insert(pos - L);
            }
            if (pos + 1 <= R)
            {
                segs.insert({pos + 1, R});
                lens.insert(R - pos);
            }

            int newL = pos, newR = pos;

            auto rightIt = segs.lower_bound({pos + 1, 0});
            if (rightIt != segs.end() && rightIt->first == pos + 1 &&
                s[pos + 1] == ch)
            {
                lens.erase(lens.find(rightIt->second - rightIt->first + 1));
                newR = rightIt->second;
                segs.erase(rightIt);
            }

            auto leftIt = segs.lower_bound({pos, 0});
            if (leftIt != segs.begin())
            {
                --leftIt;
                if (leftIt->second == pos - 1 && s[pos - 1] == ch)
                {
                    lens.erase(
                        lens.find(leftIt->second - leftIt->first + 1));
                    newL = leftIt->first;
                    segs.erase(leftIt);
                }
            }

            segs.insert({newL, newR});
            lens.insert(newR - newL + 1);
            s[pos] = ch;
        }

        ans[q] = *lens.rbegin();
    }

    return ans;
}

int main()
{
    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndices = {1, 3, 3};

    vector<int> result = longestRepeating(s, queryCharacters, queryIndices);
    for (int len : result)
    {
        cout << len << " ";
    }
    cout << endl;

    result = longestRepeatingI(s, queryCharacters, queryIndices);
    for (int len : result)
    {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
