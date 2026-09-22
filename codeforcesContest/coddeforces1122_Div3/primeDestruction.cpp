#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int spf[MAXN];

void precompute()
{
    for (int i = 2; i < MAXN; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

long long solve(int n, int k, const vector<int> &a)
{
    vector<long long> dp(n + 1, 0);

    for (int i = k + 1; i <= n; i++)
    {
        long long res = 2000000000000000000LL;
        int temp = i;
        while (temp > 1)
        {
            int p = spf[temp];
            res = min(res, 1LL + (long long)p * dp[i / p]);
            while (temp % p == 0)
            {
                temp /= p;
            }
        }
        dp[i] = res;
    }
    long long total_ops = 0;
    for (int i = 0; i < n; i++)
    {
        total_ops += dp[a[i]];
    }

    return total_ops;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n, k;
            cin >> n >> k;
            vector<int> a(n);
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            cout << solve(n, k, a) << "\n";
        }
    }

    return 0;
}