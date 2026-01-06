#include <bits/stdc++.h>
using namespace std;

int numOfWays(int n)
{
    const int MOD = 1e9 + 7;
    long long a = 6, b = 6;
    for (int i = 2; i <= n; i++)
    {
        long long newA = (2 * a + 2 * b) % MOD;
        long long newB = (2 * a + 3 * b) % MOD;
        a = newA;
        b = newB;
    }
    return (a + b) % MOD;
}

int main()
{
    int n = 5000;
    cout << numOfWays(5000) << endl;

    return 0;
}