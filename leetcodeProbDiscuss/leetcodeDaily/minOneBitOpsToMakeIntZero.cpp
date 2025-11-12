#include <bits/stdc++.h>
using namespace std;

int minimumOneBitOperations(int n)
{
    int res;
    for (res = 0; n > 0; n &= n - 1)
        res = -(res + (n ^ (n - 1)));
    return abs(res);
}

int minimumOneBitOperationsI(int n)
{
    if (n == 0)
        return 0;
    int msb = 31 - __builtin_clz(n);

    return (1 << (msb + 1)) - 1 - minimumOneBitOperationsI(n ^ (1 << msb));
}

int main()
{
    int n = 3;

    cout << minimumOneBitOperationsI(n) << endl;

    return 0;
}