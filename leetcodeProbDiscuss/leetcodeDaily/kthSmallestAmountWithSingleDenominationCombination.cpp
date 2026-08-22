#include <bits/stdc++.h>
using namespace std;

// Binary Answer + Inclusion-Exclusion Principle

/// Let n be the length of coins.
///
/// Time complexity: O(2^n ×(nlog(max{coins})+log(k×min{coins})))
/// During the preprocessing stage, calculating the least common multiple of each subset takes O(nlog(maxcoins)) time per subset, and there are O(2^n) subsets. During the binary search, we perform O(log(k×mincoins)) iterations, and each iteration takes O(2^n) time to calculate count(x).
///
/// Space complexity: O(2^n).

using ll = long long;
long long findKthSmallest(vector<int> &coins, int k)
{
    int n = coins.size();
    int m = (1 << n);
    sort(coins.begin(), coins.end());
    vector<int> bit_count(m);
    vector<ll> lcm(m);
    ll l = k, r = 1ll * coins[0] * k + 1;

    for (int mask = 1; mask < m; mask++)
    {
        ll cur_lcm = 1;
        for (int i = 0; i < n; i++)
        {
            if (mask >> i & 1)
            {
                ll tmp = cur_lcm / gcd(cur_lcm, coins[i]);
                if (tmp <= r / coins[i])
                {
                    cur_lcm = tmp * coins[i];
                }
                else
                {
                    cur_lcm = r + 1;
                    break;
                }
                bit_count[mask]++;
            }
        }
        lcm[mask] = cur_lcm;
    }

    auto get = [&](ll x) -> ll
    {
        ll count = 0;
        for (int mask = 1; mask < m; mask++)
        {
            if (lcm[mask] > x)
            {
                continue;
            }
            if (bit_count[mask] & 1)
            {
                count += x / lcm[mask];
            }
            else
            {
                count -= x / lcm[mask];
            }
        }
        return count;
    };

    while (l < r)
    {
        ll x = (l + r) >> 1;
        if (get(x) >= k)
        {
            r = x;
        }
        else
        {
            l = x + 1;
        }
    }
    return l;
}

// Optimized Based on Approach 1

/// Let n be the length of coins.
///
/// Time complexity: O(n^2+2^n×(log(maxcoins)+log(k×mincoins))).
///
/// Removing redundant denominations takes O(n^2) time. During the preprocessing stage, the least common multiple of each subset can be computed in O(log(maxcoins)) time, and there are O(2^n) subsets. During the binary search, we perform O(log(k×mincoins)) iterations, and each iteration takes O(2^n) time to calculate count(x).
///
/// Space complexity: O(2^n).

using ll = long long;
long long findKthSmallestI(vector<int> &coins, int k)
{
    sort(coins.begin(), coins.end());
    vector<int> new_coins;
    for (int x : coins)
    {
        bool flag = true;
        for (int y : new_coins)
        {
            if (x % y == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            new_coins.push_back(x);
        }
    }
    coins = new_coins;

    int n = coins.size();
    int m = (1 << n);
    vector<int> bit_count(m);
    vector<ll> lcm(m, 1);
    ll l = k, r = 1ll * coins[0] * k + 1;

    for (int mask = 1; mask < m; mask++)
    {
        int pre_mask = mask & (mask - 1);
        int i = __builtin_ctz(mask);

        ll tmp = lcm[pre_mask] / gcd(lcm[pre_mask], coins[i]);
        if (tmp <= r / coins[i])
        {
            lcm[mask] = tmp * coins[i];
        }
        else
        {
            lcm[mask] = r + 1;
        }
    }

    auto get = [&](ll x) -> ll
    {
        ll count = 0;
        for (int mask = 1; mask < m; mask++)
        {
            if (lcm[mask] > x)
            {
                continue;
            }
            if (__builtin_popcount(mask) & 1)
            {
                count += x / lcm[mask];
            }
            else
            {
                count -= x / lcm[mask];
            }
        }
        return count;
    };

    while (l < r)
    {
        ll x = (l + r) >> 1;
        if (get(x) >= k)
        {
            r = x;
        }
        else
        {
            l = x + 1;
        }
    }
    return l;
}

int main()
{
    vector<int> coins = {3, 6, 9};
    int k = 3;
    cout << findKthSmallest(coins, k) << endl;

    return 0;
}
