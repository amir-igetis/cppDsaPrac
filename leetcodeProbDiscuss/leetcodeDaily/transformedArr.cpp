
#include <bits/stdc++.h>
using namespace std;

vector<int> constructTransformedArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            res[i] = nums[i];
            continue;
        }
        int newIdx = (i + nums[i]) % n;
        if (newIdx < 0)
            newIdx += n;

        res[i] = nums[newIdx];
    }
    return res;
}

int main()
{

    //        vector<int> nums = {3, -2, 1, 1};
    vector<int> nums = {-1, 4, -1};
    vector<int> res = constructTransformedArray(nums);
    for (auto &i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}