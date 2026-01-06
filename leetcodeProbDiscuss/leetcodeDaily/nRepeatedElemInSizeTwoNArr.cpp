#include <bits/stdc++.h>
using namespace std;

//    count tc & sc O(N)
int repeatedNTimes(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int x : nums)
    {
        mp[x]++; // equivalent of getOrDefault + put
    }

    for (auto &p : mp)
    {
        if (p.second > 1)
            return p.first;
    }

    return -1;
}

//    compare  tc & sc O(N) and O(1)
int repeatedNTimesI(vector<int> &nums)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < nums.size() - i; j++)
        {
            if (nums[j] == nums[j + i])
                return nums[j];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    cout << repeatedNTimesI(nums) << endl;

    return 0;
}