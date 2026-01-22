#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums)
{
    for (int &x : nums)
    {
        int res = -1;
        int d = 1;
        while ((x & d) != 0)
        {
            res = x - d;
            d <<= 1;
        }
        x = res;
    }
    return nums;
}

int main()
{
    vector<int> nums = {2, 3, 5, 7};
    vector<int> ans = minBitwiseArray(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}