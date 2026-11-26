#include <bits/stdc++.h>
using namespace std;

// Binary Search on the Answer + Rolling Hash

/// Let n be the length of nums.
///
/// Time complexity: O(nlogn).
///
/// Precomputing prefix hashes takes O(n) time. Binary search considers O(logn) lengths. Each check examines at most n subarrays, computing each hash in O(1) time and counting occurrences with a hash table. Each check therefore takes O(n) time, giving O(nlogn) overall.
///
/// Space complexity: O(n).
///
/// The prefix hash and base-power arrays each require O(n) space. The hash table used by each check stores at most O(n) values.
using ll = long long;

int smallestUniqueSubarray(vector<int> &nums)
{
    constexpr ll MOD = 1000000007LL;
    constexpr ll BASE = 911382323LL;

    int n = (int)nums.size();
    vector<ll> h(n + 1);
    vector<ll> p(n + 1);
    p[0] = 1;

    // Compute prefix hashes and powers of BASE
    for (int i = 0; i < n; ++i)
    {
        h[i + 1] = (h[i] * BASE + nums[i]) % MOD;
        p[i + 1] = p[i] * BASE % MOD;
    }

    auto check = [&](int len)
    {
        unordered_map<ll, int> cnt;

        for (int l = 0; l + len <= n; ++l)
        {
            int r = l + len;

            ll key = (h[r] - h[l] * p[len] % MOD + MOD) % MOD;
            ++cnt[key];
        }

        for (auto &entry : cnt)
        {
            if (entry.second == 1)
            {
                return true;
            }
        }
        return false;
    };

    int lo = 1, hi = n;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

// Suffix Array

/// Let n be the length of nums, and U=max(nums). The given range of nums[i] is of the same order as n, so n is also used when analyzing counting sort.
///
/// Time complexity: O(nlogn) (or O(nlog
/// 2
///  n) in Python).
///
/// Constructing sa with doubling optimized by counting sort takes O(nlogn) time (in Python, sorting tuples with standard sort takes O(nlog
/// 2
///  n)). Kasai's algorithm computes the longest common prefix array in O(n) amortized time. The overall time complexity is therefore O(nlogn).
///
/// Space complexity: O(n).
///
/// The suffix array sa, rank, and other auxiliary arrays each require O(n) space. The counting-sort array requires O(n+U) space, which can be approximated as O(n) in this problem.
int smallestUniqueSubarrayI(vector<int> &nums)
{
    int n = (int)nums.size();

    vector<int> sa(n), rank(nums.begin(), nums.end());
    vector<int> nextRank(n);

    iota(sa.begin(), sa.end(), 0);

    // Construct the sorted suffix array by doubling
    int maxRank = *max_element(nums.begin(), nums.end());
    vector<int> temp(n), cnt(std::max(n + 1, maxRank + 2));

    auto counting_sort = [&](auto get_key)
    {
        fill(cnt.begin(), cnt.end(), 0);

        for (int i : sa)
        {
            ++cnt[get_key(i)];
        }

        for (int i = 1; i <= maxRank + 1; ++i)
        {
            cnt[i] += cnt[i - 1];
        }

        for (int p = n - 1; p >= 0; --p)
        {
            int i = sa[p];
            temp[--cnt[get_key(i)]] = i;
        }

        sa.swap(temp);
    };

    for (int k = 1; k < n; k <<= 1)
    {
        auto get_rank = [&](int i) -> pair<int, int>
        {
            return {rank[i], i + k < n ? rank[i + k] : -1};
        };

        // Sort by the second key, then stably sort by the first key
        counting_sort([&](int i)
                      { return get_rank(i).second + 1; });
        counting_sort([&](int i)
                      { return get_rank(i).first + 1; });

        nextRank[sa[0]] = 0;

        // Assign ranks to the newly sorted suffixes
        for (int i = 1; i < n; ++i)
        {
            auto rx = get_rank(sa[i - 1]), ry = get_rank(sa[i]);
            nextRank[sa[i]] = nextRank[sa[i - 1]] + (rx != ry);
        }

        rank.swap(nextRank);
        maxRank = rank[sa.back()];

        // All n suffixes have distinct ranks, so sorting is complete
        if (maxRank == n - 1)
        {
            break;
        }
    }

    // Construct LCP using Kasai's algorithm
    vector<int> pos(n), lcp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        pos[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pos[i] == 0)
        {
            h = 0;
            continue;
        }

        int j = sa[pos[i] - 1];
        while (i + h < n && j + h < n && nums[i + h] == nums[j + h])
        {
            ++h;
        }

        lcp[pos[i]] = h;

        if (h > 0)
        {
            --h;
        }
    }

    int answer = n;
    for (int i = 0; i < n; ++i)
    {
        int next = (i + 1 < n ? lcp[i + 1] : 0);

        int need = std::max(lcp[i], next) + 1;
        if (sa[i] + need - 1 < n)
        {
            answer = std::min(answer, need);
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {3, 3, 3};
    cout << smallestUniqueSubarray(nums) << endl;
    cout << smallestUniqueSubarrayI(nums) << endl;

    return 0;
}