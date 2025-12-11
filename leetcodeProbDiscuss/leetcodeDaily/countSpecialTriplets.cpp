#include <bits/stdc++.h>
using namespace std;

// enumeration + counting
int specialTriplets(vector<int> &nums)
{
    const int MOD = 1e9 + 7;
    unordered_map<int, int> numCount;
    unordered_map<int, int> numPartialCount;

    numCount.reserve(nums.size() * 2);
    numPartialCount.reserve(nums.size() * 2);

    for (auto &v : nums)
        numCount[v]++;

    int ans = 0;
    for (auto &v : nums)
    {
        int target = v * 2;
        int lCount = numPartialCount[target];
        numPartialCount[v]++;
        int rCount = numCount[target] - numPartialCount[target];
        ans = (ans + (lCount * 1LL * rCount % MOD)) % MOD;
    }

    return ans;
}

// enumeration + binary search

int specialTripletsI(vector<int> &nums)
{
    const int MOD = 1e9 + 7;
    unordered_map<int, vector<int>> pos;
    pos.reserve(nums.size() * 2);

    for (int i = 0; i < nums.size(); i++)
    {
        pos[nums[i]].push_back(i);
    }

    int ans = 0;

    for (int i = 1; i < nums.size() - 1; i++)
    {
        int target = nums[i] * 2LL;
        if (pos.count(target) == 0)
        {
            continue;
        }

        const auto &arr = pos[target];
        if (arr.size() <= 1 || arr[0] >= i)
        {
            continue;
        }

        auto split = upper_bound(arr.begin(), arr.end(), i);
        int l = split - arr.begin();
        int r = arr.size() - l;

        if (nums[i] == 0)
        {
            l--;
        }
        ans = (ans + l * 1LL * r % MOD) % MOD;
    }

    return ans;
}

int main()
{

    vector<int> nums = {6, 3, 6};
    cout << specialTriplets(nums) << endl;

    return 0;
}