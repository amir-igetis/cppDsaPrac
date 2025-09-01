#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() < 3)
        return nums.size();

    int in = 2;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] != nums[in - 2])
            nums[in++] = nums[i];
    }
    return in;
}

int main()
{

    vector<int> nums =  {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(nums) << endl;
    return 0;
}