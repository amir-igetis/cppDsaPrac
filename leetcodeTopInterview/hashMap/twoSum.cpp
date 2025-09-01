#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++)
    {
        int comp = target - nums[i];

        if (mp.find(comp) != mp.end())
        {
            return {mp[comp], i}; // return indices
        }

        mp[nums[i]] = i; // store value with index
    }

    return {-1, -1};
}

int main()
{

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = twoSum(nums, target);
    for (const &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}