
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{

    if (nums.size() == 0)
        return 0;

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[count] != nums[i])
        {
            count++;
            nums[count] = nums[i];
        }
    }
    return count + 1;
}

int main()
{

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;

    return 0;
}