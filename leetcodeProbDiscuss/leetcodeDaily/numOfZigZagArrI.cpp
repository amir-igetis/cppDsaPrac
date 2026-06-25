#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int zigZagArrays(int n, int l, int r)
{
    vector<int> dp0(r + 1);
    vector<int> dp1(r + 1);
    vector<int> sum0(r + 2);
    vector<int> sum1(r + 2);
    for (int i = l; i <= r; i++)
    {
        dp0[i] = 1;
        dp1[i] = 1;
        sum0[i] = i - l + 1;
        sum1[i] = i - l + 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = l; j <= r; j++)
        {
            dp0[j] = (sum1[r] - sum1[j] + MOD) % MOD;
            dp1[j] = sum0[j - 1];
        }
        sum0[l] = dp0[l];
        sum1[l] = dp1[l];
        for (int j = l + 1; j <= r; j++)
        {
            sum0[j] = (sum0[j - 1] + dp0[j]) % MOD;
            sum1[j] = (sum1[j - 1] + dp1[j]) % MOD;
        }
    }
    return (sum0[r] + sum1[r]) % MOD;
}

int main()
{

    int n = 3, l = 1, r = 3;
    cout << zigZagArrays(n, l, r) << endl;

    return 0;
}