#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (int i : nums)
    {
        res ^= i;
    }

    return res;
}

int main()
{

    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;

    return 0;
}