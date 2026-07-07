#include <bits/stdc++.h>
using namespace std;

//    left to right tc & sc O(logn)
long long sumAndMultiplyI(int n)
{
    long long x = 0;
    long long sum = 0;
    string s = to_string(n);
    for (char c : s)
    {
        int d = c - '0';
        sum += d;
        if (d > 0)
        {
            x = x * 10 + d;
        }
    }
    return x * sum;
}

//    right to left tc O(logn) & sc O(1)
long long sumAndMultiply(int n)
{
    long long x = 0;
    long long sum = 0;
    long long pow10 = 1;
    while (n > 0)
    {
        int d = n % 10;
        sum += d;
        if (d > 0)
        {
            x += d * pow10;
            pow10 *= 10;
        }
        n /= 10;
    }
    return x * sum;
}

int main()
{

    int n = 10203004;
    cout << sumAndMultiply(n) << endl;
    cout << sumAndMultiplyI(n) << endl;

    return 0;
}