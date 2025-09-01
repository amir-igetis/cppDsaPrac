#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int jumps = 0, currEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}

int main()
{

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}