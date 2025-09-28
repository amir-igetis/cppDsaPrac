#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    for (int k = n - 1; k >= 2; k--)
    {
        int start = 0, end = k - 1;
        while (start < end)
        {
            if (nums[start] + nums[end] > nums[k])
            {
                count += (end - start);
                end--;
            }
            else
                start++;
        }
    }
    return count;
}

int main()
{

    vector<int> nums = {2, 2, 3, 4};
    cout << triangleNumber(nums) << endl;

    return 0;
}