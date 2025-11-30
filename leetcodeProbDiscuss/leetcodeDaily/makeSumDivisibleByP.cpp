#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int> &nums, int p)
{
    long long total = 0;
    for (int x : nums)
        total += x;

    int rem = total % p;
    if (rem == 0)
        return 0;

    unordered_map<int, int> lastPos;
    lastPos[0] = -1;

    long long prefix = 0;
    int ans = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        prefix = (prefix + nums[i]) % p;
        int need = (prefix - rem + p) % p;

        if (lastPos.count(need))
            ans = min(ans, i - lastPos[need]);

        lastPos[prefix] = i;
    }

    return ans == nums.size() ? -1 : ans;
}

int main()
{

    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << minSubarray(nums, p) << endl;

    return 0;
}