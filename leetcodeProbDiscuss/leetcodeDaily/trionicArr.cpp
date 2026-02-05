#include <bits/stdc++.h>
using namespace std;

//    Evaluating the Validity of the Boundaries tc O(n) & sc O(1)
bool isTrionic(vector<int> &nums)
{
    int n = nums.size();
    int i = 1;
    while (i < n && nums[i - 1] < nums[i])
        i++;
    int p = i - 1;
    while (i < n && nums[i - 1] > nums[i])
        i++;
    int q = i - 1;
    while (i < n && nums[i - 1] < nums[i])
        i++;
    int flag = i - 1;
    return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
}

//    Counting the Number of Turning Points tc O(n) & sc O(1)
bool isTrionicI(vector<int> &nums)
{
    int n = nums.size();
    if (nums[0] >= nums[1])
    {
        return false;
    }
    int count = 1;
    for (int i = 2; i < n; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            return false;
        }
        if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0)
        {
            count++;
        }
    }
    return count == 3;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 2, 6};
    cout << (isTrionicI(nums) ? "True" : "False") << endl;

    return 0;
}