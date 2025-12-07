#include <bits/stdc++.h>
using namespace std;

int countOdds(int low, int high)
{
    int ans = ((high + 1) / 2) - (low / 2);
    return ans;
}

int main()
{
    int low = 3, high = 10;
    cout << countOdds(low, high) << endl;

    return 0;
}