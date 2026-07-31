#include <bits/stdc++.h>
using namespace std;

int maxProduct(int n)
{
    int max = 0, secondMax = 0;
    while (n > 0)
    {
        int digit = n % 10;
        if (digit > max)
        {
            secondMax = max;
            max = digit;
        }
        else if (digit > secondMax)
        {
            secondMax = digit;
        }
        n /= 10;
    }
    return max * secondMax;
}

int main()
{
    int n = 124;
    cout << maxProduct(n);

    return 0;
}