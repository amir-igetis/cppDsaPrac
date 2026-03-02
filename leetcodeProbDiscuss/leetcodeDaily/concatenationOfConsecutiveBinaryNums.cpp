#include <bits/stdc++.h>
using namespace std;

int concatenatedBinary(int n)
{
    const int MOD = 1e9 + 7;
    long long res = 0;
    int bitLen = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
            bitLen++;

        res = ((res << bitLen) + i) % MOD;
    }
    return (int)res;
}

int main()
{
    int n = 1;
    cout << concatenatedBinary(n) << endl;

    return 0;
}