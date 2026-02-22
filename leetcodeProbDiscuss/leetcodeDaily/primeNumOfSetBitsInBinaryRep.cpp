#include <bits/stdc++.h>
using namespace std;

int countPrimeSetBits(int left, int right)
{
    set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        int bits = 0;
        for (int n = i; n > 0; n >>= 1)
            bits += n & 1;
        count += primes.count(bits);
    }
    return count;
}

int main()
{
    int left = 6, right = 10;
    cout << countPrimeSetBits(left, right) << endl;

    return 0;
}