#include <bits/stdc++.h>
using namespace std;

#define ll long long

int peopleAwareOfSecret(int n, int delay, int forget)
{
    int mod = 1e9 + 7;
    vector<ll> dp(n + 1);
    dp[1] = 1;

    ll share = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i - delay >= 1)
        {
            share = (share + dp[i - delay]) % mod;
        }
        if (i - forget >= 1)
        {
            share = (share - dp[i - forget] + mod) % mod;
        }
        dp[i] = share;
    }

    ll ans = 0;
    for (int i = n - forget + 1; i <= n; i++)
        if (i >= 1)
            ans = (ans + dp[i]) % mod;

    return (int)ans;
}

// learn the queue solution

int peopleAwareOfSecretI(int n, int delay, int forget)
{
    int MOD = 1e9 + 7;
    queue<long long> q;
    q.push(1);
    long long share = 0, ans = 0;

    for (int day = 2; day <= n; day++)
    {
        if (day - delay >= 1)
        {
            share = (share + q.front()) % MOD;
        }
        if (day - forget >= 1)
        {
            share = (share - q.front() + MOD) % MOD;
            q.pop();
        }
        q.push(share);
    }

    while (!q.empty())
    {
        ans = (ans + q.front()) % MOD;
        q.pop();
    }

    return (int)ans;
}

int main()
{

    int n = 6, delay = 2, forget = 4;

    cout << peopleAwareOfSecretI(n, delay, forget) << endl;

    return 0;
}