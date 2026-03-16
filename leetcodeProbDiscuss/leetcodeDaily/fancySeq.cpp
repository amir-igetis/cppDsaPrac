#include <bits/stdc++.h>
using namespace std;

class Fancy
{
public:
    const long long MOD = 1000000007;

    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    Fancy() {}

    long long modPow(long long base, long long exp)
    {
        long long res = 1;
        while (exp)
        {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long x)
    {
        return modPow(x, MOD - 2);
    }

    void append(int val)
    {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc)
    {
        add = (add + inc) % MOD;
    }

    void multAll(int m)
    {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx)
    {
        if (idx >= arr.size())
            return -1;

        long long val = arr[idx];
        val = (val * mul % MOD + add) % MOD;

        return (int)val;
    }
};