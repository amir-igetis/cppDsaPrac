#include <bits/stdc++.h>
using namespace std;

// find the pattern tc O(logn) sc O(1)
int uniqueXorTriplets(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int ans = 1;
    while (ans <= n)
        ans <<= 1;

    return ans;
}

int main()
{
    vector<int> nums = {1, 2};
    cout << uniqueXorTriplets(nums) << endl;

    return 0;
}