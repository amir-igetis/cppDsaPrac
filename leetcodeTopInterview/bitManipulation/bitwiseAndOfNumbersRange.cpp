#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{

    int shift = 0;
    while (left < right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
}

int main()
{
    int left = 5, right = 7;
    cout << rangeBitwiseAnd(left, right) << endl;

    return 0;
}