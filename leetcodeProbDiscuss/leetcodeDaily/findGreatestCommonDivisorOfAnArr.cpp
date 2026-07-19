#include <bits/stdc++.h>
using namespace std;

int findGCD(vector<int> &nums)
{
    int mx = INT_MIN;
    int mn = INT_MAX;
    for (auto &i : nums)
    {
        mn = min(mn, i);
        mx = max(mx, i);
    }
    return __gcd(mx, mn);
}

int main()
{
    vector<int> nums = {2, 5, 6, 9, 10};
    cout << findGCD(nums) << endl;

    return 0;
}