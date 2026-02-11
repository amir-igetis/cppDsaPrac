#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int mnaxIdx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > mnaxIdx)
            return false;
        mnaxIdx = max(mnaxIdx, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> nums = {4, 2, 7, 1, 2};
    cout << (canJump(nums) ? "True" : "False") << endl;
    return 0;
}