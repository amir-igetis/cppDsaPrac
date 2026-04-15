#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int> &nums, int target, int start)
{
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            res = min(res, abs(i - start));
    }
    return res;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5, start = 3;
    cout << getMinDistance(nums, target, start) << endl;

    return 0;
}