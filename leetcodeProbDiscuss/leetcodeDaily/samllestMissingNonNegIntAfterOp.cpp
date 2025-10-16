#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    unordered_map<int, int> count;
    for (int &num : nums)
    {
        int mod = ((num % value) + value) % value;
        count[mod]++;
    }

    int mex = 0;
    while (true)
    {
        int mod = mex % value;
        if (count[mod] == 0)
            break;
        count[mod]--;
        mex++;
    }
    return mex;
}

// soln from leetcode
int findSmallestIntegerI(vector<int> &nums, int value)
{
    int n = nums.size(), res = 0;
    vector<int> rem(value);
    for (int x : nums)
    {
        int r = ((x % value) + value) % value;
        rem[r]++;
    }
    while (rem[res % value]-- > 0)
        res++;

    return res;
}

int main()
{

    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 5;

    cout << findSmallestIntegerI(nums, value) << endl;

    return 0;
}