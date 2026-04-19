#include <bits/stdc++.h>
using namespace std;

int reverseNum(int x)
{
    int y = 0;
    while (x > 0)
    {
        y = y * 10 + (x % 10);
        x /= 10;
    }
    return y;
}

int minMirrorPairDistance(vector<int> &nums)
{
    unordered_map<int, int> prev;
    int n = nums.size();
    int ans = n + 1;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        if (prev.count(x) != 0)
            ans = min(ans, i - prev[x]);

        prev[reverseNum(x)] = i;
    }
    return ans == n + 1 ? -1 : ans;
}

int main()
{

    vector<int> nums = {12, 21, 45, 33, 54};
    cout << minMirrorPairDistance(nums) << endl;

    return 0;
}