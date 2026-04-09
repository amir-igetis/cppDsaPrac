#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

// Fast exponentiation (modular inverse)
ll modPow(ll x, ll y)
{
    ll res = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

// Square Root Decomposition + Difference Array
int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int T = sqrt(n);

    vector<vector<vector<int>>> groups(T);

    for (auto &q : queries)
    {
        int l = q[0], r = q[1], k = q[2], v = q[3];

        if (k < T)
        {
            groups[k].push_back({l, r, v});
        }
        else
        {
            for (int i = l; i <= r; i += k)
            {
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }
    }

    vector<ll> dif(n + T);

    for (int k = 1; k < T; k++)
    {
        if (groups[k].empty())
            continue;

        fill(dif.begin(), dif.end(), 1);

        for (auto &q : groups[k])
        {
            int l = q[0], r = q[1], v = q[2];

            dif[l] = dif[l] * v % mod;

            int R = ((r - l) / k + 1) * k + l;

            // FIXED HERE
            dif[R] = dif[R] * modPow(v, mod - 2) % mod;
        }

        // propagate difference array
        for (int i = k; i < n; i++)
        {
            dif[i] = dif[i] * dif[i - k] % mod;
        }

        // apply to nums
        for (int i = 0; i < n; i++)
        {
            nums[i] = (1LL * nums[i] * dif[i]) % mod;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= nums[i];
    }

    return res;
}

int main()
{
    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {
        {1, 4, 2, 3},
        {0, 2, 1, 2}};

    cout << xorAfterQueries(nums, queries) << endl;

    return 0;
}