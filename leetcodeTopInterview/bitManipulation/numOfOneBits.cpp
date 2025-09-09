#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main()
{
    int n = 11;
    cout << hammingWeight(n) << endl;

    return 0;
}