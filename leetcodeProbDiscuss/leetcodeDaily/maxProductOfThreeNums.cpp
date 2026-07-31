#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    int maxi = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
    int mini = INT_MAX, secondMin = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxi)
        {
            thirdMax = secondMax;
            secondMax = maxi;
            maxi = nums[i];
        }
        else if (nums[i] > secondMax)
        {
            thirdMax = secondMax;
            secondMax = nums[i];
        }
        else if (nums[i] > thirdMax)
        {
            thirdMax = nums[i];
        }

        if (nums[i] < mini)
        {
            secondMin = mini;
            mini = nums[i];
        }
        else if (nums[i] < secondMin)
        {
            secondMin = nums[i];
        }
    }
    return max(maxi * secondMax * thirdMax,
               mini * secondMin * maxi);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << maximumProduct(nums) << endl;

    return 0;
}