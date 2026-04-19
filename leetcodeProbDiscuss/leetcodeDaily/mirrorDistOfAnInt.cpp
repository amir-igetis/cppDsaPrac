#include <bits/stdc++.h>
using namespace std;

int rev(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int rem = n % 10;
        ans = (ans * 10) + rem;
        n /= 10;
    }
    return ans;
}
int mirrorDistance(int n)
{
    return abs(n - rev(n));
}

int main()
{
    int n = 25;
    cout << mirrorDistance(n) << endl;

    return 0;
}