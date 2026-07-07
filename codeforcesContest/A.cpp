#include <bits/stdc++.h>
using namespace std;

void func()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long cost = 1;
    while (n > 0 && cost <= n)
    {
        long long take = min(k, n / cost);
        ans += take;
        n -= take * cost;
        cost *= 2;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        func();

        // vector<int> res = func(n, s);
        // // cout << func(n, s) << endl;

        // for (auto &i : res)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    return 0;
}
