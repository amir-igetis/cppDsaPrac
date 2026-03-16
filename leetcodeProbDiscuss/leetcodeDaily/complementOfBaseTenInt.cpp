
#include <bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n)
{
    int x = 1;
    while (n > x)
        x = x * 2 + 1;
    return x - n;
}

int main()
{

    int n = 5;
    cout << bitwiseComplement(n) << endl;
    return 0;
}