#include <bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k)
{
    if (k % 2 == 0 || k % 5 == 0)
        return -1;

    int num = 0;
    for (int len = 1; len <= k; len++)
    {
        num = (num * 10 + 1) % k;
        if (num == 0)
            return len;
    }

    return -1;
}

int main()
{

    int k = 1;
    cout << smallestRepunitDivByK(k) << endl;

    return 0;
}