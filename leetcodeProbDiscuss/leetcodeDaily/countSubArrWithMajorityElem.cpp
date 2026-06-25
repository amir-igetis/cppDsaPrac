#include <bits/stdc++.h>
using namespace std;

int countMajoritySubarrays(vector<int> &nums, int target)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == target)
                count += 1;
            else
                count -= 1;
            if (count > 0)
                ans++;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << countMajoritySubarrays(nums, target) << endl;

    return 0;
}