#include <bits/stdc++.h>
using namespace std;

int reverseBits(int n)
{
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int bit = n & 1;
        res = (res << 1) | bit;
        n >>= 1;
    }
    return res;
}

int main()
{
    int n = 43261596;
    cout << reverseBits(n) << endl;

    return 0;
}