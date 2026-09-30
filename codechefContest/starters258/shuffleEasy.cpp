#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAX = 200005;

long long fact[MAX];
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int q;
        cin >> q;
    }
    long long ans = power(K, N - K + 1);
    ans = (ans * fact[K - 1]) % MOD;

    cout << ans << "\n";
}

int main()
{

    precompute();

    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}