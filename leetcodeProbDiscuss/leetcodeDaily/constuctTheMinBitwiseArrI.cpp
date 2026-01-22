#include <bits/stdc++.h>
using namespace std;

//    brute force tc O(mn) sc O(1)
vector<int> minBitwiseArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = nums[i];
        for (int j = 1; j < nums[i]; j++)
        {
            if ((j | (j + 1)) == nums[i])
            {
                nums[i] = j;
                break;
            }
        }
        if (nums[i] == tmp)
        {
            nums[i] = -1;
        }
    }
    return nums;
}

//    bitwise operator tc O(NlogM) sc O(1)
vector<int> minBitwiseArrayI(vector<int> &nums)
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
    vector<int> res = minBitwiseArrayI(nums);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}