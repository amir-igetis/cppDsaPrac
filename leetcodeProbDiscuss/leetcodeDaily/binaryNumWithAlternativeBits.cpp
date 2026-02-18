#include <bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n)
{
    long long m = n ^ (n >> 1);
    return (m & m + 1) == 0;
}

int main()
{

    int n = 5;
    cout << (hasAlternatingBits(n) ? "True" : "False") << endl;

    return 0;
}