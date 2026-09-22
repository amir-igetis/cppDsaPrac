#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Check if already sorted
    bool sorted = true;
    for (int i = 0; i + 1 < n; i++)
    {
        if (s[i] > s[i + 1])
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
    {
        cout << 0 << "\n";
        return;
    }

    // Prefix count of 1s
    vector<int> pref1(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref1[i + 1] = pref1[i] + (s[i] == '1' ? 1 : 0);
    }

    auto count1 = [&](int l, int r)
    {
        if (l > r)
            return 0;
        return pref1[r + 1] - pref1[l];
    };

    auto count0 = [&](int l, int r)
    {
        if (l > r)
            return 0;
        return (r - l + 1) - count1(l, r);
    };

    // Case 1: s[0] == '1'
    // Since s[0] is 1 and cannot be turned into 0, the only option is to make all characters '1'
    if (s[0] == '1')
    {
        cout << count0(0, n - 1) << "\n";
        return;
    }

    // Case 2: s[0] == '0'
    // Option A: Turn everything into '0'
    int ans = count1(0, n - 1);

    // Option B: Prefix of length k becomes '0', suffix of length n - k becomes '1'
    // This is valid for 1 <= k < n IF the suffix s[k ... n-1] contains at least one '1'
    for (int k = 1; k < n; k++)
    {
        if (count1(k, n - 1) > 0)
        {
            int cost = count1(0, k - 1) + count0(k, n - 1);
            ans = min(ans, cost);
        }
    }

    cout << ans << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}