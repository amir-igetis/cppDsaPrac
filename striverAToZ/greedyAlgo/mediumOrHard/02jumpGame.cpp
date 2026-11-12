#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.size() < 2)
        return true;
    int maxIdx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxIdx)
            return false;
        maxIdx = max(maxIdx, i + nums[i]);
    }
    return true;
}

/// You are given an integer array nums. You are initially positioned at the array's first 
/// index, and each element in the array represents your maximum jump length from that position.
/// 
/// Return true if you can reach the last index of the array, or false if you cannot.
/// 
int main()
{
    vector<int> nums = {4, 2, 7, 1, 2};
    vector<int> numsI = {3, 2, 1, 0, 4};
    cout << (canJump(numsI) ? "True" : "False") << endl;
    return 0;
}