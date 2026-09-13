#include <bits/stdc++.h>
using namespace std;

long long countCommas(long long n)
{
    long long p = 1000, res = 0;
    while (p <= n)
    {
        res += n - p + 1;
        p *= 1000;
    }
    return res;
}

int main()
{
    int n = 1002;
    cout << countCommas(n) << endl;

    return 0;
}