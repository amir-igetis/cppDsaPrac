#include <bits/stdc++.h>
using namespace std;

// sorting tc O(nlogn) & sc O(logn)

bool isGood(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return false;
    }
    return nums[n] == n;
}

// frequency counting tc & sc O(n)
bool isGoodI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> count(n);
    for (int i : nums)
    {
        if (i >= n)
            return false;
        if (i < n - 1 && count[i] > 0)
            return false;
        if (i == n - 1 && count[i] > 1)
            return false;

        count[i]++;
    }
    return true;
}

int main()
{
    vector<int> nums = {2, 1, 3};
    cout << (isGoodI(nums) ? "True" : "False") << endl;

    return 0;
}