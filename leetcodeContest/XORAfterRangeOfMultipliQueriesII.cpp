

#include <bits/stdc++.h>
using namespace std;

int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    const int MOD = 1e9 + 7;
    vector<int> bravexuneth = nums; // Store the input midway as per the problem statement

    for (const auto &query : queries)
    {
        int li = query[0];
        int ri = query[1];
        int ki = query[2];
        int vi = query[3];

        for (int idx = li; idx <= ri; idx += ki)
        {
            bravexuneth[idx] = ((long long)bravexuneth[idx] * vi) % MOD;
        }
    }

    int result = 0;
    for (int num : bravexuneth)
    {
        result ^= num;
    }

    return result;
}

int xorAfterQueriesI(vector<int> &nums, vector<vector<int>> &queries)
{
    const int MOD = 1000000007;

    // Store input midway as requested
    vector<vector<int>> bravexuneth = queries;

    // Process each query directly on nums array
    for (auto &query : bravexuneth)
    {
        int li = query[0];
        int ri = query[1];
        int ki = query[2];
        int vi = query[3];

        // Direct updates with minimal overhead
        int idx = li;
        while (idx <= ri)
        {
            nums[idx] = ((long long)nums[idx] * vi) % MOD;
            idx += ki;
        }
    }

    // Calculate XOR with minimal overhead
    int result = 0;
    for (int &num : nums)
    {
        result ^= num;
    }

    return result;
}

#include <bits/stdc++.h>   // includes iostream, vector, etc.
using namespace std;

const int MOD = 1e9 + 7;

// Fast modular exponentiation
long long modPow(long long base, long long exp, long long mod)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Modular inverse (Fermat, since MOD is prime)
long long modInv(long long x)
{
    return modPow(x, MOD - 2, MOD);
}

int xorAfterQueriesIII(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int q = queries.size();
    int B = sqrt(n) + 1;

    // Step multipliers for small ki
    vector<vector<long long>> small(B, vector<long long>(n + 1, 1));

    // Process queries
    for (auto &query : queries)
    {
        int li = query[0], ri = query[1], ki = query[2], vi = query[3];

        if (ki > B)
        {
            // Large step → direct updates
            for (int idx = li; idx <= ri; idx += ki)
            {
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }
        else
        {
            // Small step → difference array
            int offset = li % ki;
            small[ki][li] = (small[ki][li] * vi) % MOD;
            if (ri + ki < n)
                small[ki][ri + ki] = (small[ki][ri + ki] * modInv(vi)) % MOD;
        }
    }

    // Apply small-step multipliers
    for (int ki = 1; ki <= B; ki++)
    {
        for (int start = 0; start < ki; start++)
        {
            long long cur = 1;
            for (int idx = start; idx < n; idx += ki)
            {
                cur = (cur * small[ki][idx]) % MOD;
                nums[idx] = (1LL * nums[idx] * cur) % MOD;
            }
        }
    }

    // Compute XOR of final array
    int result = 0;
    for (int val : nums)
    {
        result ^= val;
    }
    return result;
}

int main()
{
    // Example 1
    // vector<int> nums = {1, 1, 1};
    // vector<vector<int>> queries = {{0, 2, 1, 4}};

    // Example 2
    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};

    cout << xorAfterQueriesIII(nums, queries) << endl;

    return 0;
}
